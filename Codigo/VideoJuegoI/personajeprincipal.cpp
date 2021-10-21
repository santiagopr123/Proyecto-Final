#include "personajeprincipal.h"

PersonajePrincipal::PersonajePrincipal(int An, int Al, double Pos_x, double Pos_y, double Vel_x, double Vel_y, double Ace_x, double Ace_y, int *Pu, QGraphicsScene *Scene_Aux, Vista *Aux_Parametros)
{
    ancho = An;
    alto = Al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Velocidad_x = Vel_x;
    Velocidad_y = Vel_y;
    Aceleracion_x = Ace_x;
    Aceleracion_y = Ace_y;
    Vida = 1000;
    Puntaje = Pu;
    Scene = Scene_Aux;
    Disparos = 2;
    Parametros_Pantalla = Aux_Parametros;

    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(Calcular()));

    Timer_2 = new QTimer();
    connect(Timer_2,SIGNAL(timeout()),this,SLOT(Recarga()));

    setPos(Posicion_x,Posicion_y);

    Timer->start(20);
    Timer_2->start(3500);


}

QRectF PersonajePrincipal::boundingRect() const
{

}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void PersonajePrincipal::MoverDerecha()
{

}

void PersonajePrincipal::MoverIzquierda()
{

}

void PersonajePrincipal::MoverArriba()
{

}

void PersonajePrincipal::MoverArribaPlataforma()
{

}

void PersonajePrincipal::Disparar()
{

}

void PersonajePrincipal::Calcular()
{

}

void PersonajePrincipal::Recarga()
{

}
