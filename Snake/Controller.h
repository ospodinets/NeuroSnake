#pragma once

enum class Direction
{
    STOPPED, LEFT, TOP, RIGHT, BOTTOM
};

class IController
{
public:
    virtual Direction getDirection() = 0;
    virtual void reset() = 0;
};

