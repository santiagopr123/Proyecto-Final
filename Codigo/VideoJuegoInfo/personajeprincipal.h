#ifndef PERSONAJEPRINCIPAL_H
#define PERSONAJEPRINCIPAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <typeinfo>

#include "balasimple.h"
#include "balamovarmsim.h"
#include "vista.h"

class PersonajePrincipal:public QObject, public QGraphicsItem
{
    Q_OBJECT
private:

    int alto;
    int ancho;

    double Posicion_x,Posicion_y;
    double Velocidad_x,Velocidad_y;
    double Aceleracion_x,Aceleracion_y;
    double delta;
    double Vida;
    int *Puntaje;
    int Disparos,Contador;


    bool flag = true;

    BalaSimple *Bullet;
    QTimer *Timer,*Timer_2;
    QGraphicsScene *Scene;
    Vista *Parametros_Pantalla;

public:
    PersonajePrincipal(int An, int Al,double Pos_x,double Pos_y,double Vel_x,double Vel_y,double Ace_x,double Ace_y,int *Pu,QGraphicsScene *Scene_Aux,Vista *Aux_Parametros);
    QRectF boundingRect() const;//Para el color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoverDerecha();
    void MoverIzquierda();
    void MoverArriba();
    void MoverArribaPlataforma();
    void Disparar();

public slots:
    void Calcular();
    void Recarga();
};

#endif // PERSONAJEPRINCIPAL_H
