#ifndef SETOFTHINGS_H
#define SETOFTHINGS_H

#include "thing.h"
#include <QMessageBox>


class SetOfThings
{
public:
    SetOfThings(int id, int tempMax, int tempMin, Thing *head, Thing *upper, Thing *gloves, Thing *pants, Thing *shoes);
    bool isPleasantTemperature(int temperature);

    int getId() const;
    void setId(int value);

    int getTempMax() const;
    void setTempMax(int value);

    int getTempMin() const;
    void setTempMin(int value);

    Thing *getHead() const;
    void setHead(Thing *value);

    Thing *getUpper() const;
    void setUpper(Thing *value);

    Thing *getGloves() const;
    void setGloves(Thing *value);

    Thing *getPants() const;
    void setPants(Thing *value);

    Thing *getShoes() const;
    void setShoes(Thing *value);

    double getWeight() const;
    void setWeight(double value);

    double getCost() const;
    void setCost(double value);

private:
    void calculateWeight();
    void calculateCost();


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
};

#endif // SETOFTHINGS_H
