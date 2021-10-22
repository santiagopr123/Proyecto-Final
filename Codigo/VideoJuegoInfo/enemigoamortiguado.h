#ifndef ENEMIGOAMORTIGUADO_H
#define ENEMIGOAMORTIGUADO_H

#include <QObject>
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <qdebug.h>
#include <QTimer>
#include <QPixmap>

class EnemigoAmortiguado:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:

    double Masa;
    double Estiramiento;
    double Amplitud;
    double Amplitud_RespectoT;
    double constante_elastica;
    double Frecuencia_Angular_amortiguada;
    double Exponencial;
    double Posicion_x;
    double Posicion_y;
    double tiempo;
    double Euler;
    double Aceleracion_Gravedad;
    double constante_amortiguamiento;

    int radio;
    int Longitud_Natural;

    QTimer *Timer;
public:
    EnemigoAmortiguado(int Pos_x,int LongN,int Mass);
    ~EnemigoAmortiguado();

    void calcular_variables();
    void actualizar_posicion();

    QRectF boundingRect() const;//Para el color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:
    void move();
};

#endif // ENEMIGOAMORTIGUADO_H
