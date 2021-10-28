#ifndef ENEMIGOSIMPLE_H
#define ENEMIGOSIMPLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

#include "balasimple.h"
#include "proyectilesparabolicos.h"
#include "personajeprincipal.h"


class EnemigoSimple:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    int ancho;
    int alto;
    double Posicion_x,Posicion_y;
    int *Puntaje;

    QTimer *timer;
    QGraphicsScene *Scene;
    PersonajePrincipal *Personaje;

public:
    EnemigoSimple(int a, int al,double Pos_x,double Pos_y,QGraphicsScene *Scene_Aux,int *ApuntadorPuntaje,PersonajePrincipal *PersonajeAux);
    ~EnemigoSimple();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:
    void move();
};

#endif // ENEMIGOSIMPLE_H
