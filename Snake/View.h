#pragma once
#include "qgraphicsitem.h"

class MapView;

class View :
    public QGraphicsItem
{
public:
    View( MapView* mapView );
    ~View();

protected:
    MapView* mapView_;
};

