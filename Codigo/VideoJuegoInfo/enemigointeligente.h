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
    QTimer *Timer,*Timer_2;
    bool *Flag_Aux;
    int Incremento;

    QGraphicsScene *Scene;
    PersonajePrincipal *Character;
    balamovarmsim *Bullet;
public:
    EnemigoInteligente(int a, int al,QGraphicsScene *Scene_Aux,double Pos_x,double Pos_y, bool *Flag_newEnemy,PersonajePrincipal *Personaje);
    ~EnemigoInteligente();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:

    void Move();
    void CreateTheBullet();
};

#endif // ENEMIGOINTELIGENTE_H
