#include "draw_pareto.h"

#include <QString>
#include <QLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <iostream>

QT_CHARTS_USE_NAMESPACE


DrawParetoChart::DrawParetoChart(CPareto * p):QWidget()
{
    pareto = p;
    pareto->calculateChartData();
    pareto->calculateTrendLineData();
    QBarSet *set0 = new QBarSet("HBin");
    for (int i=0; i<p->getBarValues().size(); ++i)
    {
        set0->append(p->getBarValues()[i].second);
    }
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);

    QSplineSeries * lineSeries = new QSplineSeries();
    for (int i=0; i<p->getLineValues().size(); ++i)
    {
        lineSeries->append(p->getLineValues()[i].first,p->getLineValues()[i].second);
    }
    lineSeries->setName("Trend Line");
    chart->addSeries(lineSeries);
    chart->setTitle("Pareto chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    for (int i=0; i<p->getBarValues().size(); ++i)
    {
        categories.append(QString::number(p->getBarValues()[i].first));
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->setAxisX(axis, series);
    chart->setAxisX(axis,lineSeries);


    QValueAxis *axisY1 = new QValueAxis();
    QValueAxis *axisY2 = new QValueAxis();
    chart->setAxisY(axisY1, series);
    chart->addAxis(axisY2, Qt::AlignRight);
    chart->setAxisY(axisY2, lineSeries);
    axisY2->setRange(0,100);
    //axis->setRange(QString("5"), QString("1"));

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumWidth(500);
    chartView->setMinimumHeight(300);
    QLayout * l = new QVBoxLayout();


    l->addWidget(chartView);
    QWidget::setLayout(l);
}
