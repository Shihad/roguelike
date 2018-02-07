#include "enemy.h"

Enemy::Enemy(QObject *parent) : QObject(parent)
{
HP=maxHP;
}

void Enemy::attacked(int attackforce)
{ qDebug()<<"Enemy was attacked";
HP=HP-attackforce+ round (endurance/3);
}


void attacked(int attackforce);
