#include "enemigomovcircular.h"

void EnemigoMovCircular::setCentro_x(double value)
{
    Centro_x = value;
}

void EnemigoMovCircular::setCentro_y(double value)
{
    Centro_y = value;
}

EnemigoMovCircular::EnemigoMovCircular(int r, double tiempo)
{
    Velocidad_Angular = 2;
    DeltaTiempo = tiempo;
    radio = r;
    Radio = 100;


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
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoMovCircular::Move()
{
    Angulo = Velocidad_Angular*DeltaTiempo;

    Posicion_x = Centro_x + (Radio*cos(Angulo));
    Posicion_y = Centro_y + (Radio*sin(Angulo));

    DeltaTiempo+=0.07;

    setPos(Posicion_x,Posicion_y);
}
