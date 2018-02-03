#include "hero.h"
#include <QDebug>

Hero::Hero(QObject *parent) : QObject(parent)
{

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

void Hero::moveUp() {
    int control = currentMapArray[x][y-1];
    switch (control) {
    case 1: //It's a wall, can't move
        qDebug()<<"I can't move";
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
    case 1:
        qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
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
   case 1:
       qDebug()<<"I can't move";
       break;
   default:
       currentMapArray[x-1][y+1]=99;
       currentMapArray[x][y]=0;
       x=x-1;
       y=y+1;
       break;
   }
}
