#ifndef __IFIELDDATA__
#define __IFIELDDATA__


class CIntData;
class CDoubleData;
class CDateTimeData;
class CStringData;

typedef QString Field;

class IFieldData
{
public:
	//Returns count of rows in field
	virtual int GetCount() const = 0;
	//Returns field name
	virtual Field GetField() const = 0;
	//Returns whole field in vector<int>
	virtual CIntData GetIntData() const = 0;
	//Returns whole field in vector<double>
	virtual CDoubleData GetDoubleData() const = 0;
	//Returns whole field in vector<string>
	virtual CStringData GetStringData() const = 0;
	//Returns whole field in vector<QDateTime>
	virtual CDateTimeData GetDateTimeData() const = 0;
};

#endif //__IFIELDDATA__