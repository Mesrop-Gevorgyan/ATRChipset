#ifndef DRAW_PARETO_H
#define DRAW_PARETO_H

#include <QWidget>
#include <QtCharts/QChartView>
#include "pareto.h"

class DrawParetoChart: public QWidget
{
public:
    DrawParetoChart(const QVector<QPair<int,int>> &chartValues, const QVector<QPair<int,int>> &);
};

#endif //DRAW_PARETO_H
