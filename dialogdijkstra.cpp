#include "dialogdijkstra.h"
#include "ui_dialogdijkstra.h"

DialogDijkstra::DialogDijkstra(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogDijkstra)
{
    ui->setupUi(this);
}

DialogDijkstra::~DialogDijkstra()
{
    delete ui;
}


void DialogDijkstra::on_buttonBox_accepted()
{
    stadtname1 = ui->lineEdit_stadt1->text();
    stadtname2 = ui->lineEdit_stadt2->text();
}

QString DialogDijkstra::getStadtname1()
{
    return stadtname1;
}

QString DialogDijkstra::getStadtname2()
{
    return stadtname2;
}
