#pragma once

#include <QObject>

class MapView;
class PassMap;
class Snake;
class Bonus;
class IController;
class Obstacle;

class Map : public QObject
{
    Q_OBJECT
public:
    Map();
    ~Map();

    MapView* GetView() const;
    PassMap* GetPassMap() const;
    IController* GetController() const;

    void restart();

private slots:
    void Tick();
    void BonusEaten();
    void SnakeFailed();

private:
    bool AddBonus();

signals:
    void NewBonus( QPoint pos );

private:
    std::shared_ptr<MapView> view_;
    std::shared_ptr<PassMap> passMap_;
    std::shared_ptr<Snake> snake_;
    std::shared_ptr<Bonus> bonus_;
    std::shared_ptr<IController> m_controller;
    std::vector<std::shared_ptr<Obstacle>> m_obstacles;
};

