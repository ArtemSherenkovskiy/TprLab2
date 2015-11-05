#ifndef TABLERESULT_H
#define TABLERESULT_H

#include "constants.h"
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
};

#endif // TABLERESULT_H
