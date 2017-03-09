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
	bool contains(Field field) const;
	FieldType GetFieldType(Field) const;
        QVariantList GetValues(FieldType ) const; 
        FieldList GetFields(FieldType) const;
private:
	QMap <Field, FieldValue> m_directory;
};

#endif //__FILECONTEXT__
