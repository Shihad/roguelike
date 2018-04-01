#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
    HP=maxHP;
}

void Enemy::setXY(int newx, int newy)
{
    x= newx;
    y = newy;
}

void Enemy::attacked(int attackforce, int enemyx, int enemyy)
{ if ((enemyx==x) and (enemyy=y))
{
qDebug()<<"Enemy was attacked";
HP=HP-attackforce+  (endurance/3);
qDebug()<<"Enemy has " << HP << " left";
if (HP<=0) {
    enemyWasKilled(x,y);
    HP=maxHP;
}

int attackF;
if (luck>rand()%18) {
attackF = ((strength + agility)/2);
qDebug()<<"It's a critical hit! I was heavy wounded!";}
else {
    attackF = ((strength)/3);}
attack(attackF);



    qDebug()<<"Enemy was attacked";
HP=HP-attackforce + (endurance/3);
qDebug()<<"enemy has "<<HP <<" HP left";

if (HP<0) {
    enemydied(x,y);
   }

}}


