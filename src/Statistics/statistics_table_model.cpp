#include "statistics_table_model.h"
#include <QString>

//StatisticsTable::StatisticsTable(ITablePtr table, QWidget * parent): QAbstractTableModel(parent), m_table(table)
StatisticsTable::StatisticsTable(ITablePtr table, QWidget * parent): QAbstractTableModel(parent), m_table(table)
{}

int StatisticsTable::rowCount(const QModelIndex & parent)const
{
    QString first_col_name = m_table->GetColumnName(0);
    return  m_table->GetColumnData(first_col_name)->GetCount();
}

int StatisticsTable::columnCount(const QModelIndex & parent)const
{
    return m_table->GetCount();
}

QVariant StatisticsTable::data(const QModelIndex & index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    QString col_name = m_table->GetColumnName(index.column());
    QVariant val;
    /*if (col_name == "Parameter")
        return  m_table->GetColumnData(col_name)->GetStringData()->GetAt(index.row());
    return  m_table->GetColumnData(col_name)->GetDoubleData()->GetAt(index.row());*/

    switch(m_table->GetColumnData(col_name)->GetType())
    {
    case DataType::INT:
        val = m_table->GetColumnData(col_name)->GetIntData()->GetAt(index.row());
        break;
    case DataType::DOUBLE:
        val = m_table->GetColumnData(col_name)->GetDoubleData()->GetAt(index.row());
        break;
    case DataType::STRING:
        val = m_table->GetColumnData(col_name)->GetStringData()->GetAt(index.row());
        break;
    }
    return val;
}

QVariant StatisticsTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
             QString col_name = m_table->GetColumnName(section);
            return m_table->GetColumnData(col_name)->GetName();
        }
        if (orientation == Qt::Vertical) {
            return section+1;
        }
    }
    return QVariant();
}



