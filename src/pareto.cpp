#include "pareto.h"
#include <iostream>

CPareto::CPareto(const QVector<int> & bins):binValues(bins)
{
}


void CPareto::calculateChartData()
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
}


void CPareto::calculateTrendLineData()
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
     }
}

const QVector<QPair<int,int>> & CPareto::getBarValues()const
{
    return chartValues;
}

const QVector<QPair<int,int>> & CPareto::getLineValues()const
{
    return trendLineValues;
}
