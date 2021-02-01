#include "stdafx.h"
#include "Map.h"
#include "PassMap.h"
#include "Cell.h"
#include "CellView.h"
#include "Settings.h"

Cell::Cell( Map* map, QPoint const& currentMapPos, bool isHead )
    : MapObject( currentMapPos, std::make_shared<CellView>( map->GetView(), isHead ),
        isHead ? ObjectType::CELL_HEAD : ObjectType::CELL )
    , stepActive_( false )
    , map_ { map }
{
    targetMapPos_ = currentMapPos;
    targetPos_ = exactPos_ = currentPos_;
}

Cell::~Cell() {}

bool Cell::IsStepActive() const
{
    return stepActive_;
}

void Cell::StartStepTo( QPoint const& target )
{
    if( !stepActive_ )
    {
        assert( abs( target.x() - currentMapPos_.x() ) <= 1 ||
            abs( target.y() - currentMapPos_.y() ) <= 1 );

        auto thisPtr = shared_from_this();
        targetMapPos_ = target;
        auto cellSize = Settings::instance()->getCellSize();
        targetPos_.setX( target.x() * cellSize.width() );
        targetPos_.setY( target.y() * cellSize.height() );
        map_->GetPassMap()->Remove( currentMapPos_, thisPtr );
        map_->GetPassMap()->Add( targetMapPos_, thisPtr );

        stepActive_ = true;
    }
}

void Cell::Update( float dt )
{
    if( stepActive_ )
    {
        auto vel = Settings::instance()->getVelocity();
        QLineF target( 0.0, 0.0, ( targetPos_.x() - exactPos_.x() ),
            ( targetPos_.y() - exactPos_.y() ) );
        auto targetL = target.length();
        auto targetU = target.unitVector();
        QPointF newExactPos( exactPos_.x() + vel * targetU.x2() * dt, exactPos_.y() + vel * targetU.y2() * dt );
        QLineF actual( 0.0, 0.0, ( targetPos_.x() - newExactPos.x() ),
            ( targetPos_.y() - newExactPos.y() ) );
        auto actualL = actual.length();

        if( actualL > targetL )
        {
            auto cellSize = Settings::instance()->getCellSize();
            currentPos_ = exactPos_ = targetPos_;
            currentMapPos_ = targetMapPos_;
            stepActive_ = false;
        }
        else
        {
            exactPos_ = newExactPos;
        }
        view_->setPos( exactPos_ );
    }
}
