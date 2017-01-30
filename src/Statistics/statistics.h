#ifndef STATISTICS_H
#define STATISTICS_H

#include "Ivector.h"
#include <QMap>
#include <QVariant>

enum class EFunction
{
    Max,
    Min,
    Median,
    Average,
    StandardDeviation,
    Skewness,
    Kurtosis
};

class CStatistics
{
public:
    CStatistics();
    QMap<EFunction, double> run(const IVector & vec, QMap<EFunction, QVariant> mFuncArg)const;
    /*
     * gets
         statistics works on vec elements,
         mFuncArg is functions and arguments
         e.g.
         min,
         max,
         average
         ...
     * returns
        colculated values with map
        key is function name and value is colculated value
     */

};

#endif // STATISTICS_H
