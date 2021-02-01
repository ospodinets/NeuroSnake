#include "stdafx.h"
#include "Obstacle.h"
#include "Map.h"
#include "PassMap.h"
#include "ObstacleView.h"
#include "Settings.h"

Obstacle::Obstacle( Map* map, QPoint const& currentMapPos )
    : MapObject( currentMapPos, std::make_shared<ObstacleView>( map->GetView() ), ObjectType::OBSTACLE )
{}

Obstacle::~Obstacle() {}

