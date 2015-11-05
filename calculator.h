#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <setofthings.h>

class Calculator
{
public:
    Calculator();


private:
    int * temperatures;
    void createTemp();
    QList<Thing*> THINGS;
    QList<SetOfThings *> SETS_OF_THINGS;
    void createThings();
    void createSetsOfThings();
};

#endif // CALCULATOR_H
