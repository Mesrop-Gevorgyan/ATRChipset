#include <QApplication>
#include <QMainWindow>
#include <iostream>

#include "pareto.h"
#include "draw_pareto.h"



int main(int argc, char *argv[])
{  
    QApplication a(argc, argv);
    QVector<int> vec={1,3,2,1,1,4,4,3,4,5,4};
    CPareto * p =new CPareto(vec);
    DrawParetoChart * d = new DrawParetoChart(p);
    d->show();

    return a.exec();
}
