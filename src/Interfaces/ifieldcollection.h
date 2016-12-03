

#ifndef IFIELDCOLLECTION_H
#define IFIELDCOLLECTION_H


#include "global.h"


// Forword declaration
class IFieldData;

///////////////////////////////////////////////////////////////////////////////
//
// IFieldCollection Interface
//
class IFieldCollection
{
public:
	// Returns field from collection by name
	virtual IFieldData* GetFieldData(Field const& field) const = 0;
	// Returns count of fields in collection
	virtual int GetCount() const = 0;
	// Returns field by index in collection
	virtual Field GetField(int index) const = 0;
	// Returns index of field in collection
	virtual int GetFieldIndex(Field const& field) const = 0;
};
///////////////////////////////////////////////////////////////////////////////

#endif // IFIELDCOLLECTION_H