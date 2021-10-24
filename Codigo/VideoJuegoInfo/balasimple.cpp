#include "balasimple.h"

BalaSimple::BalaSimple(int a, int al, int Op, double pos_x, double pos_y, QGraphicsScene *Scene_Aux)
{
    ancho = a;
    alto = al;
    Posicion_x = pos_x;
    Posicion_y = pos_y;
    Desplazamiento = 0;

    Option = Op;
    Scene = Scene_Aux;

    timer = new QTimer();
    setPos(Posicion_x,Posicion_y);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

BalaSimple::~BalaSimple()
{
    delete timer;
}

QRectF BalaSimple::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void BalaSimple::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
}

void BalaSimple::move()
{

    if(Option == 0)
    {
        Posicion_y-=10;
        setPos(Posicion_x,Posicion_y);
        if(pos().y()-20<0)
        {
            Scene->removeItem(this);
            delete this;
        }
    }
    else if(Option == 1)
    {
        Posicion_x+=8;
        Desplazamiento+=8;
        setPos(Posicion_x,Posicion_y);

        if(Desplazamiento >= 400)
        {
            Scene->removeItem(this);
            delete this;
        }
    }
    else if(Option == 2)
    {

        Posicion_x-=8;
        Desplazamiento-=8;
        setPos(Posicion_x,Posicion_y);

        if(Desplazamiento <= -400)
        {
            Scene->removeItem(this);
            delete this;
        }
    }
}
