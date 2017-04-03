#ifndef SELECTION_H
#define SELECTION_H


// Qt includes
#include <QtCore\QVariantList>
#include <QtCore\QString>
#include <QtCore\QVector>

#include "global.h"


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


enum class ESelectionPattern
{
	// Coustom selection
	Value,
	// Select by pattern
	Pattern,
};


// Value selection of one field
struct SFieldValueSelection
{
	Field			oFieldID;
	ESelectionPattern    	eType;
	QString			sPattern;
	QVariantList        	aValues;
	
	// Default constructor
	SFieldValueSelection()
		: eSelectionType(ESelectionPattern::Value)
	{
	}

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
	SFieldValueSelection getAt(int nIndex) const;
	// Get field value selection by ID
	SFieldValueSelection getFieldValueSelection(Field const& oID) const;
	// Append field value selection,
	// if there is a selection for that field then replaces it
	void addFieldValueSelection(SFieldValueSelection const& oSel);
	// remove field value selection
	void remove(int nIndex);
	void remove(Field const& oID);

protected:
	//
	// Implemetation
	//
	int getIndexFromFieldID(Field const& oID) const;

private:
	//
	// Content
	//
	QVector<SFieldValueSelection>		vecSelection;
};
////////////////////////////////////////////////////////////////

#endif // SELECTION_H#pragma once
