#ifndef PARETO_H
#define PARETO_H

#include <QVector>

class CPareto
{
public:
    CPareto();
    void getChartData(const QVector<int> & binValues);
    ~CPareto();
    //QVector<int> trendLineValues;
    QVector<QPair<int,int>> chartValues;
};

#endif // PARETO_H
