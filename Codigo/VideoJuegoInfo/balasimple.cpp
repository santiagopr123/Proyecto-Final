#include "balasimple.h"

BalaSimple::BalaSimple(int a, int al, int Op, double pos_x, double pos_y, QGraphicsScene *Scene_Aux)
{
    ancho = a;
    alto = al;
    Posicion_x = pos_x;
    Posicion_y = pos_y;
    Desplazamiento = 0;

    Option = Op;

    timer = new QTimer();
    setPos(Posicion_x,Posicion_y);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
    Scene = Scene_Aux;
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
        setPos(pos().x(),pos().y()-10);
        if(pos().y()-20<0)
        {
            Scene->removeItem(this);
            delete this;
        }
    }
    else if(Option == 1)
    {
        setPos(pos().x()+8,pos().y());
        Desplazamiento+=8;
        if(Desplazamiento >=400)
        {
            Scene->removeItem(this);
            delete this;
        }
    }
}
