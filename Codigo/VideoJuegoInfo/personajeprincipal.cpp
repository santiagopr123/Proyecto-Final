#include "personajeprincipal.h"

bool PersonajePrincipal::getLevel_2() const
{
    return level_2;
}

void PersonajePrincipal::setDeltaPosx(int value)
{
    DeltaPosx = value;
}

double PersonajePrincipal::getVida() const
{
    return Vida;
}

PersonajePrincipal::PersonajePrincipal(int An, int Al, double Pos_x, double Pos_y, double Vel_x, double Vel_y, double Ace_x, double Ace_y, QGraphicsScene *Scene_Aux, Vista *Aux_Parametros, int OpB, int FlagP)
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
    Vida_Aux = Vida;
    Scene = Scene_Aux;
    DeltaPosx = 4;
    Disparos = 2;
    Parametros_Pantalla = Aux_Parametros;
    delta = 0.15;
    Contador = 0;
    level_2 = false;
    OpcionPersonaje = OpB;
    FlagPixmap = FlagP;

    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(Calcular()));
    Timer->start(30);
}

PersonajePrincipal::PersonajePrincipal(int An, int Al,double Pos_x,double Pos_y,double Vel_x,double Vel_y,double Ace_x,double Ace_y,QGraphicsScene *Scene_Aux,Vista *Aux_Parametros,double health,int OpB, int FlagP)
{
    ancho = An;
    alto = Al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    Velocidad_x = Vel_x;
    Velocidad_y = Vel_y;
    Aceleracion_x = Ace_x;
    Aceleracion_y = Ace_y;
    Vida = health;
    Vida_Aux = Vida;
    Scene = Scene_Aux;
    DeltaPosx = 4;
    Disparos = 2;
    Parametros_Pantalla = Aux_Parametros;
    delta = 0.15;
    Contador = 0;
    level_2 = false;
    OpcionPersonaje = OpB;
    FlagPixmap = FlagP;


    setPos(Posicion_x,Posicion_y);

    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(Calcular()));
    Timer->start(30);
}

PersonajePrincipal::~PersonajePrincipal()
{
    delete Timer;
}

QRectF PersonajePrincipal::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void PersonajePrincipal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(FlagPixmap == 0)
    {
        painter->setBrush(Qt::yellow);
        painter->drawRect(boundingRect());
    }
    else if(FlagPixmap == 1)
    {
        painter->setBrush(Qt::red);
        painter->drawRect(boundingRect());
    }
    else if(FlagPixmap == 2)
    {
        QPixmap pixmap(":/Imagenes/player_1.png");
        painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
        setScale(2);
    }
    else
    {
        QPixmap pixmap(":/Imagenes/player-2.png");
        painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
        setScale(2);
    }

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void PersonajePrincipal::MoverDerecha()
{
    Posicion_x+=DeltaPosx;
    setPos(Posicion_x,Posicion_y);
    if(Posicion_x > 1110)
    {
        Posicion_x = 1090;
    }
}

void PersonajePrincipal::MoverIzquierda()
{
    Posicion_x-=DeltaPosx;
    setPos(Posicion_x,Posicion_y);

    if(Posicion_x < 0)
    {
        Posicion_x = 5;
    }
}

void PersonajePrincipal::MoverArriba()
{
    Velocidad_x = 0;
    Velocidad_y = -50;
    Aceleracion_y = 10;
    flag = true;
}

void PersonajePrincipal::MoverArribaPlataforma()
{
    if(this->pos().y() < 100 && this->pos().x() >= 550)
    {
        Velocidad_x = 0;
        Velocidad_y = -35;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().y() < 270  && this->pos().y() > 100 && this->pos().x() >= 550 )
    {
        Velocidad_x = 0;
        Velocidad_y = -70;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().x() >= 550)
    {
        Velocidad_x = 0;
        Velocidad_y = -70;
        Aceleracion_y = 10;
        flag = true;
    }
    else if(this->pos().x()<540 && this->pos().y() < 400)
    {
        Velocidad_x = 0;
        Velocidad_y = -40;
        Aceleracion_y = 10;
        flag = true;
    }

}

void PersonajePrincipal::DisparaArriba()
{
    if(Disparos > 0 && Disparos < 3)
    {
        Bullet = new BalaSimple(7,0,pos().x(),pos().y(),Scene);
        Scene->addItem(Bullet);
        Disparos--;
    }
}

void PersonajePrincipal::DispararDerecha()
{
    if(Disparos > 0 && Disparos < 3)
    {

        Bullet = new BalaSimple(7,1,pos().x(),pos().y(),Scene);
        Scene->addItem(Bullet);
        Disparos--;
    }
}

void PersonajePrincipal::DispararIzquierda()
{
    if(Disparos > 0 && Disparos < 3)
    {

        Bullet = new BalaSimple(7,2,pos().x(),pos().y(),Scene);
        Scene->addItem(Bullet);
        Disparos--;
    }
}

void PersonajePrincipal::Calcular()
{
    Contador++;
    if(Contador == 117)
    {
        Disparos = 2;
        Contador = 0;
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];

        if(typeid(balamovarmsim) == typeid (*Elemento))
        {
            Vida = Vida-50;

            if(OpcionPersonaje == 0)
            {
                Parametros_Pantalla->decreaseHealthP1(50);
            }
            else
            {
                Parametros_Pantalla->decreaseHealthP2(50);
            }

            Scene->removeItem(Elemento);
            delete Elemento;
        }

        if(typeid (ProyectilesParabolicos) == typeid (*Elemento))
        {
            Vida = Vida-60;
            if(OpcionPersonaje == 0)
            {
                Parametros_Pantalla->decreaseHealthP1(60);
            }
            else
            {
                Parametros_Pantalla->decreaseHealthP2(60);
            }
            Scene->removeItem(Elemento);
            delete Elemento;
        }

        if(typeid(Trampolines) == typeid (*Elemento))
        {

            this->MoverArribaPlataforma();
        }

        if(typeid(Door) == typeid (*Elemento))
        {
            level_2 = true;
        }

        if(typeid(Bala_CaidaLibre) == typeid (*Elemento))
        {
            Vida = Vida-50;

            if(OpcionPersonaje == 0)
            {
                Parametros_Pantalla->decreaseHealthP1(50);
            }
            else
            {
                Parametros_Pantalla->decreaseHealthP2(50);
            }

            Scene->removeItem(Elemento);
            delete Elemento;
        }
        if(typeid(EnemigoAmortiguado) == typeid (*Elemento))
        {
            Vida = Vida-10;

            if(OpcionPersonaje == 0)
            {
                Parametros_Pantalla->decreaseHealthP1(10);
            }
            else
            {
                Parametros_Pantalla->decreaseHealthP2(10);
            }
        }

        if(typeid(EnemigoSimple) == typeid (*Elemento))
        {
            Vida = Vida-10;

            if(OpcionPersonaje == 0)
            {
                Parametros_Pantalla->decreaseHealthP1(10);
            }
            else
            {
                Parametros_Pantalla->decreaseHealthP2(10);
            }
        }
    }

    if(flag == true)
    {
        Velocidad_x = Velocidad_x + (Aceleracion_x*delta);
        Velocidad_y = Velocidad_y + (Aceleracion_y*delta);

        Posicion_x = Posicion_x + (Velocidad_x*delta);
        Posicion_y = Posicion_y + (Velocidad_y*delta) + (0.5*Aceleracion_y*delta*delta);
        setPos(Posicion_x,Posicion_y);
        if(pos().y()>440)
        {
            setPos(Posicion_x,440);
            Posicion_y = 440;
            flag = false;
        }
    }
}

void PersonajePrincipal::setPosicion_y(double value)
{
    Posicion_y = value;
}

void PersonajePrincipal::RestarVida(int CantidadV)
{
    Vida-=CantidadV;
    if(OpcionPersonaje == 0)
    {
        Parametros_Pantalla->decreaseHealthP1(CantidadV);
    }
    else
    {
        Parametros_Pantalla->decreaseHealthP2(CantidadV);
    }
}
