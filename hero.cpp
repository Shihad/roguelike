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
    if (currentMapArray[x][y-1]!=1) {
        qDebug()<<currentMapArray[x][y-1];
        currentMapArray[x][y-1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y-1;
    }
}
void Hero::moveDown() {
    if (currentMapArray[x][y+1]!=1) {
        qDebug()<<currentMapArray[x][y+1];
        currentMapArray[x][y+1]=99;
        currentMapArray[x][y]=0;
        x=x;
        y=y+1;
    }
}


void Hero::moveRight() {


    if (currentMapArray[x+1][y]!=1) {
        currentMapArray[x+1][y]=99;
        currentMapArray[x][y]=0;
        x=x+1;
        y=y;
        qDebug()<<"hello, i moved right"<<endl;
    }
}


void Hero::moveLeft() {
    if (currentMapArray[x-1][y]!=1) {
        currentMapArray[x-1][y]=99;
        currentMapArray[x][y]=0;
        x=x-1;
        y=y;
    }
}

