#include "thing.h"


/**
 * @brief Thing::Thing
 * constructor creates Thing
 * @param int id
 * id of current item
 * @param QString name
 * name of current item
 * @param double weight
 * weight of current item
 * @param int cost
 * cost of current item
 */
Thing::Thing(int id, QString name, double weight, int cost)
{
    this->id = id;
    this->name = name;
    this->weight = weight;
    this->cost = cost;
}

/**
 * @brief Thing::foreignCost
 * @return
 * int that contains cost of the thing abroad
 * if the thing has id == 0, foreing cost is equal to cost
 */
int Thing::foreignCost()
{

    return id ? cost + FOREIGN_BONUS : cost;
}

int Thing::getId() const
{
    return id;
}

void Thing::setId(int value)
{
    id = value;
}

QString Thing::getName() const
{
    return name;
}

void Thing::setName(const QString &value)
{
    name = value;
}

double Thing::getWeight() const
{
    return weight;
}

void Thing::setWeight(double value)
{
    weight = value;
}

int Thing::getCost() const
{
    return cost;
}

void Thing::setCost(int value)
{
    cost = value;
}

