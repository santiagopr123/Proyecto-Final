#include "boss.h"

double Boss::getVida() const
{
    return Vida;
}

Boss::Boss(int a, int al, double Pos_x, double Pos_y, QGraphicsScene *Scene_Aux, Vista *Para)
{
    //se recibe el tamaño que tendra ademas de las posiciones, un puntero para la escena y los parametros
    //que se mostraran en escena, ademas para tener acceso a los metodos
    Scene = Scene_Aux;
    ancho = a;
    alto = al;
    Posicion_x = Pos_x;
    Posicion_y = Pos_y;
    DeltaDesplazamientoY = 5;
    DeltaDesplazamientoX = 0;
    Vida = 2000;
    ParametrosScene = Para;

    timer = new QTimer();

    //se inicializan dentro de este objeto, objetos de movimiento circular ya que la posicion de boss es fundamental
    //para el movieminto de los objetos EnemigoMovCircular
    Escudo_1 = new EnemigoMovCircular(10,70,0,Scene);
    Scene->addItem(Escudo_1);
    Escudo_2 = new EnemigoMovCircular(10,70,1.5707963267948966192313216916398,Scene);
    Scene->addItem(Escudo_2);
    Escudo_3 = new EnemigoMovCircular(10,75,0.78539816339744830961566084581988,Scene);
    Scene->addItem(Escudo_3);
    Escudo_4 = new EnemigoMovCircular(10,70,2.3561944901923449288469825374596,Scene);
    Scene->addItem(Escudo_4);

    connect(timer,SIGNAL(timeout()),SLOT(move()));
    timer->start(50);
}

Boss::~Boss()
{
    delete timer;
}

QRectF Boss::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/BossG.png");
    painter->drawPixmap(-ancho/2,-alto/2,ancho,alto,pixmap);
    setScale(1.7);
}

void Boss::setDeltaDesplazamientoY(double value)
{
    DeltaDesplazamientoY = value;
}

void Boss::setDeltaDesplazamientoX(double value)
{
    DeltaDesplazamientoX = value;
}

void Boss::move()
{
    Posicion_y+=DeltaDesplazamientoY;
    Posicion_x+=DeltaDesplazamientoX;

    Escudo_1->setCentro_x(Posicion_x);
    Escudo_1->setCentro_y(Posicion_y);
    Escudo_2->setCentro_x(Posicion_x);
    Escudo_2->setCentro_y(Posicion_y);
    Escudo_3->setCentro_x(Posicion_x);
    Escudo_3->setCentro_y(Posicion_y);
    Escudo_4->setCentro_x(Posicion_x);
    Escudo_4->setCentro_y(Posicion_y);

    setPos(Posicion_x,Posicion_y);

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(BalaSimple) == typeid(*Elemento))
        {
            Vida-=150;
            Scene->removeItem(Elemento);
            ParametrosScene->BossFinal(150);
            delete Elemento;
            if(Vida<0)
            {
                Scene->removeItem(this);
                Scene->removeItem(Escudo_1);
                Scene->removeItem(Escudo_2);
                Scene->removeItem(Escudo_3);
                Scene->removeItem(Escudo_4);
                delete  Escudo_1;
                delete Escudo_2;
                delete  Escudo_3;
                delete Escudo_4;
                delete this;
            }
        }
    }
}
