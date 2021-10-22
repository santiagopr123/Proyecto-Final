#include "trampolines.h"

Trampolines::Trampolines(double pos_x, double pos_y)
{
    ancho = 60;
    alto = 40;
    Posicion_x = pos_x;
    Posicion_y = pos_y;

    setPos(Posicion_x,Posicion_y);
}

QRectF Trampolines::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Trampolines::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
}
