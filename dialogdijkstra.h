#ifndef DIALOGDIJKSTRA_H
#define DIALOGDIJKSTRA_H

#include <QDialog>

namespace Ui {
class DialogDijkstra;
}

class DialogDijkstra : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDijkstra(QWidget *parent = nullptr);
    ~DialogDijkstra();

    /**
     * @brief getStadtname1
     * @return Gibt Name der ersten Stadt wieder
     */
    QString getStadtname1();

    /**
     * @brief getStadtname2
     * @return Gibt Name der zweiten Stadt wieder
     */
    QString getStadtname2();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDijkstra *ui;
    QString stadtname1;
    QString stadtname2;
};

#endif // DIALOGDIJKSTRA_H
