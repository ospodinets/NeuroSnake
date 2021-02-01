#ifndef SNAKE_H
#define SNAKE_H

#include <QtWidgets/QWidget>
#include "ui_SnakeWidget.h"

class Map;

class SnakeWidget : public QWidget
{
    Q_OBJECT

public:
    SnakeWidget( QWidget* parent = 0 );
    ~SnakeWidget();

private:
    void keyPressEvent( QKeyEvent* event ) override;

private:
    Ui::SnakeWidgetClass ui;

    std::shared_ptr<Map> map_;
};

#endif // SNAKE_H
