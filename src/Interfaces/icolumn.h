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
	//Returns count of rows in CColumn
	virtual int GetCount() const = 0;
	//Returns CColumn name
	virtual QString GetName() const = 0;
	//Returns whole CColumn in IVectorPtr
	virtual IVectorPtr GetData() const = 0;
	//Returns whole CColumn in CIntDataPtr
	virtual CIntDataPtr GetIntData() const = 0;
	//Returns whole CColumn in CDoubleDataPtr
	virtual CDoubleDataPtr GetDoubleData() const = 0;
	//Returns whole CColumn in CStringDataPtr
	virtual CStringDataPtr GetStringData() const = 0;
	//Returns whole CColumn in CBoolDataPtr
	virtual CBoolDataPtr GetBoolData() const = 0;
	//Returns whole CColumn in CDateTimeDataPtr
	virtual CDateTimeDataPtr GetDateTimeData() const = 0;

};

#endif //__ICOLUMN__

