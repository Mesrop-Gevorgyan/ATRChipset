#ifndef __FILECONTEXT__
#define __FILECONTEXT__

#include <QString>
#include <QMap>
#include <QVariant>
#include <QPair>
#include <QList>
#include "global.h"
#include <QDateTime>

class FileContext
{
public:
	FileContext();
	void add(Field,FieldValue);
	QVariant GetValue(Field) const;
	FieldType GetFieldType(Field) const;
	Field GetField(FieldType) const;
	QVariantList GetValues(FieldList) const; // ? purpose of this 
private:
	QMap <Field, FieldValue> m_directory;
};

#endif //__FILECONTEXT__
