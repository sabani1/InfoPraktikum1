#ifndef STREET_H
#define STREET_H
#include "city.h"
#include <QGraphicsScene>

class Street
{
public:
    /**
     * @brief Street Konstruktor
     * @param city1
     * @param city2
     */
    Street(City* city1, City* city2);

    /**
     * @brief draw Zeichnet die Straße ins Grafikfenster
     * @param scene Grafikfenster des Hauptfensters
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief getCity1 Gibt erste Stadt mit der die Straße verbunden ist wieder
     * @return city1
     */
    City getCity1() const;

    /**
     * @brief getCity2 Gibt zweite Stadt mit der die Straße verbunden ist wieder
     * @return city2
     */
    City getCity2() const;

    /**
     * @brief getCity1ptr Gibt Zeiger auf erster Stadt wieder
     * @return Zeiger auf city1
     */
    City* getCity1ptr() const;

    /**
     * @brief getCity2ptr Gibt Zeiger auf zweiter Stadt wieder
     * @return Zeiger auf city2
     */
    City* getCity2ptr() const;

    /**
     * @brief drawRed Zeichnet Straße in rot ein
     * @param scene Grafikfenster
     */
    void drawRed(QGraphicsScene& scene);

private:
    City* city1;
    City* city2;
};

#endif // STREET_H
