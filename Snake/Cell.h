#pragma once

#include "MapObject.h"
#include <QPoint>

class Map;
class CellView;

class Cell : public MapObject
{
    Q_OBJECT
public:
    Cell( Map* map, QPoint const& currentMapPos, bool isHead );
    ~Cell();

    QPointF const& targetPos() const
    {
        return targetPos_;
    }

    QPoint const& targetMapPos() const
    {
        return targetMapPos_;
    }

    bool IsStepActive() const;

    void StartStepTo( QPoint const& target );
    void Update( float dt );

private:
    QPointF targetPos_;
    QPoint targetMapPos_;
    QPointF exactPos_;
    bool stepActive_;
    Map* map_;
};

