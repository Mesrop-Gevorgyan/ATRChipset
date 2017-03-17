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
*  Returns Column names of table
*/
ColumnList TableInfo::GetColumns() const
{
	return infoMap.keys();
}


