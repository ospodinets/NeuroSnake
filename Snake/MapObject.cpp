#include "stdafx.h"
#include "MapObject.h"
#include "Settings.h"
#include "Map.h"
#include "PassMap.h"
#include "View.h"


MapObject::MapObject( QPoint const& currentMapPos, std::shared_ptr<View> view, ObjectType type )
    : currentMapPos_( currentMapPos )
    , view_( view )
    , type_( type )
{
    auto cellSize = Settings::instance()->getCellSize();
    currentPos_.setX( currentMapPos.x() * cellSize.width() );
    currentPos_.setY( currentMapPos.y() * cellSize.height() );
    view_->setPos( currentPos_ );
}

MapObject::~MapObject()
{}
