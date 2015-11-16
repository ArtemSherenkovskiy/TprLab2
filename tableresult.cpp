#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{

    calculator = new Calculator();
   createTable();
   ui->setupUi(this);
}

TableResult::~TableResult()
{
    delete ui;
}

void TableResult::createTable()
{
    QFile file("result.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
           return;

       QTextStream out(&file);

    QList<double> *probability = new QList<double>();
    auto sets = calculator->getMonthExpenditure();
    //
    //Сколько нужно потратить всего на первозку и докупку одежды
    //
    //
    out<< "All expenditure\nSets ;";
    for(int i = 0 ; i<NUM_OF_MONTHES;i++)
    {
        out<<i+1<<";";
    }
    out<<"\n";
    for(int i=0;i<sets.size();i++)
    {
        out<<i<<";";
        for(int j=0; j<sets.at(i)->size();j++)
        {
            out<<sets.at(i)->at(j)<<";";
        }
        out<<"\n";
    }
    out<<"\n\n\n"<<"For 12 monthes\nSets;Cost\n";
    //
    //for 12 monthes
    //
    //
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        probability->append((double)1/(double)12);
    }
    auto avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }
    //
    //Winter
    //
    //
    out<<"\n\n\n"<<"Winter\nSets;Cost\n";
    double oneThird = (double)1/(double)3;
    createPrabability(probability,oneThird,oneThird,0,0,0,0,0,0,0,0,0,oneThird);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }
    //
    //Spring
    //
    //
    out<<"\n\n\n"<<"Spring\nSets;Cost\n";
    createPrabability(probability,0,0,oneThird,oneThird,oneThird,0,0,0,0,0,0,0);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }
    //
    //Summer
    //
    //
    out<<"\n\n\n"<<"Summer\nSets;Cost\n";
    createPrabability(probability,0,0,0,0,0,oneThird,oneThird,oneThird,0,0,0,0);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }
    //
    //Autumn
    //
    //
    out<<"\n\n\n"<<"Autumn\nSets;Cost\n";
    createPrabability(probability,0,0,0,0,0,0,0,0,oneThird,oneThird,oneThird,0);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }

    //
    //for 12 monthes
    //
    //
    double day31 = (double)31/(double)365;
    double day30 = (double)30/(double)365;
    double day28 = (double)28/(double)365;

    out<<"\n\n\n"<<"12monthes with days\nSets;Cost\n";
    createPrabability(probability,day31,day28,day31,day30,day31,day30,day31,day31,day30,day31,day30,day31);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }

    //
    //for 12 monthes winter probability x3
    //
    //
    double oneEighteens = (double)1/(double)18;
    double oneSix = (double)1/(double)6;

    out<<"\n\n\n"<<"12monthes winterx3\nSets;Cost\n";
    createPrabability(probability,oneSix,oneSix,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneEighteens,oneSix);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }

    //
    //for 12 monthes things x1/3
    //
    //

    out<<"\n\n\n"<<"12monthes things x1/3\nSets;Cost\n";
    probability->clear();
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        probability->append((double)1/(double)12);
    }
    QMap<int, double> *mapa = new QMap<int, double>();
    mapa->insert(2, oneThird);
    mapa->insert(4, oneThird);
    mapa->insert(9, oneThird);
    mapa->insert(15, oneThird);
    mapa->insert(16, oneThird);
    avarageExp = calculator->calculateAnswers(probability);
    for(int i = 0;i<avarageExp->size();i++)
    {
        out<<i<<";"<<avarageExp->at(i)<<"\n";
    }



}

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


