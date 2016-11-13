#ifndef __CSELECTION__
#define __CSELECTION__

#include <QVariantList>
#include <QString>

typedef QString Field;
typedef QStringList FieldList;

struct SFieldInfo
{
	Field			FieldID;
	QString			sName;
	EFieldType		eType;
};

enum EFieldType
{
	Int = 0x01,
	String = 0x02,
	DateTime = 0x03,
};

enum ESelectionPatten
{
	// Default selection (all Field valus are selected)
	All = 0x01,
	// Coustom selection
	ValueSelection = 0x02
};

////////////////////////////////////////////////////////////////
//
// class CSelection
//
class CSelection
{
public:
	struct SFieldValueSelection
	{
		ESelectionPatten    	eSelectionType;
		QString					sPattern;
		QVariantList        	arrSelectedValues;
	};

private:
	QVector<SFieldValueSelection>		vecSelection;
};
////////////////////////////////////////////////////////////////

#endif //__CSELECTION__
