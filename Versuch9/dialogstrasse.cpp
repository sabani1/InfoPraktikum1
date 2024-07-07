#include "dialogstrasse.h"
#include "ui_dialogstrasse.h"

DialogStrasse::DialogStrasse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogStrasse)
{
    ui->setupUi(this);
}

DialogStrasse::~DialogStrasse()
{
    delete ui;
}

void DialogStrasse::on_buttonBox_accepted()
{
    stadt1 = ui->lineEdit_stadt1->text();
    stadt2 = ui->lineEdit_stadt2->text();
}

QString DialogStrasse::getStadtname1()
{
    return stadt1;
}

QString DialogStrasse::getStadtname2()
{
    return stadt2;
}
