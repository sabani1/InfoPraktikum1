#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    /**
     * @brief getName
     * @return Gibt Name der eintragene Stadt wieder
     */
    QString getName();

    /**
     * @brief getX
     * @return Gibt X-Koordinate der eingetragene Stadt wieder
     */
    QString getX();

    /**
     * @brief getY
     * @return Gibt Y-Koordinate der eingetragene Stadt wieder
     */
    QString getY();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    QString name;
    QString x;
    QString y;

};

#endif // DIALOG_H
