#include "boss.h"

Boss::Boss(int a, int al, double Pos_x, double Pos_y, QGraphicsScene *Scene_Aux)
{
    Scene = Scene_Aux;
    ancho = a;
    alto = al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    DeltaDesplazamientoY = 5;
    DeltaDesplazamientoX = 0;
    Vida = 2000;

    timer = new QTimer();

    Escudo_1 = new EnemigoMovCircular(10,0);
    Scene->addItem(Escudo_1);
    Escudo_2 = new EnemigoMovCircular(10,1.5707963267948966192313216916398);
    Scene->addItem(Escudo_2);

    connect(timer,SIGNAL(timeout()),SLOT(move()));
    timer->start(50);
}

Boss::~Boss()
{
    delete timer;
}

QRectF Boss::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
}

void Boss::setDeltaDesplazamientoY(double value)
{
    DeltaDesplazamientoY = value;
}

void Boss::setDeltaDesplazamientoX(double value)
{
    DeltaDesplazamientoX = value;
}

void Boss::move()
{
    Posicion_y+=DeltaDesplazamientoY;
    Posicion_x+=DeltaDesplazamientoX;

    Escudo_1->setCentro_x(Posicion_x);
    Escudo_1->setCentro_y(Posicion_y);
    Escudo_2->setCentro_x(Posicion_x);
    Escudo_2->setCentro_y(Posicion_y);

    setPos(Posicion_x,Posicion_y);

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid(*Elemento))
        {
            Vida-=150;
            Scene->removeItem(Elemento);
            delete Elemento;
            if(Vida<0)
            {
                Scene->removeItem(this);
                Scene->removeItem(Escudo_1);
                Scene->removeItem(Escudo_2);
                delete  Escudo_1;
                delete Escudo_2;
                delete this;
            }
        }
    }
}
