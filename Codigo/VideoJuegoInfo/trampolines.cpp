#include "trampolines.h"

Trampolines::Trampolines(double pos_x, double pos_y)
{
    //se reciben posiciones del objeto
    ancho = 60;
    alto = 20;
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
    QPixmap pixmap(":/Imagenes/Platforgame.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(1.7);
}

