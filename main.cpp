#include "mainwindow.h"
#include <QApplication>

#include <QString> //QString is wie std::string
#include <QDebug> //qDebug() ist wie std::cout

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
