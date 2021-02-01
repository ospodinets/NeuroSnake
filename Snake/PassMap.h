#pragma once

class MapObject;
class Obstacle;
class Map;

#include <memory>
#include <vector>

class PassMap
{
public:

    PassMap();
    ~PassMap();

    void Add( const QPoint& pos, std::shared_ptr<MapObject> object );
    void Remove( const QPoint& pos, std::shared_ptr<MapObject> object );
    std::shared_ptr<MapObject> Get( QPoint const& pos );
    std::vector<QPoint> GetFreeCells() const;
    
private:
    std::vector<std::weak_ptr<MapObject>> map_;

};

