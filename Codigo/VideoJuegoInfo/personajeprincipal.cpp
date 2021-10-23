#include "personajeprincipal.h"

bool PersonajePrincipal::getLevel_2() const
{
    return level_2;
}

PersonajePrincipal::PersonajePrincipal(int An, int Al, double Pos_x, double Pos_y, double Vel_x, double Vel_y, double Ace_x, double Ace_y, QGraphicsScene *Scene_Aux, Vista *Aux_Parametros)
{
    ancho = An;
    alto = Al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Velocidad_x = Vel_x;
    Velocidad_y = Vel_y;
    Aceleracion_x = Ace_x;
    Aceleracion_y = Ace_y;
    Vida = 1000;
    Vida_Aux = Vida;
    Scene = Scene_Aux;
    Disparos = 2;
    Parametros_Pantalla = Aux_Parametros;
    delta = 0.15;
    Contador = 0;
    level_2 = false;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(Calcular()));
    Timer->start(30);
}

PersonajePrincipal::~PersonajePrincipal()
{
    delete Timer;
}

QRectF PersonajePrincipal::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void PersonajePrincipal::MoverDerecha()
{
    Posicion_x+=3;
    setPos(Posicion_x,Posicion_y);
}

void PersonajePrincipal::MoverIzquierda()
{
    Posicion_x-=3;
    setPos(Posicion_x,Posicion_y);
}

void PersonajePrincipal::MoverArriba()
{
    Velocidad_x = 0;
    Velocidad_y = -50;
    Aceleracion_y = 10;
    flag = true;
}

void PersonajePrincipal::MoverArribaPlataforma()
{
    if(this->pos().y() < 100 && this->pos().x() >= 550)
    {
        Velocidad_x = 0;
        Velocidad_y = -35;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().y() < 270  && this->pos().y() > 100 && this->pos().x() >= 550 )
    {
        Velocidad_x = 0;
        Velocidad_y = -70;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().x() >= 550)
    {
        Velocidad_x = 0;
        Velocidad_y = -70;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().x()<540 && this->pos().y() < 400)
    {
        Velocidad_x = 0;
        Velocidad_y = -40;
        Aceleracion_y = 10;
        flag = true;
    }

}

void PersonajePrincipal::Disparar()
{
    if(Disparos > 0 && Disparos < 3)
    {
        Bullet = new BalaSimple(10,4,0,pos().x(),pos().y(),Scene);
        Scene->addItem(Bullet);
        Disparos--;
    }
}

void PersonajePrincipal::Calcular()
{
    Contador++;
    if(Contador == 117)
    {
        Disparos = 2;
        Contador = 0;
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(balamovarmsim) == typeid (*Elemento))
        {
            Vida = Vida-50;
            Parametros_Pantalla->decreaseHealth(50);
            Scene->removeItem(Elemento);
            delete Elemento;
        }
        else if(typeid(Trampolines) == typeid (*Elemento))
        {

            this->MoverArribaPlataforma();
        }
        else if(typeid(Door) == typeid (*Elemento))
        {
            level_2 = true;
        }
    }

    if(flag == true)
    {
        Velocidad_x = Velocidad_x + (Aceleracion_x*delta);
        Velocidad_y = Velocidad_y + (Aceleracion_y*delta);

        Posicion_x = Posicion_x + (Velocidad_x*delta);
        Posicion_y = Posicion_y + (Velocidad_y*delta) + (0.5*Aceleracion_y*delta*delta);
        setPos(Posicion_x,Posicion_y);
        if(pos().y()>440)
        {
            setPos(Posicion_x,440);
            Posicion_y = 440;
            flag = false;
        }
    }
}

void PersonajePrincipal::setPosicion_y(double value)
{
    Posicion_y = value;
}

void PersonajePrincipal::RestarVida(int CantidadV)
{
    Vida-=CantidadV;
    Parametros_Pantalla->decreaseHealth(CantidadV);
}
