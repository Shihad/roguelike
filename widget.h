#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "roguelikemap.h"
#include "clinterface.h"
#include "guinterface.h"
#include "hero.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);    Ui::Widget *ui;

    ~Widget();
public slots:
    void takePickUp(int pickup);
    void addtext(QString);


private:
   Hero *hero;
    GUInterface *gui;
    QGraphicsScene *scene;
    QTimer *timer;
    Enemy *enemy;
private slots:
    void updateMap();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
