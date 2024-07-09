#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "dialog.h."
#include "dialogdijkstra.h"
#include "dialogstrasse.h"
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    mapio = new MapIoNrw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug() << "Der Knopf wurde geklickt";

    QString eingabe;
    int inteingabe;
    bool ok;
    QMessageBox msgBox;

    eingabe = ui->lineEdit_teste_was->text();
    inteingabe = eingabe.toInt(&ok);

    if (!ok)
    {
        eingabe = QString("Der folgende Text wurde eingegeben: %1").arg(eingabe);
        qDebug() << eingabe;
        msgBox.setText(eingabe);
        msgBox.exec();
    }
    else
    {
        qDebug() << "Die Zahl (+4) ergibt: " << inteingabe +4;
        QString a = QString::number(inteingabe+4);
        a = QString("Die Zahl (+4) ergibt: %1").arg(a);
        msgBox.setText(a);
        msgBox.exec();
    }

    int x = QRandomGenerator::global()->bounded(300);
    int y = QRandomGenerator::global()->bounded(300);
    scene.addRect(x, y, 8, 8, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgAbout;
    msgAbout.about(this, "About", "Das ist Versuch 9");
}


void MainWindow::on_pushButton_test_draw_city_clicked()
{
    scene.clear();
    map.clear();
    City aachen = City("Aachen", -40, 0);
    City koeln = City("Köln", 40, 0);
    map.addCity(&aachen);
    map.addCity(&koeln);
    map.draw(scene);
}


void MainWindow::on_pushButton_clicked()
{
    scene.clear();
    map.clear();

    City c1("city c1", 20,50);
    map.addCity(&c1);
    map.draw(scene);
}


void MainWindow::on_pushButton_test_street_clicked()
{
    City aachen = City("Aachen", -40, 0);
    City koeln = City("Köln", 40, 0);
    Street street1 = Street(&aachen, &koeln);
    map.addStreet(&street1);
    map.draw(scene);
}


void MainWindow::on_checkBox_testknoepfe_clicked()
{
    if(ui->checkBox_testknoepfe->isChecked())
    {
        ui->pushButton->hide();
        ui->pushButton_test_draw_city->hide();
        ui->pushButton_test_street->hide();
        ui->pushButton_teste_was->hide();
        ui->pushButton_test_abstract_map->hide();
        ui->pushButton_test_dijkstra->hide();
    }

    else
    {
        ui->pushButton->show();
        ui->pushButton_test_draw_city->show();
        ui->pushButton_test_street->show();
        ui->pushButton_teste_was->show();
        ui->pushButton_test_abstract_map->show();
        ui->pushButton_test_dijkstra->show();
    }
}



void MainWindow::on_pushButton_add_city_clicked()
{
    Dialog dialog;
    bool ok;

    while(true)
    {
        int ergebnis = dialog.exec();

        if(ergebnis == QDialog::Accepted)
        {
            qDebug() << "Eine neue Stadt wird der Liste hinzugefügt";
            QString name = dialog.getName();
            int x = dialog.getX().toInt(&ok);
            if (!ok) {
                qDebug() << "Fehler bei der Eingabe des X-Wertes, bitte nochmal eingeben.";
                continue;
            }

            int y = dialog.getY().toInt(&ok);
            if (!ok) {
                qDebug() << "Fehler bei der Eingabe des Y-Wertes, bitte nochmal eingeben.";
                continue;
            }

            std::string str = name.toStdString();
            std::size_t found = str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

            if(found != std::string::npos)
            {
                qDebug() << "Fehler bei der Eingabe des Namens, bitte nur Buchstaben verwenden.";
                continue;
            }

            City *city1 = new City(name, x, y);
            map.addCity(&city1);
            break;
        }
        else
        {
            break;
        }
    }
    map.draw(scene);
}


void MainWindow::on_pushButton_fill_map_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);

}


void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    //dijkstra search(map, start, target), return QVector<Street*>
    QVector<Street*> weg = Dijkstra::search(map, "Aachen", "Düsseldorf");
    qDebug() << "Der kürzeste Weg:";

    for(auto it=weg.begin(); it != weg.end(); it++)
    {
        qDebug() << "Straße" << (*it)->getCity1().getName() << (*it)->getCity2().getName();
        (*it)->drawRed(scene);
    }
}


void MainWindow::on_pushButton_dijkstra_clicked()
{
    DialogDijkstra dialog;
    int ergebnis = dialog.exec();
    QString stadt;

    if(ergebnis == QDialog::Accepted)
    {
        QString stadtname1 = dialog.getStadtname1();
        QString stadtname2 = dialog.getStadtname2();

        QVector<Street*> weg = Dijkstra::search(map, stadtname1, stadtname2);
        qDebug() << "Der kürzeste Weg von" << stadtname1 << "nach" << stadtname2 << ":";

        for(auto it=weg.begin(); it != weg.end(); it++)
        {
            (*it)->drawRed(scene);

            if((*it)->getCity2().getName() != stadt)
            {
                qDebug() << (*it)->getCity1().getName() << "nach" << (*it)->getCity2().getName();
            }

            else
            {
                qDebug() << (*it)->getCity2().getName() << "nach" << (*it)->getCity1().getName();
            }

            stadt = (*it)->getCity2().getName();

        }
    }
}


void MainWindow::on_pushButton_add_street_clicked()
{
    DialogStrasse dialog;
    int ergebnis = dialog.exec();

    if(ergebnis == QDialog::Accepted)
    {
        QString stadtname1 = dialog.getStadtname1();
        QString stadtname2 = dialog.getStadtname2();

        City* city1 = map.findCity(stadtname1);
        City* city2 = map.findCity(stadtname2);

        Street *street1 = new Street(city1, city2);
        map.addStreet(&street1);
        street1.draw(scene);
    }
}

