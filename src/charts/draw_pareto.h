#ifndef DRAW_PARETO_H
#define DRAW_PARETO_H

#include <QWidget>
#include <QtCharts/QChartView>
#include "pareto.h"

class DrawParetoChart: public QWidget
{
public:
    DrawParetoChart(CPareto *);
private:
    CPareto * pareto;
};

#endif //DRAW_PARETO_H
