#include "stdafx.h"
#include "SnakeWidget.h"
#include <QtWidgets/QApplication>

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );
    SnakeWidget w;
    w.show();
    return a.exec();
}
