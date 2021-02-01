#include "stdafx.h"
#include "ObstacleView.h"
#include "MapView.h"
#include "Settings.h"

ObstacleView::ObstacleView( MapView* mapView )
    : View( mapView )
{}

ObstacleView::~ObstacleView() {}

QRectF ObstacleView::boundingRect() const
{
    auto size = Settings::instance()->getCellSize();
    return QRectF( -1, -1, size.width() + 1, size.height() + 1 );
}

void ObstacleView::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    QRectF rect = boundingRect();
    auto cellSize = Settings::instance()->getCellSize();
    painter->setPen( QColor::fromRgb( 0x196327 ) );
    painter->setBrush( QColor::fromRgb( 0x196327 ) );
    painter->drawRect( rect );
}
