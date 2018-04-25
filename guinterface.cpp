#include "guinterface.h"


GUInterface::GUInterface(QObject *parent) : QObject(parent), QGraphicsItem()
{

    figPix = new QPixmap(":/tiles/tiles.png"); // Загружаем изображение спрайта в QPixmap

}

QRectF GUInterface::boundingRect() const
{
    return QRectF(-160,-160,320,320);
}


void GUInterface::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* В отрисовщике графического объекта отрисовываем спрайт
     * Разберём все параметры данной функции
     * Первых два аргумента - это координаты, куда присваиваются верхнему левому углу QPixmap
     * Третий аргумент - это указатель на QPixmap
     * 4 и 5 аргументы - Координаты в В изображении QPixmap, откуда будет отображаться изображение
     * Задавая координаты, мы выбираем спрайт
     * и последние два аргумента - это ширина и высота  кадра
     *
     * */
    //ищем героя
    int x,y;
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
            if (x<10) { x = 10;}
            if (y<10) {y = 10;}
            if (x>40) {x = 40;}
            if (y>40) {y = 40;}


    for(int i = x-10; i < x+10; i++) {
        for(int j = y-10; j < y+10; j++) {
            int a = currentMapArray[i][j];

                    switch (a) {
                    case 1: //рисуем стены
                    painter->drawPixmap(16*(i-x),16*(j-y), *figPix, 96, 16, 16,16);
                    break;

                    case 20:
                         //Рисуем пикапы
                             painter->drawPixmap(16*(i-x),16*(j-y), *figPix,0, 144, 16,16);
                         break;
                    case 40:
                        //Рисуем врагов
                             painter->drawPixmap(16*(i-x),16*(j-y), *figPix,96, 96, 16,16);
                         break;

                    case 99: { //рисуем героя
                         painter->drawPixmap(16*(i-x),16*(j-y), *figPix, 0, 64, 16,16);
                         break;
                    case 11: {//risuem trup geroya
                             painter->drawPixmap(16*(i-x),16*(j-y), *figPix, 96,112,16,16);
                             break;}
                    }

                    default:
                   { painter->drawPixmap(16*(i-x),16*(j-y), *figPix, 16, 0, 16,16);

                    break;}
        }

        }

       // std::cout<<endl;
    }
  //  qDebug() << "Привет, я отрисовал элемент" << endl;

    Q_UNUSED(option);
    Q_UNUSED(widget);

}}
/*

void GUInterface::showMap(int* arr, int m, int n)
 {for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
    //    qDebug() << *(arr + i*n + j);
     //   std::cout<<*(arr + i*n + j);
        if (*(arr + i*n + j)=1) {
           figNum=6;
           this->update(16*i,16*j,16,16);
        }

    }
  //  qDebug() << endl;
  //  std::cout<<endl;
}}
*/

/*
void Figure::moveUp() {
    this->setY(this->y()-15.0);

    if(!scene()->collidingItems(this).isEmpty()){

    this->setY(this->y()+15.0);}
}

void Figure::moveDown() {
  this->setY(this->y()+15.0);
    if(!scene()->collidingItems(this).isEmpty()){
     this->setY(this->y()-15.0); }
}


void Figure::moveRight() {
    this->setX(this->x()+15.0);
      if(!scene()->collidingItems(this).isEmpty()){
       this->setX(this->x()-15.0); }
}


void Figure::moveLeft() {
    this->setX(this->x()-15.0);
      if(!scene()->collidingItems(this).isEmpty()){
       this->setX(this->x()+15.0); }
}

void Figure::rotateLeft(){
    int r = this->rotation();
    r=r-15;
    setRotation(r);
}

void Figure::rotateRight(){
    int r = this->rotation();
    r=r+15;
    setRotation(r);
}

void Figure::jump() {

}
*/
