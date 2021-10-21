#ifndef BALAMOVARMSIM_H
#define BALAMOVARMSIM_H

#include <math.h>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class balamovarmsim:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:

    double Posicion_x,Posicion_y;
    double Amplitud,masa,Constante_elastica;
    double Frecuencia_angular;
    double delta;
    int alto,ancho;
    int Longitud_Natural;
    int Option;

    QGraphicsScene *Scene;

    QTimer *Timer;
public:
    balamovarmsim(double Pos_x,double Pos_y, int Long_N,int Op,QGraphicsScene *Scene_Aux);
    ~balamovarmsim();

    QRectF boundingRect() const;//Para el color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public slots:

    void MoveBullet();

};

#endif // BALAMOVARMSIM_H
