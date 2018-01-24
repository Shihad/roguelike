#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CLInterface cli;
    RoguelikeMap map;
    Hero hero;
    map.generateRandomMap();
    map.placeHeroInRandomPlace();
    map.returnMap();

    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                hero.currentMapArray[i][j]=map.currentMapArray[i][j];
            }}

    hero.findHero();


   // cli.showMap(&map.currentMapArray[0][0],50,50);

    this->resize(900,900);
    this->setFixedSize(900,900);
    ui->graphicsView->resize(850,850);


    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFocus();
    gui = new GUInterface();


   // hero.moveUp();
   //s hero.moveRight();
   // hero.moveUp();
    hero.findHero();

    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                gui->currentMapArray[i][j]=hero.currentMapArray[i][j];
            }
    }

        scene->addItem(gui);




}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if (key==Qt::Key_W){
      hero->moveUp();

    }
    else if (key==Qt::Key_S){

    }
}
