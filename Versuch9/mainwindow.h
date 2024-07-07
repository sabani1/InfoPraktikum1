#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_test_draw_city_clicked();

    void on_pushButton_clicked();

    void on_pushButton_test_street_clicked();

    void on_checkBox_testknoepfe_clicked();

    void on_pushButton_add_city_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_test_abstract_map_clicked();

    void on_pushButton_test_dijkstra_clicked();

    void on_pushButton_dijkstra_clicked();

    void on_pushButton_add_street_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;

};
#endif // MAINWINDOW_H
