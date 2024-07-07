#ifndef DIALOGSTRASSE_H
#define DIALOGSTRASSE_H

#include <QDialog>

namespace Ui {
class DialogStrasse;
}

class DialogStrasse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStrasse(QWidget *parent = nullptr);
    ~DialogStrasse();

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
    Ui::DialogStrasse *ui;
    QString stadt1;
    QString stadt2;
};

#endif // DIALOGSTRASSE_H
