#include "enemigometioritos.h"

EnemigoMeteoritos::EnemigoMeteoritos(double pos_x,double pos_y,int Limit_Inf, int Limit_Sup, QGraphicsScene *Scene_Aux)
{
    //Se recibe las posiciones, y los limites de movieminto , tambien un puntero de la escena
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
    Timer_2->start(900);

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
    //movimiento rectilineo, se desplaza en el rango LI_s y LI_i y se le da la posicion de la escena
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
    //se crea un objeto de tipo bala_caida libre, el objeto creado es independiente
    MeteoritosEnemy = new Bala_CaidaLibre(15,15,Scene,Posicion_x,Posicion_y);
    Scene->addItem(MeteoritosEnemy);
}
