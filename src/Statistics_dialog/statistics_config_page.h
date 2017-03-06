#ifndef STATISTICS_CONFIG_PAGE_H
#define STATISTICS_CONFIG_PAGE_H

#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <QStackedLayout>

class CConfigPage: public QWidget
{
    Q_OBJECT
public:
    CConfigPage():QWidget()
    {}
};

class CStatisticsConfigPage: public CConfigPage
{
    Q_OBJECT
public:
    CStatisticsConfigPage();
private:
    QVBoxLayout * verLay;
    QStackedLayout * stackedLayout;
};

class YieldBinSumTypes: public QWidget
{
public:
    YieldBinSumTypes();
};

class ParamSumTypes:public QWidget
{
public:
    ParamSumTypes();
};

#endif // STATISTICS_CONFIG_PAGE_H
