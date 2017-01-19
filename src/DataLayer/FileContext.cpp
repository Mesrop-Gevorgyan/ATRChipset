#include "FileContext.h"

FileContext::FileContext() : m_directory()
{
}

void FileContext::add(Field fieldName, FieldValue value)
{
	m_directory.insert(fieldName,value);
}

QVariant FileContext::GetValue(Field field) const 
{
	return m_directory[field].first;
}

FieldType FileContext::GetFieldType(Field field) const
{
	return m_directory[field].second;
}

Field FileContext::GetField(FieldType fieldType) const
{
	for (auto key : m_directory.keys())
	{
		if (m_directory[key].second == fieldType)
			return key;
	}
	return Field();
}

QVariantList FileContext::GetValues(FieldList selection) const
{
	QVariantList result;
	for (auto field : selection)
	{

	}

	return QVariantList();
}
