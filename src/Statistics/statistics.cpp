#include "statistics.h"
#include <stdexcept>
#include <cmath>
#include <queue>

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

CStatistics::CStatistics()
{}

QMap<EFunction, double> CStatistics::run(const IVector & vec, QMap<EFunction, QVariant> FuncArg)const
{
    if (!vec.GetCount())
          throw std::logic_error("No any element for summary");

    if (FuncArg.isEmpty())
          throw std::logic_error("No any function for summary");

      QMap<EFunction, double> result;

      double dFirstElement = vec.GetValue(0).toDouble();

      double min = dFirstElement;
      double max = dFirstElement;
      double average;
      double standard_deviation;

      bool bMin = FuncArg.find(EFunction::Min) != FuncArg.end();
      bool bMax = FuncArg.find(EFunction::Max) != FuncArg.end();
      bool bMedian = FuncArg.find(EFunction::Median) != FuncArg.end();
      bool bAvg = FuncArg.find(EFunction::Average) != FuncArg.end();
      bool bStDev = FuncArg.find(EFunction::StandardDeviation) != FuncArg.end();
      bool bSkew = FuncArg.find(EFunction::Skewness) != FuncArg.end();
      bool bKurt = FuncArg.find(EFunction::Kurtosis) != FuncArg.end();

      double dElementsSum = dFirstElement;
      double dElementsSqrSum = dElementsSum * dFirstElement;
      double dElementsCubeSum = dElementsSqrSum * dFirstElement;
      double dElements4thSum = dElementsCubeSum * dFirstElement; //name must be change
      int iElementCount = vec.GetCount();

      std::priority_queue<double, std::vector<double>, min_heap_comparator> min_heap;
      std::priority_queue<double, std::vector<double>, max_heap_comparator> max_heap;
      min_heap.push(dFirstElement);

      for (int i=1; i< iElementCount; ++i)
      {
          double currentElement = vec.GetValue(i).toDouble();
          dElementsSum += currentElement;
          double SqrCurrentElement = currentElement * currentElement; // x^2
          dElementsSqrSum += SqrCurrentElement;
          double CubCurrentElement = SqrCurrentElement * currentElement; // x^3
          dElementsCubeSum += CubCurrentElement;
          double d4thCurrentElement = CubCurrentElement * currentElement; // x^4
          dElements4thSum += d4thCurrentElement;

          //min max
          if (currentElement > max)
              max = currentElement;
          if (currentElement < min)
              min = currentElement;

          //median
          bool current_median_heap = (min_heap.size() > max_heap.size()); // if equal to 0 then median is in max_heape else in min_heap
          double current_median;
          if (current_median_heap) //current median is in min_heap
              current_median = min_heap.top();
          else //current median is in max_heap
              current_median = max_heap.top();

          if (currentElement > current_median)
              min_heap.push(currentElement);
          else
              max_heap.push(currentElement);

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

      if (bMedian)
      {
          double median;
          //median
          if (min_heap.size() == max_heap.size())
              median = (min_heap.top() + max_heap.top())/2;
          else
              if (min_heap.size() > max_heap.size())
                  median = min_heap.top();
              else
                  median = max_heap.top();

          result[EFunction::Median] = median;
      }


      if (bAvg || bStDev || bSkew || bKurt)
        // average
        average = dElementsSum / iElementCount;
        if (bAvg)
            result[EFunction::Average] = average;

      if (bStDev || bSkew || bKurt)
      {
        // standard  deviation
        double dAvgMulSum = average * dElementsSum;
        double dCountMulSqrAvg = iElementCount * pow(average, 2);
        standard_deviation = sqrt((dElementsSqrSum - 2 * dAvgMulSum + dCountMulSqrAvg)/(iElementCount - 1));
        if (bStDev)
            result[EFunction::StandardDeviation] = standard_deviation;

          if (bSkew || bKurt)
          {
            // skewness
            double dAvgMulSqrSum = average * dElementsSqrSum;
            double dSqrAvgMulSum = dAvgMulSum * average;
            double dCountMulCubeAvg = dCountMulSqrAvg * average;
            double multiplier = iElementCount / ((iElementCount - 1) * (iElementCount - 2) * pow(standard_deviation, 3));
            if (bSkew)
            {
                result[EFunction::Skewness] = multiplier * (dElementsCubeSum - 3 * dAvgMulSqrSum + 3 * dSqrAvgMulSum - dCountMulCubeAvg);

            }

              if (bKurt)
              {
                  // kurtosis
                  multiplier *= (iElementCount + 1) / ((iElementCount - 3) * standard_deviation);
                  double dCubeSumMulAvg = dElementsCubeSum * average;
                  double dSqrSumMulSqrAvg = dAvgMulSqrSum * average;
                  double dCubeAvgMulSum = dSqrAvgMulSum * average;
                  double dCountMul4thAvg = dCountMulCubeAvg * average;
                  result[EFunction::Kurtosis] = multiplier * (dElements4thSum - 4 * dCubeSumMulAvg + 6 * dSqrSumMulSqrAvg - 4 * dCubeAvgMulSum + dCountMul4thAvg)
                          - (3 * pow((iElementCount - 1), 2)) / ((iElementCount - 2) * (iElementCount - 3));
              }
          }
      }

      if (bMin)
          result[EFunction::Min] = min;
      if (bMax)
          result[EFunction::Max] = max;

      return result;

}
