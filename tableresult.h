#ifndef TABLERESULT_H
#define TABLERESULT_H

#include <limits.h>
#include <setofthings.h>
#include <QMainWindow>

namespace Ui {
class TableResult;
}

class TableResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableResult(QWidget *parent = 0);
    ~TableResult();

private:
    Ui::TableResult *ui;
    int * temperatures;
    void createTemp();
    QList<Thing*> THINGS;
    QList<SetOfThings *> SETS_OF_THINGS;
    void createThings();
    void createSetsOfThings();
};

#endif // TABLERESULT_H
