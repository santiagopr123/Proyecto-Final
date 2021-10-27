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
#include "bala_caidalibre.h"
#include "vista.h"
#include "trampolines.h"
#include "door.h"
#include "proyectilesparabolicos.h"
#include "enemigoamortiguado.h"
#include "enemigosimple.h"

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
    double Vida,Vida_Aux;
    int Disparos,Contador;
    int DeltaPosx;
    int OpcionPersonaje;


    bool flag = true;
    bool level_2;

    BalaSimple *Bullet;
    QTimer *Timer;
    QGraphicsScene *Scene;
    Vista *Parametros_Pantalla;

public:
    PersonajePrincipal(int An, int Al,double Pos_x,double Pos_y,double Vel_x,double Vel_y,double Ace_x,double Ace_y,QGraphicsScene *Scene_Aux,Vista *Aux_Parametros,int OpB);
    PersonajePrincipal(int An, int Al,double Pos_x,double Pos_y,double Vel_x,double Vel_y,double Ace_x,double Ace_y,QGraphicsScene *Scene_Aux,Vista *Aux_Parametros,double health,int OpB);
    ~PersonajePrincipal();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoverDerecha();
    void MoverIzquierda();
    void MoverArriba();
    void MoverArribaPlataforma();

    void DisparaArriba();
    void DispararDerecha();
    void DispararIzquierda();

    void setPosicion_y(double value);

    void RestarVida(int CantidadV);

    bool getLevel_2() const;

    void setDeltaPosx(int value);

    double getVida() const;

public slots:
    void Calcular();
};

#endif // PERSONAJEPRINCIPAL_H
