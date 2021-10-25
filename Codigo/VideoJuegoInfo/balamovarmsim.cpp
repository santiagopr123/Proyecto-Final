#include "balamovarmsim.h"

balamovarmsim::balamovarmsim(double Pos_x, double Pos_y, int Long_N, int Op, QGraphicsScene *Scene_Aux)
{
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Scene = Scene_Aux;
    Longitud_Natural = Long_N;
    delta = 0.4;
    alto = 10;
    ancho = 10;
    masa = 10;
    Option = Op;

    Scene = Scene_Aux;

    Amplitud = 20;
    Constante_elastica = 2;
    Frecuencia_angular = sqrt(Constante_elastica/masa);

    Timer = new QTimer();
   connect(Timer,SIGNAL(timeout()),this,SLOT(MoveBullet()));

    setPos(Posicion_x, Posicion_y+Longitud_Natural);
    Timer->start(30);
}

balamovarmsim::~balamovarmsim()
{
    delete Timer;
}

QRectF balamovarmsim::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void balamovarmsim::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void balamovarmsim::MoveBullet()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid(*Elemento))
        {
            Scene->removeItem(Elemento);
            Scene->removeItem(this);
            delete Elemento;
            delete this;
            return;
        }
    }

    Posicion_y = Amplitud*cos(Frecuencia_angular*delta);
    if(Option == 0)
    {
        Posicion_x-=5;
    }
    else if(Option == 1)
    {
        Posicion_x+=5;
    }


    setPos(Posicion_x,Posicion_y+Longitud_Natural);
    delta+=0.4;

    if(Posicion_x <50 || Posicion_x > 1400)
    {
        Scene->removeItem(this);
        delete this;
    }
}
