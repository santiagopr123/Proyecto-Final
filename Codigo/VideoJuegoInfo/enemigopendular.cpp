#include "enemigopendular.h"

EnemigoPendular::EnemigoPendular(QGraphicsScene *Scene_Aux, PersonajePrincipal *Personaje_1, int *ApuntadorPuntaje)
{
    Contador = 0;
    Scene = Scene_Aux;
    Flag = true;
    Apuntador_Flag = &Flag;
    FlagMulti = false;
    Character_1 = Personaje_1;
    Puntaje = ApuntadorPuntaje;

    Angulo_Inicial = asin(Posicion_x/Longitud);
    Velocidad_Angular_Inicial = 0;
    Aceleracion_Angular = -Aceleracion_Gravedad*sin(Angulo_Inicial);


    setPos(Posicion_x+500,Posicion_y-50);

    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

EnemigoPendular::EnemigoPendular(QGraphicsScene *Scene_Aux,PersonajePrincipal *Personaje_1,PersonajePrincipal *Personaje_2,int *ApuntadorPuntaje)
{
    Contador = 0;
    Scene = Scene_Aux;
    Flag = true;
    Apuntador_Flag = &Flag;
    FlagMulti = true;
    Character_1 = Personaje_1;
    Character_2 = Personaje_2;
    Puntaje = ApuntadorPuntaje;

    Angulo_Inicial = asin(Posicion_x/Longitud);
    Velocidad_Angular_Inicial = 0;
    Aceleracion_Angular = -Aceleracion_Gravedad*sin(Angulo_Inicial);

    setPos(Posicion_x+500,Posicion_y-50);

    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

EnemigoPendular::~EnemigoPendular()
{
    delete timer;
}

QRectF EnemigoPendular::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void EnemigoPendular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(-radio,-radio, 2*radio, 2*radio);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoPendular::move()
{
    actualizar_posicion();
}

void EnemigoPendular::calcular_variables()
{
    Velocidad_Angular = Velocidad_Angular_Inicial+(Aceleracion_Angular*tiempo);
    Angulo = Angulo_Inicial+(Velocidad_Angular*tiempo)+(Aceleracion_Angular*tiempo*tiempo)/2;

    Aceleracion_Angular = -Aceleracion_Gravedad*sin(Angulo);
}

void EnemigoPendular::actualizar_posicion()
{
    srand(time(NULL));

    calcular_variables();

    Posicion_x = Longitud*sin(Angulo_Inicial);
    Posicion_y = Longitud*cos(Angulo_Inicial);
    setPos(Posicion_x+500,Posicion_y-50);

    if(this->collidesWithItem(Character_1))
    {
        Character_1->RestarVida(1);
        Character_1->setPosicion_y(this->pos().y()+20);
    }

    if(FlagMulti == true)
    {
        if(this->collidesWithItem(Character_2))
        {
            Character_2->RestarVida(1);
            Character_2->setPosicion_y(this->pos().y()+20);
        }
    }

    Velocidad_Angular_Inicial = Velocidad_Angular;
    Angulo_Inicial = Angulo;

    if(Flag == true && FlagMulti == true)
    {
        int NumAleatorio = rand()%(2);

        if(NumAleatorio == 0)
        {
            Hijo = new EnemigoInteligente(10,10,Scene,this->pos().x(),this->pos().y(),Apuntador_Flag,Character_1,Puntaje,1);
            Scene->addItem(Hijo);
            Flag = false;
        }
        else if(NumAleatorio == 1)
        {
            Hijo = new EnemigoInteligente(10,10,Scene,this->pos().x(),this->pos().y(),Apuntador_Flag,Character_2,Puntaje,1);
            Scene->addItem(Hijo);
            Flag = false;
        }

    }
    else if(Flag == true)
    {
        Hijo = new EnemigoInteligente(10,10,Scene,this->pos().x(),this->pos().y(),Apuntador_Flag,Character_1,Puntaje,1);
        Scene->addItem(Hijo);
        Flag = false;
    }
}
