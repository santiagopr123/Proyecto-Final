#ifndef TRAMPOLINES_H
#define TRAMPOLINES_H

#include <QGraphicsItem>
#include <QPainter>

class Trampolines: public QGraphicsItem
{
private:
    int ancho;
    int alto;
    double Posicion_x;
    double Posicion_y;

public:
    Trampolines(double pos_x,double pos_y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // TRAMPOLINES_H
