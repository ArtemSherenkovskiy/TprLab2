#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <setofthings.h>

class Calculator
{
public:
    Calculator();
    double *calculateAnswers(double *probabilityArray);
    double *calculateAnswers(double *probabilityArray, QMap<int, int> newPrices);


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
    double **monthExpenditure;
};

#endif // CALCULATOR_H
