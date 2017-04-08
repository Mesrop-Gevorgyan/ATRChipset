#include "analisys_selection.h"
#include "ui_analisys_selection.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>

AnalisysSelection::AnalisysSelection(/*QWidget* parent*/)
                 : QWidget()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    BinTypes = new QVBoxLayout();
    QLabel * label = new QLabel("Analysis Selection");
    label->setFont(font);
    label->setStyleSheet("QLabel { color : #00009c; } ");

    QCheckBox* checkBox1 = new QCheckBox("Bin Pareto 1");
    QCheckBox* checkBox2 = new QCheckBox("Wafer 1");
    QCheckBox* checkBox3 = new QCheckBox("Bin Pareto 2");

    BinTypes->addWidget(label);
    BinTypes->addWidget(checkBox1);
    BinTypes->addWidget(checkBox2);
    BinTypes->addWidget(checkBox3);

    QPushButton* newButton = new QPushButton();
    newButton->setFixedSize(200,40);
    newButton->setText("New");

    QPushButton* editButton = new QPushButton();
    editButton->setFixedSize(200,40);
    editButton->setText("Edit");

    QVBoxLayout* stepLayout = new QVBoxLayout();
    stepLayout->addWidget(newButton);
    stepLayout->addWidget(editButton);

    QHBoxLayout * vbox = new QHBoxLayout();
    vbox->addLayout(BinTypes);
    vbox->addLayout(stepLayout);

    QGridLayout* gridlayout = new QGridLayout();
    gridlayout->addLayout(vbox,0,15,4,20);
    QWidget::setLayout(gridlayout);
}

AnalisysSelection::~AnalisysSelection()
{
}
