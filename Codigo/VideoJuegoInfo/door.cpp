#include "door.h"

Door::Door(double pos_x, double pos_y)
{
    ancho = 30;
    alto = 30;
    Posicion_x = pos_x;
    Posicion_y = pos_y;
    setPos(Posicion_x,Posicion_y);
}

QRectF Door::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/NextLevel.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(1.2);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
