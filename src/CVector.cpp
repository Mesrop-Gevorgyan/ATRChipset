#include "CVector.h"
#include <stdexcept>

// 
// CIntData implementation
//
CIntData::CIntData() : m_arr_data() {}

CIntData::CIntData(QVector<int> arr_data) : m_arr_data(arr_data) {}

int  CIntData::GetAt(int index) const throw()
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

QVariant CIntData::GetValue(int index) const
{
	return QVariant(m_arr_data[index]);
}

// 
// CDoubleData implementation
//
CDoubleData::CDoubleData() : m_arr_data() {}

CDoubleData::CDoubleData(QVector<double> arr_data) : m_arr_data(arr_data) {}

double  CDoubleData::GetAt(int index) const throw()
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

QVariant CDoubleData::GetValue(int index) const
{
	return QVariant(m_arr_data[index]);
}

//
//CStringData implementation
//
CStringData::CStringData() : m_arr_data() {}

CStringData::CStringData(QVector<QString> arr_data) : m_arr_data(arr_data) {}

QString  CStringData::GetAt(int index) const throw()
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

QVariant CStringData::GetValue(int index) const
{
	return QVariant(m_arr_data[index]);
}
//
// CDateTimeData implementation
//
CDateTimeData::CDateTimeData() : m_arr_data() {}

CDateTimeData::CDateTimeData(QVector<QDateTime> arr_data) : m_arr_data(arr_data) {}

QDateTime  CDateTimeData::GetAt(int index) const throw()
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

QVariant CDateTimeData::GetValue(int index) const
{
	return QVariant(m_arr_data[index]);
}

//
//CBoolData implementation
//
CBoolData::CBoolData() : m_arr_data() {}

CBoolData::CBoolData(QVector<bool> arr_data) : m_arr_data(arr_data) {}

bool  CBoolData::GetAt(int index) const throw()
{
	if (index >= m_arr_data.size() || index < 0)
		throw std::out_of_range("Going out of range of array !\n");
	else
		return m_arr_data[index];
}

int CBoolData::GetCount() const
{
	return m_arr_data.size();
}

QVariant CBoolData::GetValue(int index) const
{
	return QVariant(m_arr_data[index]);
}
