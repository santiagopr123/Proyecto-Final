#include "enemigometioritos.h"

EnemigoMeteoritos::EnemigoMeteoritos(double pos_x,double pos_y,int Limit_Inf, int Limit_Sup, QGraphicsScene *Scene_Aux)
{
    Posicion_x = pos_x;
    Posicion_y = pos_y;

    Li_I = Limit_Inf;
    Li_S = Limit_Sup;

    Scene = Scene_Aux;
    Incremento = 3;
    ancho = 32;
    alto = 25;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer();
    Timer_2 = new QTimer();

    connect(Timer,SIGNAL(timeout()),this,SLOT(MoveEnemy()));
    connect(Timer_2,SIGNAL(timeout()),this,SLOT(SpawnMeteoro()));

    Timer->start(70);
    Timer_2->start(3500);

}

EnemigoMeteoritos::~EnemigoMeteoritos()
{
    delete Timer;
    delete Timer_2;
}

QRectF EnemigoMeteoritos::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void EnemigoMeteoritos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/meteoroEnemy.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(1.7);
}

void EnemigoMeteoritos::MoveEnemy()
{
    if(Posicion_x>=Li_S)
    {
        Incremento = -3;
    }
    else if(Posicion_x<=Li_I)
    {
        Incremento = 3;
    }
    Posicion_x+=Incremento;

    setPos(Posicion_x,Posicion_y);

}

void EnemigoMeteoritos::SpawnMeteoro()
{
    MeteoritosEnemy = new Bala_CaidaLibre(15,15,Scene,Posicion_x,Posicion_y);
    Scene->addItem(MeteoritosEnemy);
}
