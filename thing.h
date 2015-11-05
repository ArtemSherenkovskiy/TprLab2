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
    static const int FOREIGN_BONUS = 2;// на 2 уо дороже за гарницей

};

#endif // THING_H
