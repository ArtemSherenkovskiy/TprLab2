#include "tableresult.h"
#include "ui_tableresult.h"

TableResult::TableResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableResult)
{
    ui->setupUi(this);
}

TableResult::~TableResult()
{
    delete ui;
}
