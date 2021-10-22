#include "enemigointeligente.h"

EnemigoInteligente::EnemigoInteligente(int a, int al,QGraphicsScene *Scene_Aux,double Pos_x,double Pos_y, bool *Flag_newEnemy,PersonajePrincipal *Personaje,int *ApuntadorPuntaje)
{
    ancho = a;
    alto = al;
    Scene = Scene_Aux;
    Flag_Aux = Flag_newEnemy;
    Incremento = 2;
    contador = 0;
    Puntaje = ApuntadorPuntaje;

    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    velocidad = 0;
    delta = 0.3;
    Gravedad = 9.8;
    Character = Personaje;
    Vida = 200;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer;
    connect(Timer,SIGNAL(timeout()),this,SLOT(MoveAnDCreateBullet()));
    Timer->start(70);

}

EnemigoInteligente::~EnemigoInteligente()
{
    delete Timer;

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

void EnemigoInteligente::MoveAnDCreateBullet()
{
    contador++;
    if(contador >= 35)
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

        contador = 0;
    }

    if(this->collidesWithItem(Character))
    {
        Character->RestarVida(1);
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid (*Elemento))
        {
            Vida-=50;
            Scene->removeItem(Elemento);
            delete Elemento;
            if(Vida<0)
            {
                *Flag_Aux = true;
                *Puntaje +=100;
                Scene->removeItem(this);
                delete this;
            }
        }
    }

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
