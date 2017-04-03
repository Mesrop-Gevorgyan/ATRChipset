#include "pareto.h"


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
             chartValues.append(qMakePair(binValues[i],1));
    }
    qSort(chartValues.begin(), chartValues.end(), [] (const QPair<int,int> &first, const QPair<int,int> & second) {
        return first.second>second.second;
    } );
}


