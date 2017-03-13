#ifndef ITABLE_H
#define ITABLE_H

#include "global.h"

class ITable
{
public:
	// Returns Column from table by name
	virtual IColumn* GetColumnData(Field const& field) const = 0;
	// Returns count of columns in table
	virtual int GetCount() const = 0;
	// Returns column name by index in table
	virtual QString GetColumnName(int index) const = 0;
	// Returns index of field in collection
	virtual int GetFieldIndex(Field const& field) const = 0;
};

#endif // ITABLE_H
