#include "thing.h"

Thing::Thing()
{

}

Thing::Thing(int id, QString name, double weight, int cost)
{
    this->id = id;
    this->name = name;
    this->weight = weight;
    this->cost = cost;
}

