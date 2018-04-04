#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "hero.h"
#include <string>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
 //   CLInterface cli; //интерфейс командной строки
    map = new RoguelikeMap ; //карта
    hero = new Hero; //герой

    enemy = new Enemy; //враг

    map->generateRandomMap(); //заполняем карту случайными числами
    map->placeHeroInRandomPlace(); //размещаем героя в случайном месте
    map->placePickUpInRandomPlace();//размещаем пикапы на карте
    map->placeEnemyInRandomPlace(); //размещаем на карте врагов
    map->returnMap(); //обновляем публичную карту currentMapArray
    saveFile = new QFile("Save_File.dat");


    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                hero->currentMapArray[i][j]=map->currentMapArray[i][j];
            }} //заполняем массив публичной карты героя публичной картой

    hero->findHero(); //обновляем x,y героя


   // cli.showMap(&map.currentMapArray[0][0],50,50);

    this->resize(1900,900);
    this->setFixedSize(1900,900);
    ui->graphicsView->resize(850,850); //изменили размер окна
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    timer->start(25);

    ui->graphicsView->setFocus(); //создали сцену
    gui = new GUInterface(); //создали графический объект

    makeAllConnected();


   // connect(hero,SIGNAL(getPickUp(int,int,int)),this,SLOT(takePickUp(int,int,int))); //подбираем пикапы

 //   connect(enemy,SIGNAL(enemydied(int,int)),hero,SLOT(killEnemyInXY(int,int)));//убийство врага







    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
            }
    }

        scene->addItem(gui);






}

Widget::~Widget()
{
    delete ui;
}
//обработка нажатий клавиш
void Widget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    if (key==Qt::Key_P)
    {
        int num = hero->drinkPotions();
        QString nums;
            nums.setNum(num);
            ui->label_2->setText(nums);
            ui->textBrowser->append("I drink a healing potion. Taste like chicken");

    }
    if (key==Qt::Key_W){
        this->hero->moveUp();

        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_S)
{

        this->hero->moveDown();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }

    }
    if (key==Qt::Key_D){
        this->hero->moveRight();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_A){
        this->hero->moveLeft();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_E){
        this->hero->moveUpRight();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_C){       
        this->hero->moveDownRight();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_Q){
        this->hero->moveUpLeft();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_Z){
        qDebug()<<"hello"<<endl;
        this->hero->moveDownLeft();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
}

void Widget::addtext(QString text)
{
ui->textBrowser->append(text);
}

void Widget::updateMap() {

    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
            }
    }
    gui->update(-80,-80,160,160);
    scene->update(0.0,0.0,850.0,850.0);
    ui->graphicsView->update();


}


void Widget::takePickUp(int pickup) {

    switch (pickup) {

    case 20:
        int num = hero->getHealingPotions();
        QString nums;
        nums.setNum(num);
        ui->label_2->setText(nums);

        break;

  //default:
  //     break;
    }
}
/*
void Widget::on_pushButton_clicked()
{

}*/

void Widget::updateHP(int HP)
{
    QString nums;
    nums.setNum(HP);
    ui->label_4->setText(nums);
}


void Widget::attack_text()
{
    ui->textBrowser->append("<font color = red>Враг атаковал вас!</font color>");
}

void Widget::makeAllConnected()
{
    //отрисовка сцены

    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(hero,SIGNAL(sendHP(int)),this,SLOT(updateHP(int)));

    //движение

    connect(gui,SIGNAL(moveRight()),hero,SLOT(moveRight()));
    connect(gui,SIGNAL(moveLeft()),hero,SLOT(moveLeft()));
    connect(gui,SIGNAL(moveUp()),hero,SLOT(moveUp()));
    connect(gui,SIGNAL(moveDown()),hero,SLOT(moveDown()));
    connect(gui,SIGNAL(moveUpRight()),hero,SLOT(moveUpRight()));
    connect(gui,SIGNAL(moveUpLeft()),hero,SLOT(moveUpLeft()));
    connect(gui,SIGNAL(moveDownLeft()),hero,SLOT(moveDownLeft()));
    connect(gui,SIGNAL(moveDownRight()),hero,SLOT(moveDownRight()));


    connect(hero,SIGNAL(sendText(QString)),this,SLOT(addtext(QString)));   //сообщения

    connect(hero,SIGNAL(getPickUp(int)),this,SLOT(takePickUp(int))); //подбираем пикапы
    foreach (enemy, map->enemies) {
         connect(hero,SIGNAL(attack(int,int,int)),enemy,SLOT(attacked(int,int,int))); //атака на врага
         connect(enemy,SIGNAL(attack(int)),hero,SLOT(attacked(int)));
         connect(enemy,SIGNAL(enemyWasKilled(int,int)),hero,SLOT(killEnemyInXY(int,int)));
    }


   // connect(enemy,SIGNAL(attack(int)),this,SLOT(attack_text()));


    connect(gui,SIGNAL(moveUpRight()),hero,SLOT(moveUpRight()));
    connect(gui,SIGNAL(moveUpLeft()),hero,SLOT(moveUpLeft()));
    connect(gui,SIGNAL(moveDownLeft()),hero,SLOT(moveDownLeft()));
    connect(gui,SIGNAL(moveDownRight()),hero,SLOT(moveDownRight()));
}


void Widget::on_save_clicked()
{
char buf[60];
    saveFile->open(QIODevice::Append);
    for (int x = 0;x<50;x++)
    {
      for (int y = 0;y<50;y++)

      {

           buf[y] =(48+ gui->currentMapArray[x][y]);

      }
      saveFile->write(buf);
      saveFile->write("\n");
    }
saveFile->close();
ui->save->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{

}
