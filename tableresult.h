#ifndef TABLERESULT_H
#define TABLERESULT_H

#include <limits.h>
#include <calculator.h>
#include <QMainWindow>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

namespace Ui {
class TableResult;
}

class TableResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableResult(QWidget *parent = 0);
    ~TableResult();
QString createTable();
private:
    Ui::TableResult *ui;
    Calculator *calculator;
    QString output;
    void createPrabability(QList<double> *probability, double d1,double d2,double d3,double d4,double d5,double d6,double d7,double d8,double d9,double d10,double d11,double d12);
    void createSimpleTable(QList<double> *probability, QString tableName);
    void createSimpleTable(QList<double> *probability, QString tableName, QMap<int, double> *newPrices);
};

#endif // TABLERESULT_H
