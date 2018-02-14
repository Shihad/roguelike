#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
HP=maxHP;
}

void Enemy::attacked(int attackforce, int x, int y)

{ qDebug()<<"Enemy was attacked";
HP=HP-attackforce+ round (endurance/3);
qDebug()<<"Enemy has " << HP << " left";
if (HP<=0) {
    enemyWasKilled(x,y);
    HP=maxHP;
}
int attackF;
if (luck>rand()%18) {
attackF = round((strength + agility)/2);
qDebug()<<"It's a critical hit! I was heavy wounded!";}
else {
    attackF = round((strength)/3);}
attack(attackF);


{
    qDebug()<<"Enemy was attacked";
HP=HP-attackforce + round (endurance/3);
qDebug()<<"enemy has "<<HP <<" HP left";

if (HP<0) {
    enemydied(x,y);
    HP=maxHP;}

}}

