#include "pareto_config_page.h"
#include <QFormLayout>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include "grouping.h"

CParetoConfigPage::CParetoConfigPage(): CConfigPage()
{
    QHBoxLayout * ParetoLayout = new  QHBoxLayout();
    QVBoxLayout * TypeStackedLayout = new QVBoxLayout();
    QFormLayout * typeForm   = new QFormLayout();
    QLabel * labelType = new QLabel("Bin type:");

    QVector<QString> bin_types{"   HBin", "   SBin"};
    QComboBox * type_combo = new QComboBox();
    //connect(type_combo, SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboBox_currentIndexChanged(const QString &)));
    //connect(type_combo, SIGNAL(activated(int)), stackedLayout, SLOT(setCurrentIndex(int)));
    for (int i = 0; i < bin_types.size(); ++i)
        type_combo->addItem(bin_types[i]);
    QCheckBox * trend = new QCheckBox("Trend line");

    typeForm->addRow(labelType, type_combo);
    typeForm->addRow(trend);
    TypeStackedLayout->addLayout(typeForm);
    //TypeStackedLayout->addLayout(stackedLayout);
    CGrouping * gr = new CGrouping();
    //gr->show();
    ParetoLayout->addLayout(TypeStackedLayout);
    ParetoLayout->addWidget(gr);
    QWidget::setLayout(ParetoLayout);
}


