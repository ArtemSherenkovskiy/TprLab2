#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{
    ui->setupUi(this);
    calculator = new Calculator();
   createTable();
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
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        probability->append((double)1/(double)12);
    }
    auto sets = calculator->getMonthExpenditure();
    out<< 'Sets ;';
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
}


