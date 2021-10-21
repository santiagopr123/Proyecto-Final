#include "enemigointeligente.h"

EnemigoInteligente::EnemigoInteligente(int a, int al,QGraphicsScene *Scene_Aux,double Pos_x,double Pos_y, bool *Flag_newEnemy,PersonajePrincipal *Personaje)
{
    ancho = a;
    alto = al;
    Scene = Scene_Aux;
    Flag_Aux = Flag_newEnemy;
    Incremento = 2;

    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    velocidad = 0;
    delta = 0.3;
    Gravedad = 9.8;
    Character = Personaje;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer;
    connect(Timer,SIGNAL(timeout()),this,SLOT(Move()));
    Timer->start(70);

    Timer_2 = new QTimer;
    connect(Timer_2,SIGNAL(timeout()),this,SLOT(CreateTheBullet()));
    Timer_2->start(2500);
}

EnemigoInteligente::~EnemigoInteligente()
{
    delete Timer;
    delete Timer_2;
}

QRectF EnemigoInteligente::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void EnemigoInteligente::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoInteligente::Move()
{
    if(Character->pos().x() < Posicion_x)
    {
        Incremento = -2;
    }
    else if(Character->pos().x() > Posicion_x)
    {
        Incremento = 2;
    }

    if(pos().y()<440)
    {
        Posicion_y = Posicion_y + (velocidad*delta) + (0.5*Gravedad*delta*delta);
        velocidad = velocidad + (Gravedad*delta);
        setPos(Posicion_x,Posicion_y);
    }
    else
    {
        Posicion_y = 440;
        Posicion_x+= Incremento;
        setPos(Posicion_x,Posicion_y);
    }
}

void EnemigoInteligente::CreateTheBullet()
{
    if(Character->pos().x() > Posicion_x)
    {
        Bullet = new balamovarmsim(this->pos().x(),this->pos().y(),this->pos().y(),1,Scene);
        Scene->addItem(Bullet);
    }
    else
    {
        Bullet = new balamovarmsim(this->pos().x(),this->pos().y(),this->pos().y(),0,Scene);
        Scene->addItem(Bullet);
    }
}
