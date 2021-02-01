#include "stdafx.h"
#include "PassMap.h"
#include "MapObject.h"
#include "Settings.h"


PassMap::PassMap()
{
    auto mapSize = Settings::instance()->getMapSize();
    map_.resize( mapSize.width() * mapSize.height() );
}

PassMap::~PassMap() {}

void PassMap::Add( const QPoint& pos, std::shared_ptr<MapObject> object )
{
    auto mapSize = Settings::instance()->getMapSize();
    auto ptr = map_[ pos.x() + pos.y() * mapSize.width() ].lock();
    assert( !ptr );
    map_[ pos.x() + pos.y() * mapSize.width() ] = object;
}

void PassMap::Remove( const QPoint& pos, std::shared_ptr<MapObject> object )
{
    auto mapSize = Settings::instance()->getMapSize();
    auto ptr = map_[ pos.x() + pos.y() * mapSize.width() ].lock();
    assert( object == ptr );
    map_[ pos.x() + pos.y() * mapSize.width() ].reset();
}

std::shared_ptr<MapObject> PassMap::Get( QPoint const& pos )
{
    auto mapSize = Settings::instance()->getMapSize();
    if( pos.x() >= 0 && pos.y() >= 0 && pos.y() < mapSize.height() && pos.x() < mapSize.width() )
        return map_[ pos.x() + pos.y() * mapSize.width() ].lock();
    return nullptr;
}

std::vector<QPoint> PassMap::GetFreeCells() const
{
    std::vector<QPoint> free;
    auto mapSize = Settings::instance()->getMapSize();
    for( int y = 0; y < mapSize.height(); ++y )
    {
        for( int x = 0; x < mapSize.width(); ++x )
        {
            if( !map_[ x + y * mapSize.width() ].lock() )
                free.push_back( { x, y } );
        }
    }
    return free;
}