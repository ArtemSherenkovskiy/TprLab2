#include "calculator.h"

Calculator::Calculator()
{
    temperatures = new int[12];
    createTemp();
    createThings();
}


void Calculator::createTemp()
{
    QRegExp regExp("([\+\-]\\d+)");
    int index = 0;
    int iter = 0;
    while((index = regExp.indexIn(QString(TASK), index)) != -1)
    {
        QString str = regExp.cap(1);
        temperatures[iter] = str.toInt();
        index += str.length();
        ++iter;

    }
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        qDebug() << temperatures[i] << "\t";
    }
}

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
    THINGS.append(new Thing(15, "Bashmaki", 2, 24));
    THINGS.append(new Thing(16, "Shapka", 1, 12));
    THINGS.append(new Thing(17, "Shorti", 0.5, 6));
}

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
    SETS_OF_THINGS.append(new SetOfThings(5, 31, INT_MAX, THINGS[1], THINGS[13],
                                          THINGS[0],THINGS[5], THINGS[4]));
}
