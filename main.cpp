#include "tableresult.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableResult w;
    w.show();

    return a.exec();
}
