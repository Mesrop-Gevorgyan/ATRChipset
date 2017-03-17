#ifndef __TABLEINFO__
#define __TABLEINFO__

#include <QMap>
#include "global.h"
#include <QString>

class TableInfo
{
public:
	TableInfo();
	void add(ColumnType,Index);
	Index GetColumnIndex(ColumnType) const;
	ColumnType GetColumnType(Index index) const;
	ColumnList GetColumns() const;
private:
	QMap<ColumnType, Index> infoMap;
};

#endif // __TABLEINFO__
