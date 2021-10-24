#include "vista.h"
#include <QFont>

Vista::Vista(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    Salud = 1000;
    PuntajeP = 0;
    Tiempo_Level_1 = 90;
    FlagTiempoLevel = false;

    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

Vista::Vista(double Health, int P, bool FlagAux, QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    Salud = Health;
    PuntajeP = P;
    FlagTiempoLevel = FlagAux;

    setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vista::decreaseHealth(double CantidadVP)
{
    Salud-=CantidadVP;
    if(FlagTiempoLevel == true)
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP));
    }
    else
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
    }
}

void Vista::IncreaseScore(int CantidadPP)
{
    PuntajeP+=CantidadPP;
    if(FlagTiempoLevel == true)
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP));
    }
    else
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
    }

}

void Vista::DecreaseTimeofsurvival()
{
    if(Tiempo_Level_1 > 0)
    {
        Tiempo_Level_1-=1;
        setPlainText(QString("Salud: ")+ QString::number(Salud)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
    }
    else
    {
        FlagTiempoLevel = true;
    }
}
