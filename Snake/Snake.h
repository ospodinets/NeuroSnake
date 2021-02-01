#pragma once

#include <QObject>
#include <list>

class Cell;
class Map;
struct IController;

class Snake : public QObject
{
    Q_OBJECT

public:
    Snake( Map* map, int size, QPoint const& headIJ );
    ~Snake();

    Map* GetMap() const
    {
        return map_;
    }

    void Grow();
    void Update( double dt );
    QPoint HeadPos() const;

private slots:
    void HeadStepFinished();

private:
    bool StartNewStep();

signals:
    void Failed();

private:
    std::list<std::shared_ptr<Cell>> cells_;
    std::shared_ptr<Cell> grow_;
    Map* map_; 
    bool running_;
};

