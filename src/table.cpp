#include "table.h"

CTable::CTable()
{

}

void CTable::addColumn(const IColumnPtr column)
{
    m_data.push_back(column);
    m_field_index.insert(column->GetName(),m_data.size() - 1);
}

IColumnPtr CTable::GetColumnData(const Field &field) const
{
    if (m_field_index.find(field) == m_field_index.end())
        return IColumnPtr();
    return m_data[m_field_index[field]];
}

QString CTable::GetColumnName(int index) const
{
    return m_data[index]->GetName();
}

int CTable::GetCount() const
{
    return m_data.size();
}

int CTable::GetFieldIndex(const Field &field) const
{
    if (m_field_index.find(field) == m_field_index.end())
        return -1;
    return m_field_index[field];

}
