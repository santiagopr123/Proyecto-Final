#include "enemigomovcircular.h"

//varibles las cuales se le asignan a la clase, primordiales para el movimiento circular
void EnemigoMovCircular::setCentro_x(double value)
{
    Centro_x = value;
}

void EnemigoMovCircular::setCentro_y(double value)
{
    Centro_y = value;
}

EnemigoMovCircular::EnemigoMovCircular(int r, int RC, double tiempo, QGraphicsScene *SceneAux)
{
    //se recibe el tiempo, mas especificamente el periodo y  un puntero a la escena, ademas el radio del centro
    //de masa de la particula y el radio al centro del movimiento
    Velocidad_Angular = 2;
    DeltaTiempo = tiempo;
    radio = r;
    Radio = RC;
    Scene = SceneAux;


    //se crea el timer
    Timer = new QTimer;
    connect(Timer,SIGNAL(timeout()),this,SLOT(Move()));
    Timer->start(50);

}

EnemigoMovCircular::~EnemigoMovCircular()
{
    delete Timer;
}

QRectF EnemigoMovCircular::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void EnemigoMovCircular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap pixmap(":/Imagenes/Escudoenemigo.png");
    painter->drawPixmap(-radio,-radio, 2*radio, 2*radio,pixmap);
    setScale(1.7);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoMovCircular::Move()
{
    //ecuaciones del angulo respecto al tiempo y la velocidad angular constante
    //la posicion ademas es respecto al radio de giro
    Angulo = Velocidad_Angular*DeltaTiempo;

    Posicion_x = Centro_x + (Radio*cos(Angulo));
    Posicion_y = Centro_y + (Radio*sin(Angulo));

    DeltaTiempo+=0.07;

    setPos(Posicion_x,Posicion_y);

    //gestion de colisiones
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid (*Elemento))
        {
            Scene->removeItem(Elemento);
            delete Elemento;
        }
        if(typeid(ProyectilesParabolicos) == typeid (*Elemento))
        {
            Scene->removeItem(Elemento);
            delete Elemento;
        }
    }
}
