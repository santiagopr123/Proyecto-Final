#include "vista.h"
#include <QFont>

Vista::Vista(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    Salud = 1000;
    setPlainText(QString("vidas: ")+ QString::number(Salud));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vista::decrease(int CantidadVP)
{
    Salud-=CantidadVP;
    setPlainText(QString("vidas: ")+ QString::number(Salud));
}

int Vista::getvida()
{
    return Salud;
}
