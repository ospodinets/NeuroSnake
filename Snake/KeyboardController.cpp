#include "stdafx.h"
#include "KeyboardController.h"


KeyboardController::KeyboardController() :
    direction_( Direction::STOPPED )
{
    qApp->installEventFilter( this );
}

KeyboardController::~KeyboardController() {}

Direction KeyboardController::getDirection()
{
    return direction_;
}

void KeyboardController::reset()
{
    direction_ = Direction::STOPPED;
}

bool KeyboardController::eventFilter( QObject* Object, QEvent* Event )
{
    if( Event->type() == QEvent::KeyPress )
    {
        QKeyEvent* KeyEvent = ( QKeyEvent* )Event;

        switch( KeyEvent->key() )
        {
            case Qt::Key_Left:
                if( direction_ != Direction::RIGHT )
                    direction_ = Direction::LEFT;
                break;
            case Qt::Key_Up:
                if( direction_ != Direction::BOTTOM )
                    direction_ = Direction::TOP;
                break;
            case Qt::Key_Right:
                if( direction_ != Direction::LEFT )
                    direction_ = Direction::RIGHT;
                break;
            case Qt::Key_Down:
                if( direction_ != Direction::TOP )
                    direction_ = Direction::BOTTOM;
                break;
            case Qt::Key_Space:
                direction_ = Direction::STOPPED;
                break;
            case Qt::Key_Escape:                
                break;
            default:
                break;
        }
        return true;
    }
    return false;
}
