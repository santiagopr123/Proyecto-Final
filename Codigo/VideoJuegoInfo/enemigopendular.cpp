#include "enemigopendular.h"

EnemigoPendular::EnemigoPendular(QGraphicsScene *Scene_Aux, PersonajePrincipal *Personaje, int *ApuntadorPuntaje)
{
    Contador = 0;
    Scene = Scene_Aux;
    Flag = true;
    Apuntador_Flag = &Flag;
    Character = Personaje;
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

void EnemigoPendular::calcular_variables()
{
    Velocidad_Angular = Velocidad_Angular_Inicial+(Aceleracion_Angular*tiempo);
    Angulo = Angulo_Inicial+(Velocidad_Angular*tiempo)+(Aceleracion_Angular*tiempo*tiempo)/2;

    Aceleracion_Angular = -Aceleracion_Gravedad*sin(Angulo);
}

void EnemigoPendular::actualizar_posicion()
{
    calcular_variables();

    Posicion_x = Longitud*sin(Angulo_Inicial);
    Posicion_y = Longitud*cos(Angulo_Inicial);
    setPos(Posicion_x+500,Posicion_y-50);

    if(this->collidesWithItem(Character))
    {
        Character->RestarVida(1);
        Character->setPosicion_y(this->pos().y()+20);
    }

    Velocidad_Angular_Inicial = Velocidad_Angular;
    Angulo_Inicial = Angulo;

    if(Flag == true)
    {
        Hijo = new EnemigoInteligente(10,10,Scene,this->pos().x(),this->pos().y(),Apuntador_Flag,Character,Puntaje);
        Scene->addItem(Hijo);
        Flag = false;
    }
}

QRectF EnemigoPendular::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void EnemigoPendular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(-radio,-radio, 2*radio, 2*radio);
}

void EnemigoPendular::move()
{
    actualizar_posicion();
}
