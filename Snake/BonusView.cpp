#include "stdafx.h"
#include "BonusView.h"
#include "MapView.h"
#include "Settings.h"

BonusView::BonusView( MapView* mapView )
    : View( mapView )
{}

BonusView::~BonusView() {}

QRectF BonusView::boundingRect() const
{
    auto size = Settings::instance()->getCellSize();
    return QRectF( -1, -1, size.width() + 1, size.height() + 1 );
}

void BonusView::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    QRectF rect = boundingRect();
    auto cellSize = Settings::instance()->getCellSize();
    painter->setPen( Qt::black );
    painter->setBrush( Qt::red );

    QPointF center( cellSize.width() / 2, cellSize.height() / 2 );

    painter->drawEllipse( center, cellSize.width() / 2 - 1, cellSize.height() / 2 - 1 );
}
