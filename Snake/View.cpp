#include "stdafx.h"
#include "View.h"
#include "MapView.h"

View::View( MapView* mapView )
    : mapView_( mapView )
{
    mapView->scene()->addItem( this );
}

View::~View()
{
    
}
