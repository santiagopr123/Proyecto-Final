#include "fondosgame.h"

FondosGame::FondosGame (const QPixmap &pixmap, QGraphicsItem * parent): QGraphicsPixmapItem(pixmap, parent)
{

}

QPainterPath FondosGame::shape() const
{
    return QPainterPath();
}
