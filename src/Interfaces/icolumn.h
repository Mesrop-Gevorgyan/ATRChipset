#ifndef __ICOLUMN__
#define __ICOLUMN__

#include "global.h"

class CIntData;
class CDoubleData;
class CDateTimeData;
class CStringData;
class QString;

// Owns name , data , type 
class IColumn
{
public:
	// Returns type of the data
	virtual DataType GetType() const = 0;
	//Returns count of rows in column
	virtual int GetCount() const = 0;
	//Returns Column name
	virtual QString GetName() const = 0;
	//Returns whole column in IVectorPtr
	virtual IVectorPtr GetData() const = 0;

};

#endif //__ICOLUMN__

