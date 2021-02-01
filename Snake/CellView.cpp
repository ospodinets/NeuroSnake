#include "stdafx.h"
#include "cellview.h"
#include "MapView.h"
#include "Settings.h"

CellView::CellView( MapView* mapView, bool head )
    : View( mapView )
    , head_ { head }
{}

CellView::~CellView()
{}

QRectF CellView::boundingRect() const
{
    auto size = Settings::instance()->getCellSize();
    return QRectF( -1, -1, size.width() + 1, size.height() + 1 );
}

void CellView::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    auto cellSize = Settings::instance()->getCellSize();
    painter->setPen( Qt::black );
    painter->setBrush( head_ ? Qt::yellow : Qt::blue );

    QPointF center( cellSize.width() / 2, cellSize.height() / 2 );
    painter->drawEllipse( center, cellSize.width() / 2 - 1, cellSize.height() / 2 - 1 );
}
