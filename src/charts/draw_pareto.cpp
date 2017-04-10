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


DrawParetoChart::DrawParetoChart(const QVector<QPair<int,int>> & chartValues, const QVector<QPair<int,int>> & trendLineValues):QWidget()
{

    QBarSet *set0 = new QBarSet("HBin");
    for (int i=0; i<chartValues.size(); ++i)
    {
        set0->append(chartValues[i].second);
    }
    //*set0 << 6 << 5 << 4 << 3 << 2;
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);

    QSplineSeries * lineSeries = new QSplineSeries();
    for (int i=0; i<trendLineValues.size(); ++i)
    {
        lineSeries->append(trendLineValues[i].first,trendLineValues[i].second);
    }
    lineSeries->setName("Trend Line");
    chart->addSeries(lineSeries);
    chart->setTitle("Pareto chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    for (int i=0; i<chartValues.size(); ++i)
    {
        categories.append(QString::number(chartValues[i].first));
    }
    //categories << "30" << "12" << "10" << "11" << "20" << "3";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    //axis->append(lineSeries);
    //chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->setAxisX(axis,lineSeries);


    QValueAxis *axisY1 = new QValueAxis();
    QValueAxis *axisY2 = new QValueAxis();
    chart->setAxisY(axisY1, series);
    chart->addAxis(axisY2, Qt::AlignRight);
    chart->setAxisY(axisY2, lineSeries);
    axisY2->setRange(0,100);
    axis->setRange(QString("5"), QString("1"));

    //axisY->setRange(0, 100);

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
