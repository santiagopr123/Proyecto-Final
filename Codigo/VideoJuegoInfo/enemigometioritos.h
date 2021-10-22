#ifndef ENEMIGOMETIORITOS_H
#define ENEMIGOMETIORITOS_H
#include <QObject>
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <qdebug.h>
#include <QTimer>

#include "bala_caidalibre.h"

class EnemigoMeteoritos:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    double Posicion_x;
    double Posicion_y;
    double ancho;
    double alto;
    int Op;
    int Li_S,Li_I,Incremento;

    int Cambio_Derecha;
    int Cambio_Lado;

    QGraphicsScene * Scene;
    QTimer *Timer,*Timer_2;
    Bala_CaidaLibre *MeteoritosEnemy;

public:
    EnemigoMeteoritos(double pos_x,double pos_y,int Limit_Inf, int Limit_Sup, QGraphicsScene *Scene_Aux);
    ~EnemigoMeteoritos();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public slots:

    void MoveEnemy();
    void SpawnMeteoro();
};

#endif // ENEMIGOMETIORITOS_H
