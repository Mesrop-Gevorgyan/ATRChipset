#include <QApplication>
#include <QMainWindow>
#include <iostream>

#include "pareto.h"
#include "draw_pareto.h"



int main(int argc, char *argv[])
{  
    QApplication a(argc, argv);
    QVector<int> vec={1,3,2,1,1,4,4,3,4,5,4};
    CPareto * p =new CPareto();
    p->getChartData(vec);
    //for(QVector<QPair<int,int>>::iterator i = p->chartValues.begin(); i!=p->chartValues.end(); ++i)
    //{
      // std::cout<<i->first<<" "<<i->second<<std::endl;
    //}
    DrawParetoChart * d = new DrawParetoChart();
    d->show();

    return a.exec();
}
