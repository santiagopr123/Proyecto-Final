#ifndef ENEMIGOPENDULAR_H
#define ENEMIGOPENDULAR_H

#include <math.h>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <qdebug.h>
#include <ctime>

#include "personajeprincipal.h"
#include "enemigointeligente.h"

class EnemigoPendular:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    double Angulo_Inicial;
    double Angulo;
    double Velocidad_Angular_Inicial;
    double Velocidad_Angular;
    double Aceleracion_Angular;
    double Posicion_x =350;
    double Posicion_y = 150;

    const double tiempo = 0.002;
    const double Aceleracion_Gravedad = 9.8;
    const int Longitud =sqrt(pow(Posicion_y,2)+pow(Posicion_x,2));
    const int radio = 12;

    bool Flag,FlagMulti;
    bool *Apuntador_Flag;

    int *Puntaje;


    EnemigoInteligente *Hijo;
    QGraphicsScene *Scene;
    PersonajePrincipal *Character_1,*Character_2;
    QTimer *timer;
    int Contador;

public:
    EnemigoPendular(QGraphicsScene *Scene_Aux, PersonajePrincipal *Personaje_1, int *ApuntadorPuntaje);
    EnemigoPendular(QGraphicsScene *Scene_Aux,PersonajePrincipal *Personaje_1,PersonajePrincipal *Personaje_2,int *ApuntadorPuntaje);
    ~EnemigoPendular();

    void calcular_variables();
    void actualizar_posicion();

    QRectF boundingRect() const;//Para el color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:

    void move();
};

#endif // ENEMIGOPENDULAR_H
