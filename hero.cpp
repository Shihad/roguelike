#include "hero.h"
#include <QDebug>

Hero::Hero(QObject *parent) : QObject(parent)
{

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

