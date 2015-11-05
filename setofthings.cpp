#include "setofthings.h"

SetOfThings::SetOfThings(int id, int tempMax, int tempMin, Thing *head, Thing *upper, Thing *gloves, Thing *pants, Thing *shoes)
{
    this->id = id;
    this->tempMax = tempMax;
    this->tempMin = tempMin;
    this->head = head;
    this->upper = upper;
    this->gloves = gloves;
    this->pants = pants;
    this->shoes = shoes;
    weight = 0;
    calculateWeight();
    calculateCost();
}

void SetOfThings::calculateWeight()
{
    weight += head->weight;
    weight += upper->weight;
    weight += gloves->weight;
    weight += pants->weight;
    weight += shoes->weight;
}

void SetOfThings::calculateCost()
{
    cost = weight * (double)(KILOGRAM_COST);
}

bool SetOfThings::isPleasantTemperature(int temperature)
{
    if(temperature > tempMin && temperature < tempMax)
    {
        return true;
    }
    return false;
}

