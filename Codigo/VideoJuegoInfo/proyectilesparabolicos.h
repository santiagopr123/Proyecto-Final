#ifndef PROYECTILESPARABOLICOS_H
#define PROYECTILESPARABOLICOS_H

#include <math.h>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsScene>


class ProyectilesParabolicos:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    double velocidad_inicial;
    double velocidad_x;
    double velocidad_y;
    double angulo;
    double posicion_x;
    double posicion_y;

    double delta = 0.01;
    double gravedad = 9.8;

    int radio = 8;

    QTimer *timer;

    QGraphicsScene *Scenes;
public:
    ProyectilesParabolicos(double x,double y,double v,double a,QGraphicsScene *Scene_Aux);
    ~ProyectilesParabolicos();


    QRectF boundingRect() const;//Para el color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void actualizarposicion();
    void calcularvelocidad();

public slots:
    void move();
};

#endif // PROYECTILESPARABOLICOS_H
