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

/*
*   Returns a list of values of the specified fieldType 
*   ex: if we pass filedType as "Context",this function returns 
*   a list of file Context values
*/
QVariantList FileContext::GetValues(FieldType fieldType) const
{
        QVariantList result;

        for (auto value : m_directory.values())
        {
                if (value.second == fieldType)
                        result.append(value.first);
        }
        return result;
}

/*
*   Returns a FieldList of values of the specified fieldType
*   ex: if we pass filedType as "Context",this function returns
*   a FieldList of file Context
*/
FieldList FileContext::GetFields(FieldType fieldType) const
{
        FieldList result;

        for (auto key : m_directory.keys())
        {
                if (m_directory[key].second == fieldType)
                        result.append(key);
        }
        return result;
}

bool FileContext::contains(Field field) const
{
	for (auto value : m_directory.values())
		if (value.first == field)
			return true;
	return false;
}
