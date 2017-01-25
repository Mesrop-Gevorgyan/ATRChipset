#include "parameter_summary.h"
#include <stdexcept>
#include <cmath>
#include <queue>
#include <vector>

class max_heap_comparator {
public:
 bool operator()(double i, double j)
 {
    return i < j;
 }
};

class min_heap_comparator {
public:
 bool operator()(double i, double j)
 {
    return i > j;
 }
};

CParameterSummary::CParameterSummary()
{}

void CParameterSummary::run(const QVector<double> & vec)
{
    if (!vec.size())
        throw std::logic_error("No any element for summary");

    double dElementsSum = vec[0];
    double dElementsSqrSum = dElementsSum * vec[0];
    double dElementsCubeSum = dElementsSqrSum * vec[0];
    double dElements4thSum = dElementsCubeSum * vec[0]; //name must be change
    m_min = vec[0];
    m_max = vec[0];
    int iElementCount = vec.size();

    std::priority_queue<double, std::vector<double>, min_heap_comparator> min_heap;
    std::priority_queue<double, std::vector<double>, max_heap_comparator> max_heap;
    min_heap.push(vec[0]);

    for (int i=1; i< iElementCount; ++i)
    {
        double currentElement = vec[i];
        dElementsSum += currentElement;
        currentElement *= vec[i]; // x^2
        dElementsSqrSum += currentElement;
        currentElement *= vec[i]; // x^3
        dElementsCubeSum += currentElement;
        currentElement *= vec[i]; // x^4
        dElements4thSum += currentElement;

        //min max
        if (vec[i] > m_max)
            m_max = vec[i];
        if (vec[i] < m_min)
            m_min = vec[i];

        //median
        bool current_median_heap = (min_heap.size() > max_heap.size()); // if equal to 0 then median is in max_heape else in min_heap
        double current_median;
        if (current_median_heap) //current median is in min_heap
            current_median = min_heap.top();
        else //current median is in max_heap
            current_median = max_heap.top();

        if (vec[i] > current_median)
            min_heap.push(vec[i]);
        else
            max_heap.push(vec[i]);

        if (max_heap.size() > (i + 1)/2)
        {
            double tmp = max_heap.top();
            max_heap.pop();
            min_heap.push(tmp);
        }
        else
            if (min_heap.size() > (i + 1)/2)
            {
                double tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }

    }

    //median
    if (min_heap.size() == max_heap.size())
        m_median = (min_heap.top() + max_heap.top())/2;
    else
        if (min_heap.size() > max_heap.size())
            m_median = min_heap.top();
        else
            m_median = max_heap.top();


    // average
    m_average = dElementsSum / iElementCount;

    // standard  deviation
    double dAvgMulSum = m_average * dElementsSum;
    double dCountMulSqrAvg = iElementCount * pow(m_average, 2);
    m_standard_deviation = sqrt((dElementsSqrSum - 2 * dAvgMulSum + dCountMulSqrAvg)/(iElementCount - 1));

    // skewness

    double dAvgMulSqrSum = m_average * dElementsSqrSum;
    double dSqrAvgMulSum = dAvgMulSum * m_average;
    double dCountMulCubeAvg = dCountMulSqrAvg * m_average;
    double multiplier = iElementCount / ((iElementCount - 1) * (iElementCount - 2) * pow(m_standard_deviation, 3));
    m_skewness = multiplier * (dElementsCubeSum - 3 * dAvgMulSqrSum + 3 * dSqrAvgMulSum - dCountMulCubeAvg);

    // kurtosis
    multiplier *= (iElementCount + 1) / ((iElementCount - 3) * m_standard_deviation);
    double dCubeSumMulAvg = dElementsCubeSum * m_average;
    double dSqrSumMulSqrAvg = dAvgMulSqrSum * m_average;
    double dCubeAvgMulSum = dSqrAvgMulSum * m_average;
    double dCountMul4thAvg = dCountMulCubeAvg * m_average;
    m_kurtosis = multiplier * (dElements4thSum - 4 * dCubeSumMulAvg + 6 * dSqrSumMulSqrAvg - 4 * dCubeAvgMulSum + dCountMul4thAvg)
            - (3 * pow((iElementCount - 1), 2)) / ((iElementCount - 2) * (iElementCount - 3));

}

double CParameterSummary::get_min()const
{
    return m_min;
}
double CParameterSummary::get_max()const
{
    return m_max;
}
double CParameterSummary::get_median()const
{
    return m_median;
}
double CParameterSummary::get_average()const
{
    return m_average;
}
double CParameterSummary::get_standard_deviation()const
{
    return m_standard_deviation;
}
double CParameterSummary::get_skewness()const
{
    return m_skewness;
}
double CParameterSummary::get_kurtosis()const
{
    return m_kurtosis;
}
