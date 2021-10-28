#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QPixmap>

class Door: public QGraphicsItem
{
private:
    int ancho;
    int alto;
    double Posicion_x;
    double Posicion_y;

public:
    Door(double pos_x,double pos_y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // DOOR_H
