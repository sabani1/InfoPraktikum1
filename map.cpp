#include "map.h"
#include <QDebug>
#include <QtMath>

Map::Map() {}

void Map::addCity(City* city)
{
    for(auto it = stadtliste.begin(); it != stadtliste.end(); ++it)
    {
        if((*it)->getName() == city->getName())
        {
            qDebug() << "Die Stadt existiert schon auf der Karte!";
            return;
        }
    }
    qDebug() << "Die Stadt wurde der Liste hinzugefügt.";
    stadtliste.push_back(city);
}

bool Map::addStreet(Street* street)
{
    int counter = 0;

    for(int i=0; i<stadtliste.size(); i++)
    {
        if(stadtliste[i]->getName() == street->getCity1().getName() || stadtliste[i]->getName() == street->getCity2().getName())
        {
            counter++;
        }

    }

    if(counter >= 2)
    {
        strassenliste.push_back(street);
        return true;
    }

    else
    {
        qDebug() << "Die Städte existieren nicht auf der Karte.";
        return false;
    }
}

void Map::draw(QGraphicsScene& scene)
{
    for(auto city : stadtliste)
    {
        city->draw(scene);
    }

    for(auto street : strassenliste)
    {
        street->draw(scene);
    }

}

City* Map::findCity(const QString cityName) const
{
    for(auto it=stadtliste.begin(); it!=stadtliste.end(); it++)
    {
        if((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> liste;

    for(auto it=strassenliste.begin(); it != strassenliste.end(); it++)
    {
        if((*it)->getCity1().getName() == (*city).getName() || (*it)->getCity2().getName() == (*city).getName())
        {
            liste.push_back(*it);
        }
    }
    return liste;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{

    if(street->getCity1().getName() == (*city).getName())
    {
        return street->getCity2ptr();

    }

    else if(street->getCity2().getName() == (*city).getName())
    {
        return street->getCity1ptr();
    }

    return nullptr;
}

double Map::getLength(const Street* street) const
{
    double x1 = street->getCity1().getXPosition();
    double y1 = street->getCity1().getYPosition();
    double x2 = street->getCity2().getXPosition();
    double y2 = street->getCity2().getYPosition();


    return qSqrt(qPow(x2-x1, 2)+qPow(y2-y1, 2));

}

void Map::clear()
{
    stadtliste.clear();
    strassenliste.clear();
}
