#pragma once

#include "MapObject.h"
#include <QPoint>

class Map;
class BonusView;

class Obstacle : public MapObject
{
    Q_OBJECT
public:
    Obstacle( Map* map, QPoint const& currentMapPos );
    ~Obstacle();

};

