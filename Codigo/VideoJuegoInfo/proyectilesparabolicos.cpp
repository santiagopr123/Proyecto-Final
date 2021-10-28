#include "proyectilesparabolicos.h"

ProyectilesParabolicos::ProyectilesParabolicos(double x, double y, double v, double a, QGraphicsScene *Scene_Aux)
{
    //se recibe las posiciones iniciales, ademas de esto la velocidad y angulon que adquiere el objeto. Tmbien un puntero a la escena
    //del Qmainwindow o la clase ventanap
    posicion_x = x;
    posicion_y = y;
    velocidad_inicial = v;
    angulo = (a*3.14159)/180;

    Scenes = Scene_Aux;
    setPos(posicion_x,posicion_y);

    //se crea un QTimer y se le asigna un slot para el movimiento
    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

ProyectilesParabolicos::~ProyectilesParabolicos()
{
    delete timer;
}

QRectF ProyectilesParabolicos::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void ProyectilesParabolicos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/Proyectiles.png");
    painter->drawPixmap(-radio,-radio, 2*radio, 2*radio,pixmap);
    setScale(2);
}

void ProyectilesParabolicos::actualizarposicion()
{

    //Ademas de ser la funcion que se llama en el slots move
    //tambien se gestiona las collisiones del objeto
    calcularvelocidad();
    posicion_x = posicion_x+velocidad_x*delta;
    posicion_y = posicion_y+(velocidad_y*delta)+(0.5*gravedad*delta*delta);
    setPos(posicion_x,posicion_y);

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i)
    {
        QGraphicsItem *Elemento = colliding_items[i];
        if(typeid(ProyectilesParabolicos) == typeid (*Elemento))
        {
            Scenes->removeItem(this);
            Scenes->removeItem(Elemento);
            delete this;
            delete Elemento;
        }
    }

    if(this->pos().y() > 440 || this->pos().y() < -5 || this->pos().x()>1110 || this->pos().x()<0)
    {
        Scenes->removeItem(this);
        delete this;
    }
}

void ProyectilesParabolicos::calcularvelocidad()
{
    //Ecuaciones del moviemiento parabolico
    velocidad_x = velocidad_inicial*cos(angulo);
    velocidad_y = velocidad_inicial*sin(angulo)+gravedad*delta;
    angulo = atan2(velocidad_y,velocidad_x);
    velocidad_inicial = sqrt((velocidad_x*velocidad_x)+(velocidad_y*velocidad_y));
}

void ProyectilesParabolicos::move()
{
    //slot que llama una funcion que contiene las formulas del movimiento parabolico
    actualizarposicion();
}
