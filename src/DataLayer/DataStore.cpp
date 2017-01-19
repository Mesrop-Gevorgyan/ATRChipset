#include "DataStore.h"

DataStore::DataStore(): m_data() {}

void DataStore::add(FileInfo fileInfo, CVectorCollection binData)
{
	m_data.insert(fileInfo, binData);
}

CVectorCollection DataStore::getBinData(const FileInfo& fileInfo) const
{
	if (m_data.contains(fileInfo))
		return m_data[fileInfo];
	else
		throw std::exception("BinData with this context does not exist!\n");
}

bool operator<(const FileInfo& info1, const FileInfo& info2)
{
	if (info1.m_date < info2.m_date)
		return true;
	else
		return false;
}