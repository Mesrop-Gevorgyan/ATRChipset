#include <QApplication>
#include "statistic_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Statisticsdialog w;
    w.show();

    return a.exec();
}
