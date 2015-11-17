#include "setofthings.h"

/**
 * @brief SetOfThings::SetOfThings
 * @param int id
 * id of the current Set
 * @param int tempMax
 * maximum temperature which is pleasant for this Set
 * @param int tempMin
 * minimum temperature which is pleasant for this Se
 * @param Thing *head
 * Thing that you want to wear on your head
 * @param Thing *upper
 * Thing that you want to wear on your body
 * @param Thing *gloves
 * Thing that you want to wear on your arms
 * @param Thing *pants
 * Thing that you want to wear on your legs
 * @param Thing *shoes
 * Thing that you want to wear on your foots
 */
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

/**
 * @brief SetOfThings::calculateWeight
 * function calculate weight parametr of current Set
 */
void SetOfThings::calculateWeight()
{
    weight += head->getWeight();
    weight += upper->getWeight();
    weight += gloves->getWeight();
    weight += pants->getWeight();
    weight += shoes->getWeight();
}

/**
 * @brief SetOfThings::calculateCost
 * function calculate cost parametr of current Set
 */
void SetOfThings::calculateCost()
{
    cost = weight * (double)(KILOGRAM_COST);
}

double SetOfThings::getCost() const
{
    return cost;
}

void SetOfThings::setCost(double value)
{
    cost = value;
}

double SetOfThings::getWeight() const
{
    return weight;
}

void SetOfThings::setWeight(double value)
{
    weight = value;
}

Thing *SetOfThings::getShoes() const
{
    return shoes;
}

void SetOfThings::setShoes(Thing *value)
{
    shoes = value;
}

Thing *SetOfThings::getPants() const
{
    return pants;
}

void SetOfThings::setPants(Thing *value)
{
    pants = value;
}

Thing *SetOfThings::getGloves() const
{
    return gloves;
}

void SetOfThings::setGloves(Thing *value)
{
    gloves = value;
}

Thing *SetOfThings::getUpper() const
{
    return upper;
}

void SetOfThings::setUpper(Thing *value)
{
    upper = value;
}

Thing *SetOfThings::getHead() const
{
    return head;
}

void SetOfThings::setHead(Thing *value)
{
    head = value;
}

int SetOfThings::getTempMin() const
{
    return tempMin;
}

void SetOfThings::setTempMin(int value)
{
    tempMin = value;
}

int SetOfThings::getTempMax() const
{
    return tempMax;
}

void SetOfThings::setTempMax(int value)
{
    tempMax = value;
}

int SetOfThings::getId() const
{
    return id;
}

void SetOfThings::setId(int value)
{
    id = value;
}

/**
 * @brief SetOfThings::isPleasantTemperature
 * function check if the input temperature is pleasant for this set
 * @param int temperature
 * temperature you want to check
 * @return
 * true if temperature is pleasant
 * false if temperature is not pleasant
 */
bool SetOfThings::isPleasantTemperature(int temperature)
{
    if(temperature >= tempMin && temperature <= tempMax)
    {
        return true;
    }
    return false;
}

