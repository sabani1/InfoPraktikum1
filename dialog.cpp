#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    name = ui->lineEdit_stadtname->text();
    x = ui->lineEdit_x->text();
    y = ui->lineEdit_y->text();

    qDebug()<< "Die folgenden Daten wurden eingegeben:";
    qDebug() << name;
    qDebug() << x;
    qDebug() << y;
}

QString Dialog::getName()
{
    return name;
}

QString Dialog::getX()
{
    return x;
}

QString Dialog::getY()
{
    return y;
}
