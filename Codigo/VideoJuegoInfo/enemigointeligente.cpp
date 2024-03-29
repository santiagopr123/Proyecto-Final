#include "enemigointeligente.h"

EnemigoInteligente::EnemigoInteligente(int a, int al, QGraphicsScene *Scene_Aux, double Pos_x, double Pos_y, bool *Flag_newEnemy, PersonajePrincipal *Personaje, int *ApuntadorPuntaje, int Op)
{
    //Se inicializa las variables con las recibidas, a y al son el tamaño del objeto, tambien se reciben punteros de tipo
    //QGraphicsScene y bool para gestion de borrado y creacion de nuvos objetos de este tipo, ademas punteros a un personaje
    //esto ya que el enemigo lo debe de seguir
    ancho = a;
    alto = al;
    Scene = Scene_Aux;
    Flag_Aux = Flag_newEnemy;
    Incremento = 2;
    contador = 0;
    Puntaje = ApuntadorPuntaje;
    Opcion = Op;

    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    velocidad = 0;
    delta = 0.3;
    Gravedad = 9.8;
    //para la asignacion del puntero de tipo PersonajePrincipal se crea un atributo de clase del mismo tipo
    Character = Personaje;
    Vida = 200;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer;
    connect(Timer,SIGNAL(timeout()),this,SLOT(MoveAnDCreateBullet()));
    Timer->start(70);

}

EnemigoInteligente::EnemigoInteligente(int a, int al, QGraphicsScene *Scene_Aux, double Pos_x, double Pos_y, PersonajePrincipal *Personaje, int *ApuntadorPuntaje, int Lis, int Lii, int Op)
{
    //Se inicializa las variables con las recibidas, a y al son el tamaño del objeto, tambien se reciben punteros de tipo
    //QGraphicsScene y bool para gestion de borrado y creacion de nuvos objetos de este tipo, ademas punteros a un personaje
    //esto ya que el enemigo lo debe de seguir
    //Tambien limites el cual sirven para que no se desplace fuera del rango
    ancho = a;
    alto = al;
    Scene = Scene_Aux;
    Incremento = 2;
    contador = 0;
    Puntaje = ApuntadorPuntaje;
    Li_I = Lii;
    Li_S = Lis;
    Character = Personaje;

    Opcion = Op;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    velocidad = 0;
    delta = 0.3;
    Gravedad = 9.8;
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
    QPixmap pixmap(":/Imagenes/EnemyS.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(5);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoInteligente::MoveAnDCreateBullet()
{
    //gestion de las colisiones e interacciones con otros objetos , ademas de los limites de movimiento para seguir al personaje que
    //se le asigne y un contador el cual le comunica al objeto que debe de disparar a la direccion el cual esta el personaje
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
            if(Vida<=0)
            {
                if(Opcion == 1)
                {
                    *Flag_Aux = true;
                    *Puntaje +=100;
                    Scene->removeItem(this);
                    delete this;
                }
                else if(Opcion == 2)
                {
                    NextLevel = new Door(600,200);
                    Scene->addItem(NextLevel);
                    *Puntaje +=100;
                    Scene->removeItem(this);
                    delete this;
                }
            }
        }
    }

    if(Opcion == 1)
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
    }
    else if(Opcion == 2)
    {
        if(Posicion_x>=Li_S)
        {
            Incremento = -2;
        }
        else if(Posicion_x<=Li_I)
        {
            Incremento = 2;
        }
        Posicion_x+=Incremento;

        setPos(Posicion_x,Posicion_y);

        contador++;

        if(contador >= 35)
        {
            if(Posicion_x-550 < Character->pos().x() && Posicion_x > Character->pos().x())
            {
                Bullet = new balamovarmsim(this->pos().x(),this->pos().y(),this->pos().y(),0,Scene);
                Scene->addItem(Bullet);
            }
            else if( Character->pos().x() > Posicion_x && Posicion_x+550 > Character->pos().x())
            {
                Bullet = new balamovarmsim(this->pos().x(),this->pos().y(),this->pos().y(),1,Scene);
                Scene->addItem(Bullet);
            }

            contador = 0;
        }
    }

}
