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
// CIntDataGroup implementation
//

CIntDataGroup::CIntDataGroup(QVector<CIntDataPtr> vecs) : m_vecs(vecs) {}

int CIntDataGroup::GetAt(unsigned index) const
{
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");
	
	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return m_vecs[i]->GetAt(index);
		else
			index -= m_vecs[i]->GetCount();
	}
}

QVariant CIntDataGroup::GetValue(unsigned index) const
{
	
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return QVariant(m_vecs[i]->GetAt(index));
		else
			index -= m_vecs[i]->GetCount();
	}	
}
int CIntDataGroup::GetCount() const
{
	int count = 0;

	for (auto vec : m_vecs)
		count += vec->GetCount();

	return count;
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
// CDoubleDataGroup implementation
//
CDoubleDataGroup::CDoubleDataGroup(QVector<CDoubleDataPtr> vecs) : m_vecs(vecs) {}

double CDoubleDataGroup::GetAt(unsigned index) const
{
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return m_vecs[i]->GetAt(index);
		else
			index -= m_vecs[i]->GetCount();
	}
}

QVariant CDoubleDataGroup::GetValue(unsigned index) const
{

	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return QVariant(m_vecs[i]->GetAt(index));
		else
			index -= m_vecs[i]->GetCount();
	}
}
int CDoubleDataGroup::GetCount() const
{
	int count = 0;

	for (auto vec : m_vecs)
		count += vec->GetCount();

	return count;
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
// CStringDataGroup implementation
//
CStringDataGroup::CStringDataGroup(QVector<CStringDataPtr> vecs) : m_vecs(vecs) {}

QString CStringDataGroup::GetAt(unsigned index) const
{
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return m_vecs[i]->GetAt(index);
		else
			index -= m_vecs[i]->GetCount();
	}
}

QVariant CStringDataGroup::GetValue(unsigned index) const
{

	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return QVariant(m_vecs[i]->GetAt(index));
		else
			index -= m_vecs[i]->GetCount();
	}
}

int CStringDataGroup::GetCount() const
{
	int count = 0;

	for (auto vec : m_vecs)
		count += vec->GetCount();

	return count;
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
// CDateTimeDataGroup implementation
//
CDateTimeDataGroup::CDateTimeDataGroup(QVector<CDateTimeDataPtr> vecs) : m_vecs(vecs) {}

QDateTime CDateTimeDataGroup::GetAt(unsigned index) const
{
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return m_vecs[i]->GetAt(index);
		else
			index -= m_vecs[i]->GetCount();
	}
}

QVariant CDateTimeDataGroup::GetValue(unsigned index) const
{

	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return QVariant(m_vecs[i]->GetAt(index));
		else
			index -= m_vecs[i]->GetCount();
	}
}

int CDateTimeDataGroup::GetCount() const
{
	int count = 0;

	for (auto vec : m_vecs)
		count += vec->GetCount();

	return count;
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

// 
// CBoolDataGroup implementation
//
CBoolDataGroup::CBoolDataGroup(QVector<CBoolDataPtr> vecs) : m_vecs(vecs) {}

bool CBoolDataGroup::GetAt(unsigned index) const
{
	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return m_vecs[i]->GetAt(index);
		else
			index -= m_vecs[i]->GetCount();
	}
}

QVariant CBoolDataGroup::GetValue(unsigned index) const
{

	if (index >= this->GetCount())
		throw std::out_of_range("Going out of range of Grouped vector\n");

	for (int i = 0; i< m_vecs.count(); ++i)
	{
		if (index < m_vecs[i]->GetCount())
			return QVariant(m_vecs[i]->GetAt(index));
		else
			index -= m_vecs[i]->GetCount();
	}
}

int CBoolDataGroup::GetCount() const
{
	int count = 0;

	for (auto vec : m_vecs)
		count += vec->GetCount();

	return count;
}
