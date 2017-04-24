#ifndef SUMMARY_BIN_YIELD_H
#define SUMMARY_BIN_YIELD_H


#include "table.h"
#include "global.h"
#include "itable.h"
#include "configuration.h"
#include <QVector>
#include <QVariant>

class BinSummary
{
public:
    BinSummary();
    ITablePtr run(ITablePtr table, const CConfiguration & config);
};

class YieldSummary
{
public:
    YieldSummary();
    ITablePtr run(ITablePtr table, const CConfiguration & config);
};

#endif // SUMMARY_BIN_YIELD_H
