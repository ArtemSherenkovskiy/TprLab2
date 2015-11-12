#ifndef TABLERESULT_H
#define TABLERESULT_H

#include <limits.h>
#include <calculator.h>
#include <QMainWindow>
#include <QFile>
namespace Ui {
class TableResult;
}

class TableResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableResult(QWidget *parent = 0);
    ~TableResult();
void createTable();
private:
    Ui::TableResult *ui;
    Calculator *calculator;

};

#endif // TABLERESULT_H
