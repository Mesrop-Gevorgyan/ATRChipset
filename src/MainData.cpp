#include "MainData.h"

//
// Operator < for context class
// Without this cant insert Context to map
//
bool operator<(const Context& context1, const Context& context2)
{
	if (context1.GetLot() < context2.GetLot())
		return true;
	else
		if (context1.GetWafer() < context2.GetWafer())
			return true;
		else
			if (context1.GetDevice() < context2.GetDevice())
				return true;
			else
				return false;
}

MainData::MainData(): m_data() {}

void MainData::add(FileInfo fileInfo, QVector<IVector*> binData)
{
	m_data.insert(fileInfo, binData);
}

QVector<IVector*> MainData::getBinData(const FileInfo& fileInfo) const
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