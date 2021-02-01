#pragma once
#include <QObject>
#include <memory>

class Map;
class View;

enum class ObjectType
{
    OBSTACLE = -4,
    CELL = -3,
    CELL_NECK = -2,
    CELL_HEAD = -1,
    BONUS = 0,
    FREE = 1
};

class MapObject :
    public QObject,
    public std::enable_shared_from_this<MapObject>
{
public:
    MapObject( QPoint const& currentMapPos, std::shared_ptr<View> view, ObjectType type );
    ~MapObject();

    ObjectType GetType() const
    {
        return type_;
    }

    QPointF const& currentPos() const
    {
        return currentPos_;
    }

    QPoint const& currentMapPos() const
    {
        return currentMapPos_;
    }

protected:
    QPointF currentPos_;
    QPoint currentMapPos_;
    ObjectType type_;
    std::shared_ptr<View> view_;
};

