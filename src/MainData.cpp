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

bool operator<(const FileInfo& info1, const FileInfo& info2)
{
	if (info1.m_date < info2.m_date)
		return true;
	else
		return info1.m_context < info2.m_context;
}

//
// class Context definition
//
Context::Context() : m_lot(),m_wafer(),m_device() {}

Context::Context(QString lot,QString wafer,QString device) 
			: m_lot(lot) , m_wafer(wafer) ,m_device(device) {}

QString Context::GetLot() const
{
	return m_lot;
}

QString Context::GetWafer() const
{
	return m_wafer;
}

QString Context::GetDevice() const
{
	return m_device;
}

//
// class MainData definition
//
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

