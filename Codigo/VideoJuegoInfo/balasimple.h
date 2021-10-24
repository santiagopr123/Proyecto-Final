#ifndef BALASIMPLE_H
#define BALASIMPLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class BalaSimple:public QObject,public QGraphicsItem
{
    Q_OBJECT

private:

    int ancho;
    int alto;
    double Posicion_x;
    double Posicion_y;
    int Option;
    double Desplazamiento;


    QGraphicsScene *Scene;
    QTimer * timer;
public:
    BalaSimple(int a, int al,int Op,double pos_x,double pos_y,QGraphicsScene *Scene_Aux);
    ~BalaSimple();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);



public slots:

    void move();
};

#endif // BALASIMPLE_H
