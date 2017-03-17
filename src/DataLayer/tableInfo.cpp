#include "tableInfo.h"

TableInfo::TableInfo():infoMap() {}

void TableInfo::add(ColumnType type, Index index)
{
	infoMap.insert(type,index);
}

/*
 *  Returns @index of Column with corresponding type
 */
Index TableInfo::GetColumnIndex(ColumnType type) const
{
	return infoMap[type];
}

/*
 *  Returns @columnType of Column with corresponding @index
 */
ColumnType TableInfo::GetColumnType(Index index) const
{
	for (auto val : infoMap.values())
	{
		if (val == index)
			return infoMap.key(val);
	}
	return ColumnType();
}

/*
 *  Returns Column names of table
 */
ColumnList TableInfo::GetColumns() const
{
	return infoMap.keys();
}
