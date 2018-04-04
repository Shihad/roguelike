#include "hero.h"
#include <QDebug>
#include "roguelikemap.h"
#include "ui_widget.h"
#include "widget.h"

Hero::Hero(QObject *parent) : QObject(parent)
{maxHP=endurance*5;
    HP=maxHP;
    qDebug()<<"HitPoints -" <<HP<<" of "<< maxHP;

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
    qDebug()<<"Enemy was killed";
}

void Hero::moveUp() {
    sendHP(HP);

    int control = currentMapArray[x][y-1];

    switch (control) {
    case 1: //It's a wall, can't move
       // qDebug()<<"I can't move";

        sendText("I can't move");
        break;
    case 20: //It's a pickup
        getPickUp(control);
        qDebug()<<"It's a bottle of healing potion!";
        sendText("It's a bottle of healing potion!");
        currentMapArray[x][y-1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y-1;
        break;
    case 40: //It's an enemy
        foundEnemyAndAttackHim(x,y-1);
        break;

    default: //There isn't any obstacles, move
        currentMapArray[x][y-1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y-1;
        sendText("I moved to the north of a dungeon. It's cold here!");
        break;
    }

}

void Hero::moveDown() {
    sendHP(HP);

    int control = currentMapArray[x][y+1];
    switch (control) {
    case 1: //It's a wall, can't move
        qDebug()<<"I can't move";

        sendText("I can't move");
        break;
    case 20: //It's a pickup
        getPickUp(control);
        qDebug()<<"It's a bottle of healing potion!";
        currentMapArray[x][y+1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y+1;
        break;

    case 40: //It's an enemy
        foundEnemyAndAttackHim(x,y+1);

        break;
    default:
        currentMapArray[x][y+1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y+1;        
        sendText("I moved to the south of a dungeon. Well, a moss grew on a south side, right?");
        break;

    }
}



void Hero::moveRight()
{ sendHP(HP);
   int control = currentMapArray[x+1][y];
   switch (control) {
   case 1: //It's a wall, can't move
       qDebug()<<"I can't move";
       sendText("I can't move");
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
       currentMapArray[x+1][y]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y;
       break;

   case 40: //It's an enemy
       foundEnemyAndAttackHim(x+1,y);

       break;
   default:
       currentMapArray[x+1][y]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y;       
       sendText("I moved to the east of a dungeon. To another arabian night!");
       break;
   }
}



void Hero::moveLeft()
{ sendHP(HP);

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

   case 40: //It's an enemy
       foundEnemyAndAttackHim(x-1,y);

       break;
   default:
       currentMapArray[x-1][y]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y;       
       sendText("I moved to the west of a dungeon. Skeletons grin here is more gay");
       break;
   }
}

void Hero::moveUpRight()

{ sendHP(HP);

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

   case 40: //It's an enemy
       foundEnemyAndAttackHim(x+1,y-1);

       break;

   default:
       currentMapArray[x+1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y-1;
       sendText("I moved to nord-east. Polar-bear statues welcomes me");
       break;
   }
}

void Hero::moveDownRight()

{   sendHP(HP);
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

   case 40: //It's an enemy
       foundEnemyAndAttackHim(x+1,y+1);
       break;

   default:
       currentMapArray[x+1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x+1;
       y=y+1;
       sendText("I moved to the south-east of a dungeon. The more penguins the better");
       break;
   }
}

void Hero::moveUpLeft()

{sendHP(HP);

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

   case 40: //It's an enemy

       foundEnemyAndAttackHim(x-1,y-1);

       break;
   default:
       currentMapArray[x-1][y-1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y-1;
       sendText("I moved to the nord-east of a dungeon. God, save us from normans rage!");
       break;
   }
}

void Hero::moveDownLeft()
{sendHP(HP);

   int control = currentMapArray[x-1][y+1];
   switch (control) {
   case 1: //It's a wall, can't move
         sendText("I can`t move");
       qDebug()<<"I can't move";
       break;
   case 20: //It's a pickup
       getPickUp(control);
       qDebug()<<"It's a bottle of healing potion!";
     sendText("It's a bottle of healing potion!");
       currentMapArray[x-1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y+1;       
       sendText("I moved to the south-west of a dungeon. I hate the gooks");
       break;

   case 40: //It's an enemy

       foundEnemyAndAttackHim(x-1,y+1);

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

{sendText("I was hit!");

{

    if (attackforce>(endurance/3)) {
    HP=HP-attackforce;

    qDebug()<<"I was hit!";
    sendText("I was hit! It hurts!");
    QString str;
    str.setNum(attackforce);
    str.prepend("I've lost ");
    str.append(" hitpoints!");
    sendText(str);
    str.setNum(HP);
    str.prepend("I have ");
    str.append(" HP left!");
    sendText(str);

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

    sendHP(HP);
    }

}  else  sendText("Enemy was missed!");

      }}

int Hero::getHealingPotions()
{
    return healingPotions;
}


int Hero::drinkPotions()
{  
    if (healingPotions>0)
    {
        healingPotions--;
        HP=HP+5;
        qDebug()<<"I drink potion!";
    }
    return healingPotions;
}

int Hero::setHeroAttackForce()
{   int attackForce;
    if (luck>rand()%12) {
    attackForce = ((strength + agility)/2);
    qDebug()<<"It's a marvellous hit!";
    sendText("It's a marvellous hit!");}
    else {
        attackForce = ((strength)/3);}
    return attackForce;

}

void Hero::foundEnemyAndAttackHim(int enemyx, int enemyy)
{   int attackForce;
    QString str;
    // qDebug()<<"It's an enemy!";
     sendText("It's an enemy!");
     attackForce=setHeroAttackForce();
   //  qDebug()<<"I hit him with my sword for " << attackForce << " HP";
     str.setNum(attackForce);
     str.prepend("I hit him with my sword for ");
     str.append(" HP");
     sendText(str);
     attack(attackForce,enemyx,enemyy);
}
