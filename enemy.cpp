#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
HP=maxHP;
}

void Enemy::attacked(int attackforce, int x, int y)

{
    qDebug()<<"Enemy was attacked";
HP=HP-attackforce + round (endurance/3);
qDebug()<<"enemy has "<<HP <<" HP left";

if (HP<0) {
    enemydied(x,y);
    HP=maxHP;}

}


