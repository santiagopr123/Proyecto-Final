#ifndef VISTA_H
#define VISTA_H

#include <QGraphicsTextItem>

class Vista: public QGraphicsTextItem
{
private:

    double Salud;
    int PuntajeP;
    int Tiempo;


public:
    Vista(QGraphicsItem * parent = 0);

    void decreaseHealth(double CantidadVP);
    void IncreaseScore(int CantidadPP);
    void DecreaseTimeofsurvival();
};

#endif // VISTA_H
