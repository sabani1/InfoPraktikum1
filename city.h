#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>

class City
{
public:

    /**
     * @brief Standardkonstruktor
     */
    City();

    /**
     * @brief City Konstruktor
     * @param name Name der Stadt
     * @param x X-Koordinate der Stadt
     * @param y Y-Koordinate der Stadt
     */
    City(QString name, int x, int y);

    /**
     * @brief draw Zeichnet die Stadt in die Szene
     * @param scene Grafikbild des Hauptfensters
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief getName Gibt Name der Stadt wieder
     * @return QString Name der Stadt
     */
    QString getName() const;

    /**
     * @brief getXPosition Gibt X-Position der Stadt wieder
     * @return int X-Position der Stadt
     */
    int getXPosition() const;

    /**
     * @brief getYPosition Gibt Y-Position der Stadt wieder
     * @return int Y-Position der Stadt
     */
    int getYPosition() const;

private:
    QString name;
    int x;
    int y;

};

#endif // CITY_H
