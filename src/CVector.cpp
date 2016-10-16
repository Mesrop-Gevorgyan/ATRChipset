#include "CVector.h"
#include <stdexcept>

// 
// CIntData implementation
//
CIntData::CIntData() : m_arr_data() {}

CIntData::CIntData(QVector<int> arr_data) : m_arr_data(arr_data) {}

int  CIntData::GetAt(int index) const
{
	if (index >= m_arr_data.size() || index < 0)
		throw std::out_of_range("Going out of range of array !\n");
	else
		return m_arr_data[index];
}

int CIntData::GetCount() const
{
	return m_arr_data.size();
}

// 
// CDoubleData implementation
//
CDoubleData::CDoubleData() : m_arr_data() {}

CDoubleData::CDoubleData(QVector<double> arr_data) : m_arr_data(arr_data) {}

double  CDoubleData::GetAt(int index) const
{
	if (index >= m_arr_data.size() || index < 0)
		throw std::out_of_range("Going out of range of array !\n");
	else
		return m_arr_data[index];
}

int CDoubleData::GetCount() const
{
	return m_arr_data.size();
}

//
//CStringData implementation
//
CStringData::CStringData() : m_arr_data() {}

CStringData::CStringData(QVector<QString> arr_data) : m_arr_data(arr_data) {}

QString  CStringData::GetAt(int index) const
{
	if (index >= m_arr_data.size() || index < 0)
		throw std::out_of_range("Going out of range of array !\n");
	else
		return m_arr_data[index];
}

int CStringData::GetCount() const
{
	return m_arr_data.size();
}

//
// CDateTimeData implementation
//
CDateTimeData::CDateTimeData() : m_arr_data() {}

CDateTimeData::CDateTimeData(QVector<QDateTime> arr_data) : m_arr_data(arr_data) {}

QDateTime  CDateTimeData::GetAt(int index) const
{
	if (index >= m_arr_data.size() || index < 0)
		throw std::out_of_range("Going out of range of array !\n");
	else
		return m_arr_data[index];
}

int CDateTimeData::GetCount() const
{
	return m_arr_data.size();
}