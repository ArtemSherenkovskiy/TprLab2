#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <setofthings.h>

class Calculator
{
public:
    Calculator();
    QList<double> *calculateAnswers(QList<double> *probabilityArray);
    QList<double> *calculateAnswers(QList<double> *probabilityArray, QMap<int, double> *newPrices);
    QString createTableWithWords();
    double transportationCost(int setId);

    QList<QList<double> *> getMonthExpenditure() const;

private:
    void createTemp();
    void createThings();
    void createSetsOfThings();
    double foreignCostCalculate(SetOfThings *setOfThings, int temperature);
    void calculateMonthExpenditure();
    void createMonthes();
    QString createCell(SetOfThings *setOfThings, int temperature);


    int setsOfThingsSize;
    QList<QList<double> *>monthExpenditure;
    int * temperatureArray;
    QList<QString> monthes;
    QList<Thing*> THINGS;
    QList<SetOfThings *> SETS_OF_THINGS;
};

#endif // CALCULATOR_H
