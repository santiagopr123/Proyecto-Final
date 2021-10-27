#include "vista.h"
#include <QFont>

Vista::Vista(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    VidaBoss = 2000;
    setPlainText(QString("SaludBoss: ")+ QString::number(VidaBoss));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

Vista::Vista(bool FlagMulti, QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    Salud_1 = 1000;
    Salud_2 = 1000;

    PuntajeP = 0;

    Tiempo_Level_1 = 90;

    FlagTiempoLevel = false;
    FlagMultiplayer = FlagMulti;

    if(FlagMultiplayer == true)
    {
        setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
    }
    else
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
    }
}

Vista::Vista(double Health, double Health2, int P, bool FlagMulti, QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    Salud_1 = Health;
    Salud_2 = Health2;
    PuntajeP = P;
    FlagTiempoLevel = true;
    FlagMultiplayer = FlagMulti;

    if(FlagMultiplayer == true)
    {
        setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
    }
    else
    {
        setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
    }

}

void Vista::decreaseHealthP1(double CantidadVP)
{
    Salud_1-=CantidadVP;
    if(FlagTiempoLevel == true)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP));
        }
        else
        {
             setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP));
        }
    }
    else if(FlagTiempoLevel == false)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }
        else
        {
            setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }

    }
}

void Vista::decreaseHealthP2(double CantidadVP)
{
    Salud_2-=CantidadVP;
    if(FlagTiempoLevel == true)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP));
        }
        else
        {
             setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP));
        }
    }
    else if(FlagTiempoLevel == false)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }
        else
        {
            setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }

    }
}

void Vista::IncreaseScore(int CantidadPP)
{

    PuntajeP+=CantidadPP;
    if(FlagTiempoLevel == true)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP));
        }
        else
        {
             setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP));
        }
    }
    else if(FlagTiempoLevel == false)
    {
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("SaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }
        else
        {
             setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }
    }
}

void Vista::DecreaseTimeofsurvival()
{
    if(Tiempo_Level_1 > 0)
    {
        Tiempo_Level_1-=1;
        if(FlagMultiplayer == true)
        {
            setPlainText(QString("SaludP1: ")+ QString::number(Salud_1)+QString("\nSaludP2: ")+ QString::number(Salud_2)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));
        }
        else
        {
            setPlainText(QString("Salud: ")+ QString::number(Salud_1)+"\nPuntaje: "+QString::number(PuntajeP)+"\nSobrevive: "+QString::number(Tiempo_Level_1));

        }
    }
    else
    {
        FlagTiempoLevel = true;
    }
}

void Vista::BossFinal(double CantidadVB)
{
    VidaBoss-=CantidadVB;
    setPlainText(QString("SaludBoss: ")+ QString::number(VidaBoss));

}
