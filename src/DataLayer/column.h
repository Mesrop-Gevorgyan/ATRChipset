#ifndef  __COLUMN
#define  __COLUMN

#include "icolumn.h"
#include "global.h"
#include "Vector.h"

class Column : public IColumn
{
public:
	Column(IVectorPtr, QString);
	int GetCount() const;
	DataType GetType() const;
	QString GetName() const;
	IVectorPtr GetData() const;
private:
	IVectorPtr m_data;
	QString m_name;
};


#endif // ! __COLUMN
