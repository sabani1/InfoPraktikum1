#include "street.h"

Street::Street(City* city1, City* city2)
{
    this->city1 = city1;
    this->city2 = city2;
}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(city1->getXPosition(), city1->getYPosition(), city2->getXPosition(), city2->getYPosition(), QPen(Qt::green));
}

City Street::getCity1() const
{
    return *city1;
}

City Street::getCity2() const
{
    return *city2;
}

City* Street::getCity1ptr() const
{
    return city1;
}

City* Street::getCity2ptr() const
{
    return city2;
}

void Street::drawRed(QGraphicsScene& scene)
{
    scene.addLine(city1->getXPosition(), city1->getYPosition(), city2->getXPosition(), city2->getYPosition(), QPen(Qt::red));
}
