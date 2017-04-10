#ifndef PARETO_H
#define PARETO_H

#include <QVector>
#include <QString>

class CPareto
{
public:
    CPareto(const QVector<int> &);
    void calculateChartData();
    void calculateTrendLineData();
    const QVector<QPair<int,int>> & getBarValues()const;
    const QVector<QPair<int,int>> & getLineValues()const;
    ~CPareto();
private:
    QVector<int> binValues;
    QVector<QPair<int,int>> trendLineValues;
    QVector<QPair<int,int>> chartValues;
};

#endif // PARETO_H
