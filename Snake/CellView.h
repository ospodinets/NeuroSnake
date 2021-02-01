#ifndef CELLVIEW_H
#define CELLVIEW_H

#include "View.h"

class MapView;

class CellView : public View
{
public:
    CellView( MapView* mapView, bool head );
    ~CellView();

private:

    virtual QRectF boundingRect() const override;
    virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR ) override;

private:
    bool head_;
};

#endif // CELLVIEW_H
