#include "pareto.h"
#include <iostream>

CPareto::CPareto()
{
}


void CPareto::getChartData(const QVector<int> & binValues)
{
    for(int i=0; i<binValues.size(); ++i)
    {
        QVector<QPair<int,int>>::iterator j;
        for(j =chartValues.begin(); j!=chartValues.end(); ++j)
        {
            if (j->first==binValues[i])
            {
                ++j->second;
                break;
            }
        }
        if(j==chartValues.end())
             chartValues.push_back(qMakePair(binValues[i],1));
    }
    qSort(chartValues.begin(), chartValues.end(), [] (const QPair<int,int> &first, const QPair<int,int> & second) {
        return first.second>second.second;
    } );
    std::cout<<chartValues.size()<<std::endl;
}


void CPareto::getTrendLineData()
{
    int allSum = 0;
    for(int i=0; i<chartValues.size(); ++i)
    {
        allSum += chartValues[i].second;
    }
    int sum = 0;
    for(int i = 0; i < chartValues.size(); ++i)
    {
        sum+=chartValues[i].second;
        trendLineValues.push_back(qMakePair(i,sum*100/allSum));
        std::cout<<chartValues[i].first<<" "<<sum*100/allSum<<std::endl;
     }
   //qSort(trendLineValues.begin(), trendLineValues.end(), [] (const QPair<int,int> &first, const QPair<int,int> & second) {
   //    return first.second<second.second;
   // } );
    std::cout<<trendLineValues.size()<<std::endl;
}
