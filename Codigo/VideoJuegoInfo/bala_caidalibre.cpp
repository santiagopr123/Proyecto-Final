#include "bala_caidalibre.h"

Bala_CaidaLibre::Bala_CaidaLibre(int a, int al, QGraphicsScene *Window,double Pos_x,double Pos_y)
{
    ancho = a;
    alto = al;
    Window_2 = Window;

    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    velocidad = 0;
    delta = 0.3;
    Gravedad = 9.8;

    setPos(Posicion_x,Posicion_y);
    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(MoveTheBullet()));
    Timer->start(70);
}

Bala_CaidaLibre::~Bala_CaidaLibre()
{
    delete Timer;
}

QRectF Bala_CaidaLibre::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Bala_CaidaLibre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
}

void Bala_CaidaLibre::MoveTheBullet()
{
    Posicion_y = Posicion_y + (velocidad*delta) + (0.5*Gravedad*delta*delta);
    velocidad = velocidad + (Gravedad*delta);
    setPos(Posicion_x,Posicion_y);

    if(Posicion_y > 450)
    {
        Window_2->removeItem(this);
        delete this;
    }
}
