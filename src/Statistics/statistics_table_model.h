#ifndef STATISTICS_TABLE_H
#define STATISTICS_TABLE_H


#include <QAbstractTableModel>
#include <QWidget>
#include "global.h"
#include "itable.h"
#include "table.h"
#include "icolumn.h"
#include "column.h"


class StatisticsTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    //StatisticsTable(ITablePtr, QWidget *parent=0);
    StatisticsTable(ITablePtr, QWidget *parent=0);
    int rowCount(const QModelIndex & parent = QModelIndex())const;
    int columnCount(const QModelIndex & parent = QModelIndex())const;
    QVariant data(const QModelIndex & index, int role = Qt:: DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    ITablePtr m_table;
};

#endif // STATISTICS_TABLE_H
