#pragma once

#include "MapObject.h"
#include <QPoint>

class Map;
class BonusView;

class Bonus : public MapObject
{
    Q_OBJECT
public:
    Bonus( Map* map, QPoint const& currentMapPos );
    ~Bonus();

    void Eat();

signals:
    void Eaten();
};

