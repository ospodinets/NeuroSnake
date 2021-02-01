#include "stdafx.h"
#include "MapView.h"
#include "cellview.h"
#include "Settings.h"

MapView::MapView()
    : QGraphicsView( nullptr, nullptr )
{
    QGraphicsScene* scene = new QGraphicsScene();
    setScene( scene );
    auto mapSize = Settings::instance()->getMapSize();
    auto cellSize = Settings::instance()->getCellSize();
    scene->setSceneRect( 0, 0, mapSize.width() * cellSize.width(),
        mapSize.height() * cellSize.height() );
    
    setBackgroundBrush( QBrush( 0xA9CCC6 ) );
    setRenderHint( QPainter::Antialiasing );

    for( int i = 0; i < mapSize.width() + 1; ++i )
    {
        QLineF line( QPointF( i * cellSize.width(), 0 ),
            QPointF( i * cellSize.width(), mapSize.height() * cellSize.height() ) );
        scene->addLine( line );
    }

    for( int i = 0; i < mapSize.height() + 1; ++i )
    {
        QLineF line( QPointF( 0, i * cellSize.height() ),
            QPointF( mapSize.width() * cellSize.width(), i * cellSize.height() ) );
        scene->addLine( line );
    }

    setFixedSize( mapSize.width() * cellSize.width() + 5,
        mapSize.height() * cellSize.height() + 5 );
}

MapView::~MapView()
{

}
