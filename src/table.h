#ifndef TABLE_H
#define TABLE_H

#include "itable.h"
#include "global.h"
#include "Vector.h"
#include <QMap>

class CTable:public ITable
{
public:
    CTable();
    IColumnPtr GetColumnData(Field const& field) const;
    int GetCount() const;
    QString GetColumnName(int index) const;
    int GetFieldIndex(Field const& field) const;
    void addColumn(const IColumnPtr column);
private:
    QVector<IColumnPtr> m_data;
    QMap<Field,int> m_field_index;
};

#endif // TABLE_H
