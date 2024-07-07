#ifndef MAP_H
#define MAP_H
#include "city.h"
#include "street.h"
#include "abstractmap.h"
#include <QVector>

class Map : public AbstractMap
{
public:
    /**
     * @brief Map Standardkonstruktor
     */
    Map();

    /**
     * @brief addCity Fügt Stadt zur Stadtliste hinzu
     * @param city Stadt die hinzugefügt werden soll
     */
    void addCity(City* city);

    /**
     * @brief addStreet Fügt Straße zur Straßenliste hinzu
     * @param street Straße die hinzugefügt werden soll
     * @return true, falls Straße hinzugefügt werden kann, sonst false
     */
    bool addStreet(Street* street);

    /**
     * @brief draw Zeichnet alle Städte und Straßen ins Grafikfenster ein
     * @param scene Grafikfenster
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief findCity Sucht Stadt in der Stadtliste
     * @param cityName Name der Stadt, die gesucht werden soll
     * @return Zeiger auf gefundene Stadt
     */
    City* findCity(const QString cityName) const;

    /**
     * @brief getStreetList Gibt alle Straßen wieder, die mit einer Stadt verbunden sind
     * @param city Stadt, die untersucht werden soll
     * @return Vektorliste mit allen Straßen
     */
    QVector<Street*> getStreetList(const City* city) const;

    /**
     * @brief getOppositeCity Gibt Stadt wieder, die auf gegenüberliegende Seite von der Straße liegt
     * @param street Straße, die zwei Städte verbindet
     * @param city Stadt, die auf einer Seite der Straße liegt
     * @return Zeiger auf gegenüberliegende Stadt
     */
    City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief getLength Gibt Länge einer Straße wieder
     * @param street Straße, die untersucht werden soll
     * @return Länge der Straße als double
     */

    double getLength(const Street* street) const;

    /**
     * @brief clear Löscht Inhalte der Stadtliste und Straßenliste
     */
    void clear();

private:
    QVector<City*> stadtliste;
    QVector<Street*> strassenliste;

};

#endif // MAP_H
