#ifndef VISTA_H
#define VISTA_H

#include <QGraphicsTextItem>

class Vista: public QGraphicsTextItem
{
private:

    double Salud;

public:
    Vista(QGraphicsItem * parent = 0);

    void decrease(int CantidadVP);
    int getvida();
};

#endif // VISTA_H
