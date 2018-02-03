#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "roguelikemap.h"
#include "clinterface.h"
#include "guinterface.h"
#include "hero.h"
#include <QKeyEvent>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void takePickUp(int pickup);

private:
    Ui::Widget *ui;
    Hero *hero;
    GUInterface *gui;
    QGraphicsScene *scene;
    QTimer *timer;
private slots:
    void updateMap();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
