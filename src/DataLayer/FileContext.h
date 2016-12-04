#ifndef __FILECONTEXT__
#define __FILECONTEXT__

#include <QString>
#include <QMap>
#include <QVariant>
#include <QPair>
#include <QList>

// Represent Field type in FileContext directory 
enum FieldType
{
	Context,
	TestCondition,
};

typedef QList<QString> FieldList;
typedef QString Field;
typedef QVariant Value; 
typedef QPair<Value,FieldType>  FieldValue; 

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