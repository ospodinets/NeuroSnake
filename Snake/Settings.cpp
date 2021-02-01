#include "stdafx.h"
#include "Settings.h"

namespace
{
    QSizeF cellSize( 20, 20 );
    QSize mapSize( 30, 16 );
    double velocity = 100.0;
}

Settings::Settings()
    : settings_( "./settings.ini", QSettings::IniFormat )
{
    settings_.sync();
    cellSize = settings_.value( "cellSize", cellSize ).toSizeF();
    mapSize = settings_.value( "mapSize", mapSize ).toSize();
    velocity = settings_.value( "velocity", velocity ).toReal();
}

Settings::~Settings() {}

Settings* Settings::instance()
{
    static auto inst = new Settings;
    return inst;
}

QSizeF Settings::getCellSize()
{
    return cellSize;
}

QSize Settings::getMapSize()
{
    return mapSize;
}


double Settings::getVelocity()
{
    return velocity;
}