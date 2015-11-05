#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{
    ui->setupUi(this);
    calculator = new Calculator();
    QList<double> *probability = new QList<double>();
    for(int i = 0; i < NUM_OF_MONTHES; ++i)
    {
        probability->append((double)1/(double)12);
    }
    QList<double> *answers = calculator->calculateAnswers(probability);
    system("pause");
}

TableResult::~TableResult()
{
    delete ui;
}


