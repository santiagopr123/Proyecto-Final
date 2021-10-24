#ifndef VISTA_H
#define VISTA_H

#include <QGraphicsTextItem>

class Vista: public QGraphicsTextItem
{
private:

    double Salud_1,Salud_2;
    int PuntajeP;
    int Tiempo_Level_1;

    bool FlagTiempoLevel,FlagMultiplayer;


public:
    Vista(bool FlagMulti,QGraphicsItem * parent = 0);
    Vista(double Health, double Health2, int P, bool FlagMulti, QGraphicsItem * parent = 0);

    void decreaseHealthP1(double CantidadVP);
    void decreaseHealthP2(double CantidadVP);
    void IncreaseScore(int CantidadPP);
    void DecreaseTimeofsurvival();
};

#endif // VISTA_H
