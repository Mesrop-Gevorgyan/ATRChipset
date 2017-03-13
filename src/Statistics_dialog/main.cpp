#include <QApplication>
#include "config_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CConfigWidget * config_widget = new CConfigWidget();
    config_widget->show();

    return a.exec();
}
