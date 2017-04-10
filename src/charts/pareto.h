#ifndef PARETO_H
#define PARETO_H

#include <QVector>
#include <QString>

class CPareto
{
public:
    CPareto();
    void getChartData(const QVector<int> & binValues);
    void getTrendLineData();
    ~CPareto();
private:
    QVector<QPair<int,int>> trendLineValues;
    QVector<QPair<int,int>> chartValues;
};

#endif // PARETO_H
