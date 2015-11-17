#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{
    calculator = new Calculator();
    QString filePath = createTables();
    ui->setupUi(this);
    ui->label_3->setText(filePath);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

TableResult::~TableResult()
{
    delete ui;
}

/**
 * @brief TableResult::createTables
 * create all output tables and write them into file
 * @return
 * QString which contains the absolute path to the file
 */
QString TableResult::createTables()
{
    output = "";

    auto sets = calculator->getMonthExpenditure();
    //
    //Сколько нужно потратить всего на первозку и докупку одежды
    //
    //
    output += "All expenditure\nSets ;";
    for(int i = 0 ; i<NUM_OF_MONTHES;i++)
    {
        output += QString::number(i+1) + ";";
    }
    output += "\n";
    for(int i=0;i<sets.size();i++)
    {
        output += QString::number(i + 1) + ";";
        for(int j=0; j<sets.at(i)->size();j++)
        {
            output += QString::number(sets.at(i)->at(j)) + ";";
        }
        output += "\n";
    }

    double oneThird = (double)1/(double)3;
    double oneSix = (double)1/(double)6;
    double oneTwelve = (double)1/(double)12;
    double oneEighteens = (double)1/(double)18;

    double day31 = (double)31/(double)365;
    double day30 = (double)30/(double)365;
    double day28 = (double)28/(double)365;

    QList<double> *probability = new QList<double>();


    //
    //for 12 monthes
    //
    //
    createPrabability(probability, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve);
    createSimpleTable(probability, QString("For 12 monthes"));


    //
    //Winter
    //
    //

    createPrabability(probability,oneThird,oneThird,0,0,0,0,0,0,0,0,0,oneThird);
    createSimpleTable(probability,QString("Winter"));

    //
    //Spring
    //
    //

    createPrabability(probability,0,0,oneThird,oneThird,oneThird,0,0,0,0,0,0,0);
    createSimpleTable(probability,QString("Spring"));

    //
    //Summer
    //
    //

    createPrabability(probability,0,0,0,0,0,oneThird,oneThird,oneThird,0,0,0,0);
    createSimpleTable(probability,QString("Summer"));
    //
    //Autumn
    //
    //

    createPrabability(probability,0,0,0,0,0,0,0,0,oneThird,oneThird,oneThird,0);
    createSimpleTable(probability,QString("Autumn"));


    //
    //for 12 monthes with days
    //
    //

    createPrabability(probability,day31,day28,day31,day30,day31,day30,day31,day31,day30,day31,day30,day31);
    createSimpleTable(probability,QString("12 monthes with days"));

    //
    //for 12 monthes winter probability x3
    //
    //

    createPrabability(probability,oneSix,oneSix,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneSix);
    createSimpleTable(probability,QString("Winter probabiliti x3"));

    //
    //for 12 monthes things x1/3
    //
    //

    createPrabability(probability, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve, oneTwelve);
    QMap<int, double> *mapa = new QMap<int, double>();
    mapa->insert(2, oneThird);
    mapa->insert(4, oneThird);
    mapa->insert(9, oneThird);
    mapa->insert(15, oneThird);
    mapa->insert(16, oneThird);
    createSimpleTable(probability, QString("12monthes things x1/3"), mapa);

    QFile file("result.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return QString("Error opening file!!!");
    QTextStream out(&file);
    out << output;
    QFileInfo fileInfo(file);
    return fileInfo.absoluteFilePath();

}



/**
 * @brief TableResult::createPrabability
 * function appends all input double values to QList
 * @param QList<double> *probability
 * pointer to QList in which function appends all input double values, this list is cleared firstly
 * @param double d1
 * probability to come back in January
 * @param double d2
 * probability to come back in February
 * @param double d3
 * probability to come back in March
 * @param double d4
 * probability to come back in April
 * @param double d5
 * probability to come back in May
 * @param double d6
 * probability to come back in June
 * @param double d7
 * probability to come back in July
 * @param double d8
 * probability to come back in August
 * @param double d9
 * probability to come back in September
 * @param double d10
 * probability to come back in October
 * @param double d11
 * probability to come back in November
 * @param double d12
 * probability to come back in December
 */
void TableResult::createPrabability(QList<double> *probability, double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9, double d10, double d11, double d12)
{
    probability->clear();
    probability->append(d1);
    probability->append(d2);
    probability->append(d3);
    probability->append(d4);
    probability->append(d5);
    probability->append(d6);
    probability->append(d7);
    probability->append(d8);
    probability->append(d9);
    probability->append(d10);
    probability->append(d11);
    probability->append(d12);

}



/**
 * @brief TableResult::createSimpleTable
 * create table in string variant and appent it to private QString output
 * @param QList<double> *probability
 * probability of coming back in each month of the year
 * @param QString tableName
 * name of the table that function will created
 */

void TableResult::createSimpleTable(QList<double> *probability, QString tableName)
{
    output += "\n\n\n" + tableName + "\nSets;Cost\n";

    QList<double> * avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        output += QString::number(i + 1) + ";" + QString::number(avarageExp->at(i)) + "\n";
    }
    int bestId = calculateBestSet(avarageExp);
    output += "\n;Set;Cost\nBest;" + QString::number(bestId + 1) + ";" + QString::number(avarageExp->at(bestId));
}


/**
 * @brief TableResult::createSimpleTable
 * create table in string variant and appent it to private QString output
 * @param QList<double> *probability
 * probability of coming back in each month of the year
 * @param QString tableName
 * name of the table that function will created
 * @param QMap<int, double> *newPrices
 * pointer to QMap  that contains combination of id of thing and koeficient to multiply the cost of thing
 */


void TableResult::createSimpleTable(QList<double> *probability, QString tableName, QMap<int, double> *newPrices)
{
    output += "\n\n\n" + tableName + "\nSets;Cost\n";

    QList<double> * avarageExp = calculator->calculateAnswers(probability, newPrices);
    for(int i = 0;i<avarageExp->size();i++)
    {
        output += QString::number(i + 1) + ";" + QString::number(avarageExp->at(i)) + "\n";
    }
    int bestId = calculateBestSet(avarageExp);
    output += "\n;Set;Cost\nBest;" + QString::number(bestId + 1) + ";" + QString::number(avarageExp->at(bestId));
}


/**
 * @brief TableResult::calculateBestSet
 * calculates the lowest item in QList
 * @param QList<double> *avarageExpenditures
 * pointer to QList that contains expenditures for each SetOfThings
 * @return
 * returns index of item with the lowest number
 */
int TableResult::calculateBestSet(QList<double> *avarageExpenditures)
{
    int bestId = 0;
    double bestExpenditure = INT_MAX;
    for(int i = 0, size = avarageExpenditures->size(); i < size; ++i)
    {
        if(avarageExpenditures->at(i) < bestExpenditure)
        {
            bestId = i;
            bestExpenditure = avarageExpenditures->at(i);
        }
    }
    return bestId;
}




