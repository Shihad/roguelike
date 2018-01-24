#ifndef HERO_H
#define HERO_H
#include <QObject>
#include <QKeyEvent>


class Hero : public QObject
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = 0);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setPos(int x, int y);
    void findHero();
    int currentMapArray[50][50];

signals:


public slots:

private:
    int x,y;
    int strength=5;
    int perception=5;
    int endurance=5;
    int charisma=5;
    int intellect=5;
    int agility=5;
    int luck=5;
};

#endif // HERO_H
