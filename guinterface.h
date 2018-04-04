#include <hero.h>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QDebug>


class GUInterface : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GUInterface(QObject *parent = 0);  
    int currentMapArray[50][50];


signals:

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void moveUpRight();
    void moveDownRight();
    void moveUpLeft();
    void moveDownLeft();
    void findHero();



private slots:

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *figPix;   // В данный объект QPixamp будет помещён спрайт

};
