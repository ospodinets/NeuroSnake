#include "stdafx.h"
#include "Snake.h"
#include "Map.h"
#include "PassMap.h"
#include "Settings.h"
#include "Cell.h"
#include "Controller.h"
#include "KeyboardController.h"

#include "Bonus.h"

Snake::Snake( Map* map, int size, QPoint const& headIJ ) :
    map_( map )
    , running_ { false }
{
    auto cellS = Settings::instance()->getCellSize();
    auto cellPos = headIJ;
    for( int i = 0; i < size; ++i )
    {
        if( !map->GetPassMap()->Get( cellPos ) )
        {
            std::shared_ptr<Cell> cell( new Cell( map, cellPos, i == 0 ) );
            cells_.push_back( cell );
            map_->GetPassMap()->Add( cellPos, cell );
            ++cellPos.rx();
        }
        else
        {
            assert( 0 && "Impossible to place initial snake!" );
        }
    }
}

Snake::~Snake() {}

void Snake::Grow() {}

void Snake::Update( double dt )
{
    bool moving = false;
    
    for( auto& cell : cells_ )
    {
        cell->Update( dt );
        if( cell->IsStepActive() )
        {
            moving = true;
        }
    }

    if( running_ )
    {
        if( !moving )
        {
            HeadStepFinished();
        }   
    }
    else
    {
        if( map_->GetController()->getDirection() != Direction::STOPPED &&
            !moving )
        {
            StartNewStep();
            running_ = true;
        }
    }

}

QPoint Snake::HeadPos() const
{
    return cells_.front()->currentMapPos();
}

bool Snake::StartNewStep()
{
    auto mapSize = Settings::instance()->getMapSize();
    auto cellSize = Settings::instance()->getCellSize();
    auto headPos = HeadPos();
    auto nextPos = headPos;
    switch( map_->GetController()->getDirection() )
    {
        case Direction::LEFT:
            --nextPos.rx();
            break;
        case Direction::TOP:
            --nextPos.ry();
            break;
        case Direction::RIGHT:
            ++nextPos.rx();
            break;
        case Direction::BOTTOM:
            ++nextPos.ry();
            break;
        case Direction::STOPPED:
            running_ = false;
            break;
    }

    auto pm = map_->GetPassMap()->Get( nextPos );


    if( !pm || pm->GetType() == ObjectType::BONUS )
    {
        if( pm && pm->GetType() == ObjectType::BONUS )
        {
            auto bonus = static_cast< Bonus* >( pm.get() );
            bonus->Eat();
            bonus = nullptr;
            pm.reset();

            grow_ = std::make_shared<Cell>( map_, cells_.back()->currentMapPos(), false );
        }

        for( auto& cell : cells_ )
        {
            cell->StartStepTo( nextPos );
            nextPos = cell->currentMapPos();
        }

        return true;
    }

    return false;
}

void Snake::HeadStepFinished()
{
    if( grow_ )
    {
        map_->GetPassMap()->Add( grow_->currentMapPos(), grow_ );
        cells_.push_back( grow_ );
        grow_.reset();
    }
    if( !StartNewStep() && running_ )
    {
        emit Failed();
    }
}