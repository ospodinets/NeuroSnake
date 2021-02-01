#include "stdafx.h"
#include "SnakeWidget.h"
#include "Map.h"
#include "MapView.h"
#include "Settings.h"

SnakeWidget::SnakeWidget( QWidget* parent )
    : QWidget( parent )
    , map_( new Map() )
{
    ui.setupUi( this );
    QVBoxLayout* vl = new QVBoxLayout( this );
    vl->setContentsMargins( 0, 0, 0, 0 );
    layout()->addWidget( map_->GetView() );
    setFixedSize( map_->GetView()->size() );
}

SnakeWidget::~SnakeWidget()
{}

void SnakeWidget::keyPressEvent( QKeyEvent* event )
{
    if( event->key() == Qt::Key_Escape )
        map_->restart();

}

