#ifndef HERO_H
#define HERO_H
#include <QObject>
#include <QKeyEvent>


class Hero : public QObject
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = 0);

    int currentMapArray[50][50];
    int getHealingPotions();

public slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void lvlUp(int apr);


    void moveUpRight();
    void moveDownRight();
    void moveUpLeft();
    void moveDownLeft();
  //  void setPos(int x, int y);
    void findHero();


signals:
    void getPickUp(int pickup);    
    void attack(int attackforce, int x, int y);


public slots:
    void takePickUp (int pickup);
    void attacked(int attackforce);
    void killEnemyInXY(int x, int y);

private:
    int exp=0;
    int lvlexp=10;
    int x,y,alive;
    int strength=5;
    int perception=5;
    int endurance=5;
    int charisma=5;
    int intellect=5;
    int agility=5;
    int luck=5;
    int healingPotions =0;
    int maxHP;
    int HP;
};

#endif // HERO_H
