#include "enemigoamortiguado.h"

EnemigoAmortiguado::EnemigoAmortiguado(int Pos_x, int LongN, int Mass)
{
    //se inicilizan variables y constantes, ademas de que se reciben una masa, y posicion para el objeto
    constante_amortiguamiento = 0.1;
    Aceleracion_Gravedad = 9.8;
    Longitud_Natural = LongN;
    Euler = 2.71828182846;
    Posicion_x = Pos_x;
    Estiramiento = 10;
    Posicion_y = 0;
    Amplitud = 200;
    Masa = Mass;
    tiempo = 0;
    radio = 12;

    constante_elastica = 30;

    Frecuencia_Angular_amortiguada = sqrt((constante_elastica/Masa)-(pow(constante_amortiguamiento,2)/4*pow(Masa,2)));

    Exponencial = pow(Euler,(-constante_amortiguamiento*tiempo)/(2*Masa));

    Posicion_y = Amplitud*Exponencial*cos((Frecuencia_Angular_amortiguada*tiempo));

    Amplitud_RespectoT = Amplitud*Exponencial;

    setPos(Posicion_x,Posicion_y+Longitud_Natural);

    Timer = new QTimer();
    connect(Timer,SIGNAL(timeout()),this,SLOT(move()));
    Timer->start(50);
}

EnemigoAmortiguado::~EnemigoAmortiguado()
{
    delete  Timer;
}

void EnemigoAmortiguado::calcular_variables()
{
    tiempo+=0.1;
    Exponencial = pow(2.71828182846,(-constante_amortiguamiento*tiempo)/(2*Masa));
}

void EnemigoAmortiguado::actualizar_posicion()
{
    //se calculan diversas variables respecto al tiempo para el movieminto no permetuo del oscilamiento
    calcular_variables();
    Posicion_y = Amplitud*Exponencial*cos((Frecuencia_Angular_amortiguada*tiempo));
    Amplitud_RespectoT = Amplitud*Exponencial;
    setPos(Posicion_x,Posicion_y+Longitud_Natural);
}

QRectF EnemigoAmortiguado::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void EnemigoAmortiguado::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/Imagenes/Amortiguacionenemy.png");
    painter->drawPixmap(-radio,-radio, 2*radio, 2*radio,pixmap);
    setScale(1.7);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void EnemigoAmortiguado::move()
{
    //se llamda la clase actualizar posicion
    actualizar_posicion();
}
