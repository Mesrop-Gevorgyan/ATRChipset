#include <QApplication>
#include "statistic_dialog.h"
#include "pareto_dialog.h"
#include "config_pages.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paretodialog w;
    w.show();

    return a.exec();
}
