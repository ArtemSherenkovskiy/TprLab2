#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{
    ui->setupUi(this);
    temperatures = new int[12];
    createTemp();
}

TableResult::~TableResult()
{
    delete ui;
}

void TableResult::createTemp()
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
