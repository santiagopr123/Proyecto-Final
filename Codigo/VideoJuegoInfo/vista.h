#ifndef VISTA_H
#define VISTA_H

#include <QGraphicsTextItem>

class Vista: public QGraphicsTextItem
{
private:

    double Salud;
    int PuntajeP;
    int Tiempo_Level_1;

    bool FlagTiempoLevel;


public:
    Vista(QGraphicsItem * parent = 0);
    Vista(double Health,int P,bool FlagAux,QGraphicsItem * parent = 0);

    void decreaseHealth(double CantidadVP);
    void IncreaseScore(int CantidadPP);
    void DecreaseTimeofsurvival();
};

#endif // VISTA_H
