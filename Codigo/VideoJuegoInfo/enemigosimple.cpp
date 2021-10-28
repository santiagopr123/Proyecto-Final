#include "enemigosimple.h"

EnemigoSimple::EnemigoSimple(int a, int al, double Pos_x, double Pos_y, QGraphicsScene *Scene_Aux, int *ApuntadorPuntaje, PersonajePrincipal *PersonajeAux)
{
    //se recibe las posiciones, ademas se recibe un puntero a la ecena de donde se esta jugando y un apuntador de tipo int del puntaje global
    //que es el puntaje global del o de los jugadores
    Scene = Scene_Aux;
    ancho = a;
    alto = al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Puntaje = ApuntadorPuntaje;
    Personaje = PersonajeAux;


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

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoSimple::move()
{
    //Este es el slot que se le asigna al timer, aqui se gestiona las colisiones, en caso de que este objeto se elimine
    //este le asiga al puntero desreferenciado un valor

    if(this->collidesWithItem(Personaje))
    {
        Personaje->RestarVida(30);
    }

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

    //en el caso de que este oase el limite que es 400 se lemininara
    if(pos().y()>400)
    {
        Personaje->RestarVida(30);
        Scene->removeItem(this);
        delete this;
    }

}
