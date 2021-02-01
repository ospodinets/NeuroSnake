#include "stdafx.h"
#include "Bonus.h"
#include "Map.h"
#include "PassMap.h"
#include "BonusView.h"
#include "Settings.h"

Bonus::Bonus( Map* map, QPoint const& currentMapPos )
    : MapObject( currentMapPos, std::make_shared<BonusView>( map->GetView() ), ObjectType::BONUS )
{}

Bonus::~Bonus() {}

void Bonus::Eat()
{
    view_->setVisible( false );
    emit Eaten();
}
