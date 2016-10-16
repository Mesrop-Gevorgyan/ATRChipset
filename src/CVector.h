#ifndef __CVECTOR___
#define __CVECTOR___

#include <QVector>
#include <QString>
#include <QDateTime>
#include "IField_collection.h"

// 
// CIntData declaration
//
class CIntData :public IIntVector
{
public:
	CIntData();
	CIntData(QVector<int>);
	int GetAt(int) const override;
	int GetCount() const override;
private:
	QVector<int> m_arr_data;
};

// 
// CDoubleData declaration
//
class CDoubleData : public IDoubleVector
{
public:
	CDoubleData();
	CDoubleData(QVector<double>);
	double GetAt(int) const override;
	int GetCount() const override;
private:
	QVector<double> m_arr_data;
};

// 
// CStringData declaration
//
class CStringData : public IStringVector
{
public: 
	CStringData();
	CStringData(QVector<QString>);
	QString GetAt(int) const override;
	int GetCount() const override;
private:
	QVector<QString> m_arr_data;
};

//
// CDateTimeData declaration
//
class CDateTimeData : public IDateTimeVector
{
public:
	CDateTimeData();
	CDateTimeData(QVector<QDateTime>);
	QDateTime GetAt(int) const override;
	int GetCount() const override;
private:
	QVector<QDateTime> m_arr_data;
};

#endif //__CVECTOR___
