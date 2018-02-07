#include "roguelikemap.h"
#include "ctime"

RoguelikeMap::RoguelikeMap(QObject *parent) : QObject(parent)
{
srand( time(0) );
}

void RoguelikeMap::generateRandomMap() {
    for (int i=0;i<50;i++) {
        mapArray[0][i]=1;
        mapArray[49][i]=1;
        mapArray[i][0]=1;
        mapArray[i][49]=1;


    }
    for (int i=1;i<49;i++) {
            for (int j=1;j<49;j++)
            {
                 mapArray[i][j]=rand()%4; //заполнение тела массива
            }
    }
}

void RoguelikeMap::returnMap() {
    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                currentMapArray[i][j]=mapArray[i][j]; //заполнение тела массива
            }
    }
}

void RoguelikeMap::placeHeroInRandomPlace() {
    for (int i=1;i<49;i++) {
            for (int j=1;j<49;j++)
            {
                 int a = rand()%10; //
                 if ((a==1) and(mapArray[i][j]!=1)) {
                     mapArray[i][j]=99;
                     return;
                 }
            }
}}


void RoguelikeMap::placePickUpInRandomPlace() {
    for (int i=1;i<49;i++) {
            for (int j=1;j<49;j++)
            {
                 int a = rand()%25; //
                 if ((a==1) and(mapArray[i][j]!=1)) {
                     mapArray[i][j]=20;


                 }
            }
}}


void RoguelikeMap::placeEnemyInRandomPlace() {
    for (int i=1;i<49;i++) {
            for (int j=1;j<49;j++)
            {
                 int a = rand()%25; //
                 if ((a==1) and(mapArray[i][j]!=1)) {
                     mapArray[i][j]=40;


                 }
            }
}}
