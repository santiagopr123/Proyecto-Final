#ifndef ENEMIGOMOVCIRCULAR_H
#define ENEMIGOMOVCIRCULAR_H

#include <QObject>
#include <math.h>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <qdebug.h>
#include <QTimer>
#include <QPixmap>

#include "balasimple.h"
#include "proyectilesparabolicos.h"


class EnemigoMovCircular:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:

    int radio;
    int Radio;
    double Velocidad_Angular;
    double DeltaTiempo;
    double Posicion_x;
    double Posicion_y;
    double Centro_x;
    double Centro_y;
    double Angulo;

    QTimer *Timer;
    QGraphicsScene *Scene;

public:
    EnemigoMovCircular(int r,int RC, double tiempo,QGraphicsScene *SceneAux);
    ~EnemigoMovCircular();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void setCentro_x(double value);

    void setCentro_y(double value);

private slots:

    void Move();


};

#endif // ENEMIGOMOVCIRCULAR_H
