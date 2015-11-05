#ifndef SETOFTHINGS_H
#define SETOFTHINGS_H

#include "thing.h"


class SetOfThings
{
public:
    SetOfThings(int id, int tempMax, int tempMin, Thing *head, Thing *upper, Thing *gloves, Thing *pants, Thing *shoes);

    int id;
    int tempMax;
    int tempMin;
    Thing *head;
    Thing *upper;
    Thing *gloves;
    Thing *pants;
    Thing *shoes;
    double weight;
    double cost;
    static const int KILOGRAM_COST = 10;


private:
    void calculateWeight();
    void calculateCost();
public:
    bool isPleasantTemperature(int temperature);

};

#endif // SETOFTHINGS_H
