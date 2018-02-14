#include "hero.h"
#include <QDebug>
#include "roguelikemap.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
connect(this,SIGNAL(getPickUp(int)),this,SLOT(takePickUp(int)));
}


void Hero::findHero() {
    for (int i=1;i<49;i++) {
            for (int j=1;j<49;j++)
            {

                 if (currentMapArray[i][j]==99) {
                     x=i;
                     qDebug()<<x;
                     y=j;
                     qDebug()<<y;

                 }
            }
}}


void Hero::killEnemyInXY(int x, int y)
{
    currentMapArray[x][y]=0;
    qDebug()<<"enemy was killed";
}

void Hero::moveUp() {
    int attackForce = round((strength + agility)/2);
    int control = currentMapArray[x][y-1];
    switch (control) {
    case 1: //It's a wall, can't move
        qDebug()<<"I can't move";
        break;
    case 20: //It's a pickup
        getPickUp(control);
        qDebug()<<"It's a bottle of healing potion!";
        currentMapArray[x][y-1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y-1;
        break;
    case 40: //It's an enemy

        qDebug()<<"It's an enemy!";
        qDebug()<<"I hit him with my sword for " << attackForce << " HP";
        attack(attackForce,x,y-1);
        attacked(attackForce);
        break;

    default: //There isn't any obstacles, move
        currentMapArray[x][y-1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y-1;
        break;
    }

}

void Hero::moveDown() {
    int control = currentMapArray[x][y+1];
    switch (control) {
    case 1: //It's a wall, can't move
        qDebug()<<"I can't move";
        break;
    case 20: //It's a pickup
        getPickUp(control);
        qDebug()<<"It's a bottle of healing potion!";
        currentMapArray[x][y+1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y+1;
        break;
    default:
        currentMapArray[x][y+1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y+1;
        break;
    }
}



void Hero::moveRight()
{
   int control = currentMapArray[x+1][y];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x+1][y]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y;
       break;
   default:
       currentMapArray[x+1][y]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y;
       break;
   }
}



void Hero::moveLeft()
{
   int control = currentMapArray[x-1][y];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x-1][y]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y;
       break;
   default:
       currentMapArray[x-1][y]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y;
       break;
   }
}

void Hero::moveUpRight()

{
   int control = currentMapArray[x+1][y-1];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x+1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y-1;
       break;

   default:
       currentMapArray[x+1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y-1;
       break;
   }
}

void Hero::moveDownRight()

{
   int control = currentMapArray[x+1][y+1];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x+1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y+1;
       break;
   default:
       currentMapArray[x+1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y+1;
       break;
   }
}

void Hero::moveUpLeft()

{
   int control = currentMapArray[x-1][y-1];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x-1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y-1;
       break;
   default:
       currentMapArray[x-1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y-1;
       break;
   }
}

void Hero::moveDownLeft()
{
   int control = currentMapArray[x-1][y+1];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x-1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y+1;
       break;
   default:
       currentMapArray[x-1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y+1;
       break;
   }
}

void Hero::takePickUp(int pickup) {
    switch (pickup) {
    case 20:
        healingPotions++;
        break;
    default:
        break;
    }
}

void Hero::attacked(int attackforce)
{
    qDebug()<<"I was hit!";
    attackforce=attackforce-2;
    HP=HP-(attackforce+8/endurance);
      qDebug()<<"I lose "<<attackforce+8/endurance<<"hp! i have "<<HP<<"hp"<<endl;
      if(HP<=0){qDebug()<<"u have 0 HP"; currentMapArray[x][y]=11;
           currentMapArray[x+1][y+1]=1;
           currentMapArray[x+1][y-1]=1;
           currentMapArray[x-1][y+1]=1;
           currentMapArray[x-1][y+1]=1;
           currentMapArray[x+1][y+1]=1;
           currentMapArray[x-1][y-1]=1;
           currentMapArray[x][y+1]=1;
           currentMapArray[x][y-1]=1;
           currentMapArray[x+1][y]=1;
           currentMapArray[x-1][y]=1;

      }}

int Hero::getHealingPotions()
{
    return healingPotions;
}
