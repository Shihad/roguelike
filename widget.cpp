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
    ui->graphicsView->setFocus(); //создали сцену
    gui = new GUInterface(); //создали графический объект
    connect(gui,SIGNAL(moveRight()),hero,SLOT(moveRight()));



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
        qDebug()<<"hello"<<endl;
        this->gui->moveRight();

        for (int i=0;i<50;i++) {
                for (int j=0;j<50;j++)
                {
                    qDebug()<<"h"<<i<<j;
                   gui->currentMapArray[i][j]=hero->currentMapArray[i][j];
                }
        }
        hero->findHero();
        gui->update(0,0,850,850);

    }
}
