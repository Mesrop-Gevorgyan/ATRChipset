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
	case INT:
		return QSharedPointer<CIntData>(dynamic_cast<CIntData*>(m_data.data()));
	case DOUBLE:
		return QSharedPointer<CDoubleData>(dynamic_cast<CDoubleData*>(m_data.data()));
	case STRING:
		return QSharedPointer<CStringData>(dynamic_cast<CStringData*>(m_data.data()));
	case DATETIME:
		return QSharedPointer<CDateTimeData>(dynamic_cast<CDateTimeData*>(m_data.data()));
	case BOOL:
		return QSharedPointer<CBoolData>(dynamic_cast<CBoolData*>(m_data.data()));
	default:
		return IVectorPtr();
		break;
	} 
}

