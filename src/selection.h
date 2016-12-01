
#ifndef SELECTION_H
#define SELECTION_H


#include <QtCore\QVariantList>
#include <QtCore\QString>
#include <QtCore\QVector>
#include <QtCore\QHash>


typedef QString Field;
typedef QStringList FieldList;


enum class EFieldType
{
	Bool,
	Char,
	Short,
	Int,
	LongInt,
	Float,
	Double,
	String,
	DateTime,
};


struct SFieldInfo
{
	Field			oFieldID;
	QString			sName;
	EFieldType		eType;
};


enum class ESelectionPatten
{
	// No selection
	NoSelection,
	// Default selection (all Field valus are selected)
	All,
	// Coustom selection
	ValueSelection
};


// Value selection of one field
struct SFieldValueSelection
{
	Field					oFieldID;
	ESelectionPatten    	eSelectionType;
	QString					sPattern;
	QVariantList        	aSelectedValues;

	inline bool isValid() const
	{
		return !oFieldID.isEmpty();
	}
};


/*
	Class suport to work with field value selections
*/
////////////////////////////////////////////////////////////////
//
// class CSelection
//
class CSelection
{
public:
	// Default Constructor
	CSelection() = default;
	// Destructor
	~CSelection() = default;

public:
	//
	//! Interface
	//
	bool isEmpty() const;
	bool isContains(Field const& oID) const;
	int getCount() const;
	void clear();

	// Get field value selection by ID
	SFieldValueSelection getFieldValueSelection(Field const& oID) const;
	// Append field value selection,
	// if there is a selection for that field then replaces it
	void addFieldValueSelection(SFieldValueSelection const& oSel);
	// remove field value selection
	void remove(Field const& oID);

private:
	//
	// Content
	//
	QHash<Field, SFieldValueSelection>		mapSelection;
};
////////////////////////////////////////////////////////////////

#endif // SELECTION_H