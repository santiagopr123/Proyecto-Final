#include "vista.h"
#include <QFont>

Vista::Vista(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    Salud = 1000;
    PuntajeP = 0;
    Tiempo = 45;
    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vista::decreaseHealth(double CantidadVP)
{
    Salud-=CantidadVP;
    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo));
}

void Vista::IncreaseScore(int CantidadPP)
{
    PuntajeP+=CantidadPP;
    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo));
}

void Vista::DecreaseTimeofsurvival()
{
    Tiempo-=1;
    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo));

}
