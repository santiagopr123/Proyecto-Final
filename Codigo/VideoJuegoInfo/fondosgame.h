#ifndef FONDOSGAME_H
#define FONDOSGAME_H

#include <QGraphicsPixmapItem>

class FondosGame: public QGraphicsPixmapItem
{
public:
    explicit FondosGame(const QPixmap &pixmap, QGraphicsItem *parent = 0);

public:
    virtual QPainterPath shape() const;
};

#endif // FONDOSGAME_H
