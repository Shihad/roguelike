#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
 //   CLInterface cli; //интерфейс командной строки
    RoguelikeMap map; //карта
    hero = new Hero; //герой
    map.generateRandomMap(); //заполняем карту случайными числами
    map.placeHeroInRandomPlace(); //размещаем героя в случайном месте
    map.returnMap(); //обновляем публичную карту currentMapArray

    for (int i=0;i<50;i++) {
            for (int j=0;j<50;j++)
            {
                hero->currentMapArray[i][j]=map.currentMapArray[i][j];
            }} //заполняем массив публичной карты героя публичной картой

    hero->findHero(); //обновляем x,y героя


   // cli.showMap(&map.currentMapArray[0][0],50,50);

    this->resize(900,900);
    this->setFixedSize(900,900);
    ui->graphicsView->resize(850,850); //изменили размер окна
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    timer->start(25);

    ui->graphicsView->setFocus(); //создали сцену
    gui = new GUInterface(); //создали графический объект

    connect(timer,SIGNAL(timeout()),scene,SLOT(update()));
    connect(gui,SIGNAL(moveRight()),hero,SLOT(moveRight()));
    connect(gui,SIGNAL(moveLeft()),hero,SLOT(moveLeft()));
    connect(gui,SIGNAL(moveUp()),hero,SLOT(moveUp()));
    connect(gui,SIGNAL(moveDown()),hero,SLOT(moveDown()));
    connect(gui,SIGNAL(moveUpRight()),hero,SLOT(moveUpRight()));
    connect(gui,SIGNAL(moveUpLeft()),hero,SLOT(moveUpLeft()));
    connect(gui,SIGNAL(moveDownLeft()),hero,SLOT(moveDownLeft()));
    connect(gui,SIGNAL(moveDownRight()),hero,SLOT(moveDownRight()));



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

void Widget::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if (key==Qt::Key_W){
        this->hero->moveUp();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_S){
        this->hero->moveDown();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_D){
        qDebug()<<"hello"<<endl;
        this->hero->moveRight();
        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
    }
    if (key==Qt::Key_A){
        qDebug()<<"hello"<<endl;
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
        qDebug()<<"hello"<<endl;
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
