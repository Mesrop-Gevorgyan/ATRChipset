#ifndef STATISTIC_DIALOG_H
#define STATISTIC_DIALOG_H

#include "config_pages.h"
#include "QComboBox"
#include <iostream>

class Statisticsdialog: public ConfigPages
{
    Q_OBJECT
public:
    Statisticsdialog();
public slots:
    void on_comboBox_currentIndexChanged(const QString & arg1);
private:
    QVBoxLayout * typeLayout;
    QVBoxLayout * typeFuncLayout;
};

#endif // STATISTIC_DIALOG_H
