#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QKeyEvent>
#include <QDebug>

class Enemy : public QObject
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent = 0);

signals:
    void attack(int attackforce);

public slots:
    void attacked(int attackforce);

private:
    int x,y;
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

#endif // ENEMY_H
