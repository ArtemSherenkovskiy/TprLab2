#ifndef THING_H
#define THING_H


#include "constants.h"
#include<QString>


class Thing
{
public:
    Thing();
    Thing(int id, QString name, double weight, int cost);
    int id;
    QString name;
    double weight;
    int cost;

};

#endif // THING_H
