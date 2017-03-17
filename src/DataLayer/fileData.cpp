#include "fileData.h"

FileData::FileData() {}

FileData::FileData(CVectorCollection table,TableInfo info):m_table(table),m_tableinfo(info) {}

FileData::FileData(const FileData& second) : m_table(second.m_table),m_tableinfo(second.m_tableinfo) {}

CVectorCollection FileData::GetTable() const
{
	return m_table;
}

TableInfo  FileData::GetTableInfo() const
{
	return m_tableinfo;
}
