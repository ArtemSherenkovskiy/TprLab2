#ifndef THING_H
#define THING_H


#include "constants.h"
#include<QString>


class Thing
{
public:
    Thing(int id, QString name, double weight, int cost);
    int foreignCost();


    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    double getWeight() const;
    void setWeight(double value);

    int getCost() const;
    void setCost(int value);

private:
    int id;
    QString name;
    double weight;
    int cost;
    static const int FOREIGN_BONUS = 2;// на 2 уо дороже за гарницей

};

#endif // THING_H
