#include "Vector.h"
#include <stdexcept>

// 
// CIntData implementation
//
CIntData::CIntData() : m_arr_data() {}

CIntData::CIntData(QVector<int> arr_data) : m_arr_data(arr_data) {}

int  CIntData::GetAt(unsigned index) const
{
	return m_arr_data[index];
}

int CIntData::GetCount() const
{
	return m_arr_data.size();
}

DataType CIntData::GetType() const
{
	return INT;
}

QVariant CIntData::GetValue(unsigned index) const 
{
       	return QVariant(m_arr_data[index]);
}

// 
// CDoubleData implementation
//
CDoubleData::CDoubleData() : m_arr_data() {}

CDoubleData::CDoubleData(QVector<double> arr_data) : m_arr_data(arr_data) {}

double  CDoubleData::GetAt(unsigned index) const
{
        return m_arr_data[index];
}

int CDoubleData::GetCount() const
{
	return m_arr_data.size();
}

DataType CDoubleData::GetType() const
{
	return DOUBLE;
}

QVariant CDoubleData::GetValue(unsigned index) const 
{
       return QVariant(m_arr_data[index]);
}

//
//CStringData implementation
//
CStringData::CStringData() : m_arr_data() {}

CStringData::CStringData(QVector<QString> arr_data) : m_arr_data(arr_data) {}

QString  CStringData::GetAt(unsigned index) const 
{
	return m_arr_data[index];
}

int CStringData::GetCount() const
{
	return m_arr_data.size();
}

DataType CStringData::GetType() const
{
	return STRING;
}

QVariant CStringData::GetValue(unsigned index) const 
{

        return QVariant(m_arr_data[index]);
}
//
// CDateTimeData implementation
//
CDateTimeData::CDateTimeData() : m_arr_data() {}

CDateTimeData::CDateTimeData(QVector<QDateTime> arr_data) : m_arr_data(arr_data) {}

QDateTime  CDateTimeData::GetAt(unsigned index) const 
{
        return m_arr_data[index];
}

int CDateTimeData::GetCount() const
{
	return m_arr_data.size();
}

DataType CDateTimeData::GetType() const
{
	return DATETIME;
}

QVariant CDateTimeData::GetValue(unsigned index) const 
{
	return QVariant(m_arr_data[index]);
}

//
//CBoolData implementation
//
CBoolData::CBoolData() : m_arr_data() {}

CBoolData::CBoolData(QVector<bool> arr_data) : m_arr_data(arr_data) {}

bool  CBoolData::GetAt(unsigned index) const
{
	return m_arr_data[index];
}

int CBoolData::GetCount() const
{
	return m_arr_data.size();
}

DataType CBoolData::GetType() const
{
	return BOOL;
}

QVariant CBoolData::GetValue(unsigned index) const
{
       return QVariant(m_arr_data[index]);
}
