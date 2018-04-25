#ifndef HERO_DIALOG_H
#define HERO_DIALOG_H

#include <QDialog>

namespace Ui {
class Hero_Dialog;
}

class Hero_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Hero_Dialog(QWidget *parent = 0);
    ~Hero_Dialog();

private:
    Ui::Hero_Dialog *ui;
};

#endif // HERO_DIALOG_H
