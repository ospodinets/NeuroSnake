#include "stdafx.h"
#include "Map.h"
#include "MapView.h"
#include "PassMap.h"
#include "Bonus.h"
#include "Settings.h"
#include "Snake.h"
#include "KeyboardController.h"
#include "Obstacle.h"

#include <QElapsedTimer>

namespace
{
    QElapsedTimer lastTime;
}

Map::Map()
    : view_( new MapView() )
    , passMap_( new PassMap() )    
    , m_controller( std::make_shared<KeyboardController>() )
{
    auto timer = new QTimer( this );
    timer->setInterval( 10 );
    connect( timer, SIGNAL( timeout() ),
        this, SLOT( Tick() ) );
    timer->start();
    lastTime.restart();

    srand( QDateTime::currentDateTime().toMSecsSinceEpoch() );
    auto mapSize = Settings::instance()->getMapSize();
    for( int x = 0; x < mapSize.width(); ++x )
    {
        for( int y = 0; y < mapSize.height(); ++y )
        {
            if( x == 0 || x == mapSize.width() - 1 ||
                y == 0 || y == mapSize.height() - 1 )
            {
                QPoint p( x, y );
                auto obstacle = std::make_shared<Obstacle>( this, p );
                m_obstacles.push_back( obstacle );
                passMap_->Add( p, obstacle );
            }
        }
    }

    restart();
}

Map::~Map() {}

MapView* Map::GetView() const
{
    return view_.get();
}

PassMap* Map::GetPassMap() const
{
    return passMap_.get();
}

IController* Map::GetController() const
{
    return m_controller.get();
}

void Map::restart()
{
    const auto mapSize = Settings::instance()->getMapSize();
    const int L = 3;
    QPoint headPos( mapSize.width() / 2 - L / 2, mapSize.height() / 2 );
    snake_ = std::make_shared<Snake>( this, L, headPos );
    connect( snake_.get(), SIGNAL( Failed() ), this, SLOT( SnakeFailed() ) );
    AddBonus();
}

void Map::Tick()
{
    snake_->Update( lastTime.elapsed() / 1000.0 );
    view_->viewport()->update();
    lastTime.restart();
}

void Map::BonusEaten()
{
    if( !AddBonus() )
    {
        SnakeFailed();
    }
}

void Map::SnakeFailed()
{
    m_controller->reset();
    snake_ = nullptr;
    restart();
}

bool Map::AddBonus()
{
    auto free = passMap_->GetFreeCells();

    if( !free.empty() )
    {
        int i = rand() % free.size();
        auto cellSize = Settings::instance()->getCellSize();
        bonus_ = std::make_shared<Bonus>( this, free[ i ] );
        passMap_->Add( free[ i ], bonus_ );
        connect( bonus_.get(), SIGNAL( Eaten() ), this, SLOT( BonusEaten() ) );
        emit NewBonus( bonus_->currentMapPos() );
        return true;
    }
    return false;
}
