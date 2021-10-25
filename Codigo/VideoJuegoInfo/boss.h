#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

#include "enemigomovcircular.h"
#include "balasimple.h"
#include "vista.h"

class Boss:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    int ancho;
    int alto;
    QTimer *timer;
    QGraphicsScene *Scene;
    Vista *ParametrosScene;
    double DeltaDesplazamientoX;
    double DeltaDesplazamientoY;
    double Posicion_x,Posicion_y;
    double Vida;

    EnemigoMovCircular *Escudo_1,*Escudo_2,*Escudo_3,*Escudo_4;
public:
    Boss(int a, int al, double Pos_x, double Pos_y, QGraphicsScene *Scene_Aux, Vista *Para);
    ~Boss();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void setDeltaDesplazamientoY(double value);

    void setDeltaDesplazamientoX(double value);

    double getVida() const;

public slots:
    void move();
};

#endif // BOSS_H
