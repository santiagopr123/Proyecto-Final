#ifndef ENEMIGOINTELIGENTE_H
#define ENEMIGOINTELIGENTE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

#include "personajeprincipal.h"
#include "balamovarmsim.h"
#include "balasimple.h"
#include "door.h"

class EnemigoInteligente:public QObject,public QGraphicsItem
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
    bool *Flag_Aux;
    int Incremento;
    double Vida;
    int contador;
    int *Puntaje;
    int Li_S,Li_I;
    int Opcion;

    QGraphicsScene *Scene;
    PersonajePrincipal *Character;
    balamovarmsim *Bullet;
    Door *NextLevel;

public:
    EnemigoInteligente(int a, int al,QGraphicsScene *Scene_Aux,double Pos_x,double Pos_y, bool *Flag_newEnemy,PersonajePrincipal *Personaje,int *ApuntadorPuntaje,int Op);
    EnemigoInteligente(int a, int al,QGraphicsScene *Scene_Aux,double Pos_x,double Pos_y,PersonajePrincipal *Personaje,int *ApuntadorPuntaje,int Lis,int Lii,int Op);
    ~EnemigoInteligente();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:
    void MoveAnDCreateBullet();

};


#endif // ENEMIGOINTELIGENTE_H
