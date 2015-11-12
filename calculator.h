#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <setofthings.h>

class Calculator
{
public:
    Calculator();
    QList<double> *calculateAnswers(QList<double> *probabilityArray);
    QList<double> *calculateAnswers(QList<double> *probabilityArray, QMap<int, double> *newPrices);


    QList<QList<double> *> getMonthExpenditure() const;

private:
    int * temperatureArray;
    void createTemp();
    QList<Thing*> THINGS;
    QList<SetOfThings *> SETS_OF_THINGS;
    void createThings();
    void createSetsOfThings();
    double foreignCostCalculate(SetOfThings *setOfThings, int temperature);
    void calculateMonthExpenditure();
    int setsOfThingsSize;
    QList<QList<double> *>monthExpenditure;
};

#endif // CALCULATOR_H
