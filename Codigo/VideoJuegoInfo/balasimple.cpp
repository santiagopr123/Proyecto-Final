#include "balasimple.h"

BalaSimple::BalaSimple(int r, int Op, double pos_x, double pos_y, QGraphicsScene *Scene_Aux)
{
    //Objeto que recibe un radio,posiciones y al escena donde se mostrara
    radio = r;

    Posicion_x = pos_x;
    Posicion_y = pos_y;
    Desplazamiento = 0;

    Option = Op;
    Scene = Scene_Aux;

    //Se crea el Qtimer para el movieminto propio
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
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void BalaSimple::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/balaPersonajes.png");
    painter->drawPixmap(-radio,-radio, 2*radio, 2*radio,pixmap);

    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void BalaSimple::move()
{

    //se gestiona el movieminto y velocidades de la bala, tambien el borrado de la misma
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
