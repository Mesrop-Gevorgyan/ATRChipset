#include "draw_pareto.h"

#include <QLayout>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <iostream>

QT_CHARTS_USE_NAMESPACE


DrawParetoChart::DrawParetoChart():QWidget()
{
    QBarSet *set0 = new QBarSet("HBin");
    *set0 << 6 << 5 << 4 << 3 << 2;
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pareto chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << "30" << "12" << "10" << "11" << "20" << "3";
    QBarCategoryAxis *axis = new QBarCategoryAxis();

    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
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
