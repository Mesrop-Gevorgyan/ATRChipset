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
	virtual DATATYPE GetType() const = 0;
	//Returns count of rows in field
	virtual int GetCount() const = 0;
	//Returns Column name
	virtual QString GetName() const = 0;
	//Returns whole field in vector<int>
	virtual CIntDataPtr GetIntData() const = 0;
	//Returns whole field in vector<double>
	virtual CDoubleDataPtr GetDoubleData() const = 0;
	//Returns whole field in vector<string>
	virtual CStringDataPtr GetStringData() const = 0;
	//Returns whole field in vector<QDateTime>
	virtual CDateTimeDataPtr GetDateTimeData() const = 0;
};

#endif //__ICOLUMN__