#include "column.h"

Column::Column(IVectorPtr data,QString name) : m_data(data),m_name(name) {}

int Column::GetCount() const
{
	return m_data->GetCount();
}

DataType Column::GetType() const
{
	return m_data->GetType();
}

QString Column::GetName() const
{
	return m_name;
}

IVectorPtr Column::GetData() const
{
	switch (this->GetType())
	{
	case INT:
		return (CIntDataPtr)m_data;
	default:
		break;
	} 
}

