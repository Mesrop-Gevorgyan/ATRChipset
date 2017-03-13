#ifndef __ICOLUMN__
#define __ICOLUMN__

#include "global.h"

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
	//Returns whole column in vector<int>
	virtual CIntDataPtr GetIntData() const = 0;
	//Returns whole column in vector<double>
	virtual CDoubleDataPtr GetDoubleData() const = 0;
	//Returns whole column in vector<string>
	virtual CStringDataPtr GetStringData() const = 0;
	//Returns whole column in vector<QDateTime>
	virtual CDateTimeDataPtr GetDateTimeData() const = 0;
};

#endif //__ICOLUMN__
