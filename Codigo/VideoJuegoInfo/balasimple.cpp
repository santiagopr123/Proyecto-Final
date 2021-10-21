#include "balasimple.h"

BalaSimple::BalaSimple(int a, int al,int *P,int Op,double pos_x,double pos_y,QGraphicsScene *Scene_Aux)
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
    puntaje = P;
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
//    QList<QGraphicsItem*> colliding_items = collidingItems();
//    for(int i=0; i < colliding_items.size(); ++i)
//    {
//        QGraphicsItem *Elemento = colliding_items[i];
//        if(typeid(enemigo) == typeid(*Elemento))
//        {
//            Window_2->removeItem(colliding_items[i]);
//            Window_2->removeItem(this);
//            delete colliding_items[i];
//            delete this;
//            *puntaje = *puntaje+1;
//        }
//        else if(typeid(Bala_MAS) == typeid(*Elemento))
//        {
//            Window_2->removeItem(colliding_items[i]);
//            Window_2->removeItem(this);
//            delete colliding_items[i];
//            delete this;
//        }
//        else if(typeid(Enemigo_MAS) == typeid(*Elemento))
//        {
//            Window_2->removeItem(this);
//            delete this;
//        }
//    }

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
