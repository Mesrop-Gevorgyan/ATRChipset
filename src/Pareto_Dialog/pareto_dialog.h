#ifndef PARETO_DIALOG_H
#define PARETO_DIALOG_H

#include "config_pages.h"
#include "QCheckBox"
#include "QComboBox"
#include <iostream>

class Paretodialog: public ConfigPages
{
    Q_OBJECT
public:
    Paretodialog();
private:
    QHBoxLayout * BinTypes;
    QCheckBox * Trend;
};

#endif // PARETO_DIALOG_H
