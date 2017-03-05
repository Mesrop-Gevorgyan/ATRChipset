#include "pareto_dialog.h"

Paretodialog::Paretodialog(): ConfigPages()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    BinTypes = new QHBoxLayout();
    QLabel * label = new QLabel("Bin Types:");
    label->setFont(font);
    label->setStyleSheet("QLabel { color : #00009c; } ");
    QComboBox * combobox = new QComboBox();
    combobox->setFont(font);
    combobox->setStyleSheet("QComboBox { color : #007fff; } ");
    combobox->addItem("HBin");
    combobox->addItem("SBin");
    BinTypes->addWidget(label);
    BinTypes->addWidget(combobox);
    QCheckBox * trend = new QCheckBox("Trend");
    trend->setStyleSheet("QCheckBox { color : #007fff; }");
    trend->setFont(font);
    QVBoxLayout * vbox = new QVBoxLayout();
    vbox->addLayout(BinTypes);
    vbox->addWidget(trend);
    gridlayout->addLayout(vbox,0,15,4,20);
}
