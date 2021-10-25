#ifndef BALA_CAIDALIBRE_H
#define BALA_CAIDALIBRE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class Bala_CaidaLibre:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:

    int ancho;
    int alto;
    double delta;
    double Gravedad;
    double velocidad;
    double Posicion_x,Posicion_y;
    QTimer *Timer;

    QGraphicsScene *Window_2;

public:

    Bala_CaidaLibre(int a, int al,QGraphicsScene *Window,double Pos_x,double Pos_y);
    ~Bala_CaidaLibre();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


public slots:

    void MoveTheBullet();
};

#endif // BALA_CAIDALIBRE_H
