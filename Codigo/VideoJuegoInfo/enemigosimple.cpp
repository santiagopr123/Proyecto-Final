#include "enemigosimple.h"

EnemigoSimple::EnemigoSimple(int a, int al, double Pos_x, double Pos_y, QGraphicsScene *Scene_Aux, int *ApuntadorPuntaje)
{
    Scene = Scene_Aux;
    ancho = a;
    alto = al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Puntaje = ApuntadorPuntaje;
    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),SLOT(move()));
    timer->start(50);
}

EnemigoSimple::~EnemigoSimple()
{
    delete timer;
}

QRectF EnemigoSimple::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void EnemigoSimple::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/enemy.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(1.7);
}

void EnemigoSimple::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid (*Elemento))
        {
            *Puntaje+=200;
            Scene->removeItem(Elemento);
            Scene->removeItem(this);
            delete Elemento;
            delete this;
        }
        else if(typeid(ProyectilesParabolicos) == typeid (*Elemento))
        {
            *Puntaje+=200;
            Scene->removeItem(Elemento);
            Scene->removeItem(this);
            delete Elemento;
            delete this;
        }

    }

    Posicion_y+=5;
    setPos(Posicion_x,Posicion_y);

    if(pos().y()>400)
    {
        scene()->removeItem(this);
        delete this;
    }
}
