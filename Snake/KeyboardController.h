#pragma once
#include <QObject>
#include "Controller.h"
class KeyboardController :
    public QObject,
    public IController
{
    Q_OBJECT
public:
    KeyboardController();
    ~KeyboardController();

    Direction getDirection() override;
    void reset() override;

private:
    bool eventFilter( QObject* Object, QEvent* Event );
private:
    Direction direction_;
};

