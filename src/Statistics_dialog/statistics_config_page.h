#ifndef STATISTICS_CONFIG_PAGE_H
#define STATISTICS_CONFIG_PAGE_H

#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <QStackedLayout>
#include <configuration.h>
#include <QComboBox>
#include <QListWidgetItem>
#include "grouping.h"

class CConfigPage: public QWidget
{
    Q_OBJECT
public:
    CConfigPage():QWidget()
    {}
};

class YieldBinSumTypes: public QWidget
{
public:
    YieldBinSumTypes();
    QVector<QListWidgetItem *> getItems()const;
private:
    QVector<QListWidgetItem *> m_items;
};

class ParamSumTypes:public QWidget
{
public:
    ParamSumTypes();
    QVector<QListWidgetItem *> getItems()const;
private:
    QVector<QListWidgetItem *> m_items;
};

class CStatisticsConfigPage: public CConfigPage
{
    Q_OBJECT
public:
    CStatisticsConfigPage();
    CConfiguration getConfig()const;
private:
    QComboBox * type_combo;
    ParamSumTypes * ParameterSummaryTypeWidgets;
    YieldBinSumTypes * BinSummaryTypeWidgets;
    CGrouping * gr ;
};



#endif // STATISTICS_CONFIG_PAGE_H
