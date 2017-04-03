#ifndef  __COLUMN
#define  __COLUMN

#include "icolumn.h"
#include "global.h"
#include "Vector.h"

class CColumn : public IColumn
{
public:
	CColumn(IVectorPtr, QString);
	int GetCount() const override;
	DataType GetType() const override;
	QString GetName() const override;
	IVectorPtr GetData() const override;
	CIntDataPtr GetIntData() const override;
	CDoubleDataPtr GetDoubleData() const override;
	CStringDataPtr GetStringData() const override;
	CDateTimeDataPtr GetDateTimeData() const override;
	CBoolDataPtr GetBoolData() const override;
private:
	IVectorPtr m_data;
	QString m_name;
};


#endif // ! __COLUMN
