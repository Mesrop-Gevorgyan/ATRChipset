#include "statistics_config_page.h"
#include <QFormLayout>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QLayout>
#include <QHBoxLayout>
#include "grouping.h"

CStatisticsConfigPage::CStatisticsConfigPage(): CConfigPage()
{
    QHBoxLayout * StatisticsLayout = new  QHBoxLayout();
    QVBoxLayout * TypeStackedLayout = new QVBoxLayout();
    QFormLayout * typeForm   = new QFormLayout();
    QLabel * labelType = new QLabel("Type:");


    ParameterSummaryTypeWidgets = new ParamSumTypes();
    BinSummaryTypeWidgets       = new YieldBinSumTypes();

    QStackedLayout * stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(ParameterSummaryTypeWidgets);
    stackedLayout->addWidget(BinSummaryTypeWidgets);

    QVector<QString> statistics_types{"   Parameter Summary", "   Bin/Yield Summary"};
    //QComboBox * type_combo = new QComboBox();
    type_combo = new QComboBox();
    //connect(type_combo, SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboBox_currentIndexChanged(const QString &)));
    connect(type_combo, SIGNAL(activated(int)), stackedLayout, SLOT(setCurrentIndex(int)));
    for (int i = 0; i < statistics_types.size(); ++i)
        type_combo->addItem(statistics_types[i]);


    typeForm->addRow(labelType, type_combo);
    TypeStackedLayout->addLayout(typeForm);
    TypeStackedLayout->addLayout(stackedLayout);
    //CGrouping * gr = new CGrouping();
    gr = new CGrouping();
    //gr->show();
    StatisticsLayout->addLayout(TypeStackedLayout);
    StatisticsLayout->addWidget(gr);
    QWidget::setLayout(StatisticsLayout);
}

YieldBinSumTypes::YieldBinSumTypes(): QWidget()
{
    QLayout * l = new QVBoxLayout();
    QListWidget * GrListWidg = new QListWidget();
    QVector<QString> grItems{"HBin", "SBin"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        m_items.append(listItem);
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}

QVector<QListWidgetItem *> YieldBinSumTypes::getItems()const
{
    return m_items;
}


ParamSumTypes::ParamSumTypes(): QWidget()
{
    QLayout * l = new QVBoxLayout();
    QListWidget * GrListWidg = new QListWidget();
    QVector<QString> grItems{"Min","Max","Median","Average","Standard deviation","Skewness","Kurtosis"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        m_items.append(listItem);
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}

QVector<QListWidgetItem *> ParamSumTypes::getItems()const
{
    return m_items;
}

CConfiguration CStatisticsConfigPage::getConfig()const
{
    CConfiguration config;
    QString combo_val = type_combo->currentText();
    QVector<QString> params_list;
    if(combo_val == "   Parameter Summary")
    {

        config.setType("Parameter Summary");
        params_list = QVector<QString>{"Min","Max","Median","Average","StandardDeviation","Skewness","Kurtosis"};
        QVector<QListWidgetItem *> items = ParameterSummaryTypeWidgets->getItems();
        for (int i=0; i<items.size(); ++i)
        {
            config.setParameter(params_list[i],items[i]->isSelected());
        }

    }
    else
        if (combo_val == "   Bin/Yield Summary")
        {
            config.setType("Bin/Yield");
            params_list = QVector<QString>{"SBin","HBin"};
            QVector<QListWidgetItem *> items = BinSummaryTypeWidgets->getItems();
            for (int i=0; i<items.size(); ++i)
            {
                config.setParameter(params_list[i],items[i]->isSelected());
            }
        }

    QMap<QString,QListWidgetItem *> grouping_items = gr->getItems();
    for (auto iter = grouping_items.begin(); iter != grouping_items.end(); ++iter)
    {
        config.setParameter(iter.key(),iter.value()->isSelected());
    }

    return config;
}
