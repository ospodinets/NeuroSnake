#ifndef BONUSVIEW_H
#define BONUSVIEW_H

#include "View.h"

class MapView;

class BonusView : public View
{
public:
    BonusView( MapView* mapView );
    ~BonusView();

private:

    virtual QRectF boundingRect() const override;
    virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR ) override;
};

#endif // BONUSVIEW_H
