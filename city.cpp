#include "city.h"
#include <QString>
#include <QDebug>
#include <QGraphicsTextItem>

City::City()
{
    name = "";
    x = 0;
    y = 0;
}

City::City(QString name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 4, 4, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(name);
    scene.addItem(text);
}

QString City::getName() const
{
    return name;
}

int City::getXPosition() const
{
    return x;
}

int City::getYPosition() const
{
    return y;
}
