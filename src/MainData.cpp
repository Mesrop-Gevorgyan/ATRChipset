#include "MainData.h"

MainData::MainData(): m_data() {}

void MainData::add(FileInfo fileInfo, QVector<IVector*> binData)
{
	m_data.insert(fileInfo, binData);
}

QVector<IVector*> MainData::getBinData(const FileInfo& fileInfo) const throw()
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
		return info1.m_context < info2.m_context;
}
