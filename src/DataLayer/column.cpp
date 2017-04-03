#include "Column.h"

CColumn::CColumn(IVectorPtr data, QString name) : m_name(name) { m_data = data; }

int CColumn::GetCount() const
{
	return m_data->GetCount();
}

DataType CColumn::GetType() const
{
	return m_data->GetType();
}

QString CColumn::GetName() const
{
	return m_name;
}

IVectorPtr CColumn::GetData() const
{
	switch (this->GetType())
	{
	case DataType::INT:
		return QSharedPointer<CIntData>(dynamic_cast<CIntData*>(m_data.data()));
	case DataType::DOUBLE:
		return QSharedPointer<CDoubleData>(dynamic_cast<CDoubleData*>(m_data.data()));
	case DataType::STRING:
		return QSharedPointer<CStringData>(dynamic_cast<CStringData*>(m_data.data()));
	case DataType::DATETIME:
		return QSharedPointer<CDateTimeData>(dynamic_cast<CDateTimeData*>(m_data.data()));
	case DataType::BOOL:
		return QSharedPointer<CBoolData>(dynamic_cast<CBoolData*>(m_data.data()));
	default:
		return IVectorPtr();
		break;
	} 
}

CIntDataPtr CColumn::GetIntData() const
{
	if (this->GetType() == DataType::INT)
		return QSharedPointer<CIntData>(dynamic_cast<CIntData*>(m_data.data()));
	else
		return QSharedPointer<CIntData>(nullptr);
}

CDoubleDataPtr CColumn::GetDoubleData() const
{
	if (this->GetType() == DataType::DOUBLE)
		return QSharedPointer<CDoubleData>(dynamic_cast<CDoubleData*>(m_data.data()));
	else
		return QSharedPointer<CDoubleData>(nullptr);
}

CStringDataPtr CColumn::GetStringData() const
{
	if (this->GetType() == DataType::STRING)
		return QSharedPointer<CStringData>(dynamic_cast<CStringData*>(m_data.data()));
	else
		return QSharedPointer<CStringData>(nullptr);
}

CDateTimeDataPtr CColumn::GetDateTimeData() const
{
	if (this->GetType() == DataType::DATETIME)
		return QSharedPointer<CDateTimeData>(dynamic_cast<CDateTimeData*>(m_data.data()));
	else
		return QSharedPointer<CDateTimeData>(nullptr);
}

CBoolDataPtr CColumn::GetBoolData() const
{
	if (this->GetType() == DataType::BOOL)
		return QSharedPointer<CBoolData>(dynamic_cast<CBoolData*>(m_data.data()));
	else
		return QSharedPointer<CBoolData>(nullptr);
}



