#ifndef TABLERESULT_H
#define TABLERESULT_H


#include <thing.h>
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
    void createThings();
};

#endif // TABLERESULT_H
