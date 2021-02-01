#ifndef OBSTACLEVIEW_H
#define OBSTACLEVIEW_H

#include "View.h"

class MapView;

class ObstacleView : public View
{
public:
    ObstacleView( MapView* mapView );
    ~ObstacleView();

private:

    virtual QRectF boundingRect() const override;
    virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR ) override;
};

#endif // OBSTACLEVIEW_H
