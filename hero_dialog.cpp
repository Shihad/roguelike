#include "hero_dialog.h"
#include "ui_hero_dialog.h"

Hero_Dialog::Hero_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hero_Dialog)
{
    ui->setupUi(this);
}

Hero_Dialog::~Hero_Dialog()
{
    delete ui;
}
