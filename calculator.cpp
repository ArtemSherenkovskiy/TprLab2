#include "calculator.h"

Calculator::Calculator()
{
    temperatureArray = new int[12];
    createTemp();
    createThings();
    createSetsOfThings();
    calculateMonthExpenditure();
    setsOfThingsSize = SETS_OF_THINGS.size();
    createMonthes();
}


/**
 * @brief Calculator::calculateAnswers
 * @param QList<double> *probabilityArray
 * QList that contains probability of return in each month
 * @return QList<double> *
 * returns pointer to QList<double> costs you need to spend abroad
 */
QList<double> *Calculator::calculateAnswers(QList<double> *probabilityArray)
{
    QList<double> *answers = new QList<double>();
    for(int i = 0; i < setsOfThingsSize; ++i)
    {
        answers->append(0);
        for(int j = 0; j < NUM_OF_MONTHES; ++j)
        {
            answers->replace(i,answers->value(i) + monthExpenditure.at(i)->at(j) * probabilityArray->at(j));
        }
    }
    return answers;
}


/**
 * @brief Calculator::calculateAnswers
 * @param QList<double> *probabilityArray
 * pointer to QList<double> that contains probability of return in each month
 * @param QMap<int, int> newPrices
 * pointer to QMap<int, double> that contains combination (id of thing, koef to multiply cost of this thing)
 * @return QList<double> *
 * returns pointer to QList<double> costs you need to spend abroad
 * returns pointer to empty QList if newPrices values contains koeficient which is equal to zero
 */
QList<double> *Calculator::calculateAnswers(QList<double> *probabilityArray, QMap<int, double> *newPrices/*multyplies to current costs of things*/)
{
    if(newPrices->values().contains((double)(0)))
    {
        return new QList<double>();
    }
    for(int i = 0, size = THINGS.size(); i < size; ++i)
    {
        double value = newPrices->value(i, -1);
        if(value != -1)
        {
            THINGS[i]->setCost(((double)(THINGS[i]->getCost()) * value) + 0.5);
        }
    }
    calculateMonthExpenditure();
    QList<double> * answer = calculateAnswers(probabilityArray);
    for(int i = 0, size = THINGS.size(); i < size; ++i)
    {
        double value = newPrices->value(i, -1);
        if(value != -1)
        {
            THINGS[i]->setCost(((double)(THINGS[i]->getCost()) / value) + 0.5);
        }
    }
    return answer;

}

/**
 * @brief Calculator::createTableWithWords
 * create table with thing`s names and it is prety one
 * @return
 * QString that contains table
 */

QString Calculator::createTableWithWords()
{
    QString output = "";
    output += ";;";
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        output += QString::number(temperatureArray[i]) + ";";
    }
    output += "\n";
    output += "Sets;Transportation cost;";
    for(int i = 0, size = monthes.size(); i < size; ++i)
    {
        output += monthes.at(i) + ";";
    }
    output += "\n";
    for(int i = 0, setsSize = SETS_OF_THINGS.size(); i < setsSize; ++i)
    {
        output += QString::number(i + 1) + ";" + QString::number(SETS_OF_THINGS.at(i)->getCost()) + ";";
        for(int j = 0, monthesSize = monthes.size(); j < monthesSize; ++j)
        {
            output += createCell(SETS_OF_THINGS.at(i), temperatureArray[j]) + ";";
        }
        output += "\n";
    }
    return output;
}

double Calculator::transportationCost(int setId)
{
    return SETS_OF_THINGS[setId]->getCost();
}

/**
 * @brief Calculator::calculateMonthExpenditure
 * calculate expenditure of each combination between month to come back and set of things
 */
void Calculator::calculateMonthExpenditure()
{
    for(int i = 0; i < setsOfThingsSize; ++i)
    {
        monthExpenditure.append(new QList<double>());
        for(int j = 0; j < NUM_OF_MONTHES; ++j)
        {
            monthExpenditure[i]->append(SETS_OF_THINGS[i]->getCost() + foreignCostCalculate(SETS_OF_THINGS[i], temperatureArray[j]));
        }
    }
}

/**
 * @brief Calculator::createMonthes
 * create our 12 monthes
 */

void Calculator::createMonthes()
{
    monthes.append(QString("January"));
    monthes.append(QString("February"));
    monthes.append(QString("March"));
    monthes.append(QString("April"));
    monthes.append(QString("May"));
    monthes.append(QString("June"));
    monthes.append(QString("July"));
    monthes.append(QString("August"));
    monthes.append(QString("September"));
    monthes.append(QString("October"));
    monthes.append(QString("November"));
    monthes.append(QString("December"));
}

QString Calculator::createCell(SetOfThings *setOfThings, int temperature)
{
    SetOfThings *needSet;
    double needCost = 0;
    QString sumOfItemsNames = "";
    QString sumOfItemsCosts = "";
    int numOfNeededThings = 0;
    for(int i = 0; i < setsOfThingsSize; ++i)
    {
        if(SETS_OF_THINGS[i]->isPleasantTemperature(temperature))
        {
            needSet = SETS_OF_THINGS[i];
            break;
        }
    }
    if(needSet->getHead()->getId() != setOfThings->getHead()->getId())
    {
        if(sumOfItemsCosts != 0)
        {
            sumOfItemsCosts += "+";
            sumOfItemsNames += "+";
        }
        sumOfItemsCosts += QString::number(needSet->getHead()->foreignCost());
        sumOfItemsNames += needSet->getHead()->getName();
        needCost += needSet->getHead()->foreignCost();
        ++numOfNeededThings;
    }
    if(needSet->getUpper()->getId() != setOfThings->getUpper()->getId())
    {
        if(sumOfItemsCosts != 0)
        {
            sumOfItemsCosts += "+";
            sumOfItemsNames += "+";
        }
        sumOfItemsCosts += QString::number(needSet->getUpper()->foreignCost());
        sumOfItemsNames += needSet->getUpper()->getName();
        needCost += needSet->getUpper()->foreignCost();
        ++numOfNeededThings;
    }
    if(needSet->getGloves()->getId() != setOfThings->getGloves()->getId())
    {
        if(sumOfItemsCosts != 0)
        {
            sumOfItemsCosts += "+";
            sumOfItemsNames += "+";
        }
        sumOfItemsCosts += QString::number(needSet->getGloves()->foreignCost());
        sumOfItemsNames += needSet->getGloves()->getName();
        needCost += needSet->getGloves()->foreignCost();
        ++numOfNeededThings;
    }
    if(needSet->getPants()->getId() != setOfThings->getPants()->getId())
    {
        if(sumOfItemsCosts != 0)
        {
            sumOfItemsCosts += "+";
            sumOfItemsNames += "+";
        }
        sumOfItemsCosts += QString::number(needSet->getPants()->foreignCost());
        sumOfItemsNames += needSet->getPants()->getName();
        needCost += needSet->getPants()->foreignCost();
        ++numOfNeededThings;
    }
    if(needSet->getShoes()->getId() != setOfThings->getShoes()->getId())
    {
        if(sumOfItemsCosts != 0)
        {
            sumOfItemsCosts += "+";
            sumOfItemsNames += "+";
        }
        sumOfItemsCosts += QString::number(needSet->getShoes()->foreignCost());
        sumOfItemsNames += needSet->getShoes()->getName();
        needCost += needSet->getShoes()->foreignCost();
        ++numOfNeededThings;
    }

    return sumOfItemsNames + "  " + sumOfItemsCosts + " = " + QString::number(needCost);
}

QList<QList<double> *> Calculator::getMonthExpenditure() const
{
    return monthExpenditure;
}

/**
 * @brief Calculator::foreignCostCalculate
 * calculate expenditure you will do, if you take SetOfThings * setOfThings and temperature will be int temperature
 * @param setOfThings
 * pointer to SetOfThings that you want to take from home temperature that will be at place you want
 * @param temperature
 * temperature that will be at place you want
 * @return
 * returns sum of money which you will spend there
 */
double Calculator::foreignCostCalculate(SetOfThings *setOfThings, int temperature)
{
    SetOfThings *needSet;
    double needCost = 0;
    for(int i = 0; i < setsOfThingsSize; ++i)
    {
        if(SETS_OF_THINGS[i]->isPleasantTemperature(temperature))
        {
            needSet = SETS_OF_THINGS[i];
            break;
        }
    }
    if(needSet->getHead()->getId() != setOfThings->getHead()->getId())
    {
        needCost += needSet->getHead()->foreignCost();
    }
    if(needSet->getUpper()->getId() != setOfThings->getUpper()->getId())
    {
        needCost += needSet->getUpper()->foreignCost();
    }
    if(needSet->getGloves()->getId() != setOfThings->getGloves()->getId())
    {
        needCost += needSet->getGloves()->foreignCost();
    }
    if(needSet->getPants()->getId() != setOfThings->getPants()->getId())
    {
        needCost += needSet->getPants()->foreignCost();
    }
    if(needSet->getShoes()->getId() != setOfThings->getShoes()->getId())
    {
        needCost += needSet->getShoes()->foreignCost();
    }
    return needCost;
}


/**
 * @brief Calculator::createTemp
 * take string TASK from file constant.h and find there temperatures
 */
void Calculator::createTemp()
{
    QRegExp regExp("([\+\-]\\d+)");
    int index = 0;
    int iter = 0;
    while((index = regExp.indexIn(QString(TASK), index)) != -1)
    {
        QString str = regExp.cap(1);
        temperatureArray[iter] = str.toInt();
        index += str.length();
        ++iter;

    }
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        qDebug() << temperatureArray[i] << "\t";
    }
}


/**
 * @brief Calculator::createThings
 * create our THINGS
 */
void Calculator::createThings()
{
    THINGS.append(new Thing(0, "Empty", 0, 0));
    THINGS.append(new Thing(1, "Blazer", 0.5, 6));
    THINGS.append(new Thing(2, "Bushlat", 4, 48));
    THINGS.append(new Thing(3, "Vatnie shtani", 2, 24));
    THINGS.append(new Thing(4, "V`etnams", 0.5, 6));
    THINGS.append(new Thing(5, "Jeanse", 1, 12));
    THINGS.append(new Thing(6, "Kepka", 0.5, 6));
    THINGS.append(new Thing(7, "Krossi", 1, 12));
    THINGS.append(new Thing(8, "Kurtka", 2, 24));
    THINGS.append(new Thing(9, "Palto", 3, 36));
    THINGS.append(new Thing(10, "Rukavichki", 0.5, 6));
    THINGS.append(new Thing(11, "Svitr", 1, 12));
    THINGS.append(new Thing(12, "Rubashka", 0.5, 6));
    THINGS.append(new Thing(13, "Futbolka", 0.5, 6));
    THINGS.append(new Thing(14, "Chereviki", 1.5, 18));
    THINGS.append(new Thing(15, "Choboti", 2, 24));
    THINGS.append(new Thing(16, "Shapka", 1, 12));
    THINGS.append(new Thing(17, "Shorti", 0.5, 6));
}


/**
 * @brief Calculator::createSetsOfThings
 * create our set of  things
 */
void Calculator::createSetsOfThings()
{
    SETS_OF_THINGS.append(new SetOfThings(0, -10, INT_MIN, THINGS[16], THINGS[2],
            THINGS[10],THINGS[3], THINGS[15]));
    SETS_OF_THINGS.append(new SetOfThings(1, 0, -9, THINGS[16], THINGS[9],
            THINGS[10],THINGS[5], THINGS[15]));
    SETS_OF_THINGS.append(new SetOfThings(2, 10, 1, THINGS[6], THINGS[8],
            THINGS[0],THINGS[5], THINGS[14]));
    SETS_OF_THINGS.append(new SetOfThings(3, 20, 11, THINGS[0], THINGS[11],
            THINGS[0],THINGS[5], THINGS[7]));
    SETS_OF_THINGS.append(new SetOfThings(4, 30, 21, THINGS[1], THINGS[12],
            THINGS[0],THINGS[5], THINGS[7]));
    SETS_OF_THINGS.append(new SetOfThings(5, INT_MAX, 31, THINGS[1], THINGS[13],
            THINGS[0],THINGS[17], THINGS[4]));
    setsOfThingsSize = SETS_OF_THINGS.size();
}


