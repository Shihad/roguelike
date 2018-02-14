#include "hero.h"
#include <QDebug>
#include "roguelikemap.h"

Hero::Hero(QObject *parent) : QObject(parent)
{
connect(this,SIGNAL(getPickUp(int)),this,SLOT(takePickUp(int)));
}
void Hero::getDamage()
{
  int hero_hp=100,rnd_luck,enemy_dmg=5;
  srand(time(0));
    rnd_luck=rand()%(luck*luck-(luck/luck+4));

enemy_dmg=enemy_dmg/((strength+endurance+agility+rnd_luck)/10);
HP=HP-enemy_dmg;
qDebug()<<rnd_luck<<"enemy deal on u "<<enemy_dmg<<endl;
qDebug()<<"u have "<< HP<<" helth points"<<endl;
//if (HP<=0){qDebug<<"u soon dead, u run away"<<endl;//здесь надо смерть или побег от монстра}
}

void Hero::atack()
{
int enemy_hp,rnd_luck,dmg_hero;
enemy_hp=100;//брать из класса врага
srand(time(0));
rnd_luck=rand()%luck;
dmg_hero=dmg+rnd_luck+strength*0.5+endurance*0.3+agility*0.4;
enemy_hp=enemy_hp-dmg_hero;
qDebug()<<"u deal on enemy "<<dmg_hero<<endl;
qDebug()<<"enemy have "<< enemy_hp<<" helth points"<<endl;
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
}

int Hero::getHealingPotions() {
    return healingPotions;
}
