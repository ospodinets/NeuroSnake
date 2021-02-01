#pragma once

#include <QSettings>

class Settings
{

    Settings();

public:
    ~Settings();

    static Settings* instance();

    QSizeF getCellSize();
    QSize getMapSize();
    double getVelocity();

private:
    QSettings settings_;
};

