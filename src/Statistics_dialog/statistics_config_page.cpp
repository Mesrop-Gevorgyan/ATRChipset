#include "statistics_config_page.h"
#include <QFormLayout>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QLayout>

CStatisticsConfigPage::CStatisticsConfigPage(): CConfigPage()
{
    verLay = new QVBoxLayout();
    QFormLayout * typeForm   = new QFormLayout();
    QLabel * labelType = new QLabel("Type:");

    QWidget * yieldTypeWidgets            = new YieldBinSumTypes();
    QWidget * ParameterSummaryTypeWidgets = new ParamSumTypes();
    QWidget * BinSummaryTypeWidgets       = new YieldBinSumTypes();

    stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(yieldTypeWidgets);
    stackedLayout->addWidget(ParameterSummaryTypeWidgets);
    stackedLayout->addWidget(BinSummaryTypeWidgets);

    QVector<QString> statistics_types{"   Yield", "   Parameter Summary", "   Bin Summary"};
    QComboBox * type_combo = new QComboBox();
    //connect(type_combo, SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboBox_currentIndexChanged(const QString &)));
    connect(type_combo, SIGNAL(activated(int)), stackedLayout, SLOT(setCurrentIndex(int)));
    for (int i = 0; i < statistics_types.size(); ++i)
        type_combo->addItem(statistics_types[i]);


    typeForm->addRow(labelType, type_combo);
    verLay->addLayout(typeForm);
    verLay->addLayout(stackedLayout);
    QWidget::setLayout(verLay);
}

YieldBinSumTypes::YieldBinSumTypes(): QWidget()
{
    QLayout * l = new QVBoxLayout();
    QListWidget * GrListWidg = new QListWidget();
    QVector<QString> grItems{"HBin", "SBin"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}

ParamSumTypes::ParamSumTypes(): QWidget()
{
    QLayout * l = new QVBoxLayout();
    QListWidget * GrListWidg = new QListWidget();
    QVector<QString> grItems{"Min","Max","Median","Average","Standard deviation","Skewness","Kurtosis"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}
