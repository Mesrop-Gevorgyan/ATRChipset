#ifndef __CVECTOR___
#define __CVECTOR___

#include <QVector>
#include <QString>
#include <QDateTime>
#include <QVariant>
#include "VectorCollection.h"

// 
// CIntData declaration
//
class CIntData :public IIntVector
{
public:
	CIntData();
	CIntData(QVector<int>);
	int GetAt(unsigned) const override;
	int GetCount() const override;
	DataType GetType() const override;
	QVariant GetValue(unsigned index) const override;
private:
	QVector<int> m_arr_data;
};

// 
// CIntDataGroup declaration
//
class CIntDataGroup : public CIntData
{
public:
	CIntDataGroup(QVector<CIntDataPtr>);
	int GetCount() const override;
	int GetAt(unsigned) const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<CIntDataPtr> m_vecs;
};

// 
// CDoubleData declaration
//
class CDoubleData : public IDoubleVector
{
public:
	CDoubleData();
	CDoubleData(QVector<double>);
	double GetAt(unsigned) const override;
	int GetCount() const override;
	DataType GetType() const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<double> m_arr_data;
};

// 
// CDoubleDataGroup declaration
//
class CDoubleDataGroup : public CDoubleData
{
public:
	CDoubleDataGroup(QVector<CDoubleDataPtr>);
	int GetCount() const override;
	double GetAt(unsigned) const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<CDoubleDataPtr> m_vecs;
};


// 
// CStringData declaration
//
class CStringData : public IStringVector
{
public: 
	CStringData();
	CStringData(QVector<QString>);
	QString GetAt(unsigned) const override;
	int GetCount() const override;
	DataType GetType() const override;
	QVariant GetValue(unsigned index) const override;
private:
	QVector<QString> m_arr_data;
};

// 
// CStringDataGroup declaration
//
class CStringDataGroup : public CStringData
{
public:
	CStringDataGroup(QVector<CStringDataPtr>);
	int GetCount() const override;
	QString GetAt(unsigned) const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<CStringDataPtr> m_vecs;
};
//
// CDateTimeData declaration
//
class CDateTimeData : public IDateTimeVector
{
public:
	CDateTimeData();
	CDateTimeData(QVector<QDateTime>);
	QDateTime GetAt(unsigned) const override;
	int GetCount() const override;
	DataType GetType() const override;
	QVariant GetValue(unsigned index) const override;
private:
	QVector<QDateTime> m_arr_data;
};

// 
// CDateTimeDataGroup declaration
//
class CDateTimeDataGroup : public CDateTimeData
{
public:
	CDateTimeDataGroup(QVector<CDateTimeDataPtr>);
	int GetCount() const override;
	QDateTime GetAt(unsigned) const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<CDateTimeDataPtr> m_vecs;
};

//
// CBoolData declaration
//
class CBoolData : public IBoolVector
{
public:
	CBoolData();
	CBoolData(QVector<bool>);
	bool GetAt(unsigned) const override;
	int GetCount() const override;
	DataType GetType() const override;
	QVariant GetValue(unsigned index) const override;
private:
	QVector<bool> m_arr_data;
};

// 
// CBoolDataGroup declaration
//
class CBoolDataGroup : public CBoolData
{
public:
	CBoolDataGroup(QVector<CBoolDataPtr>);
	int GetCount() const override;
	bool GetAt(unsigned) const override;
	QVariant GetValue(unsigned) const override;
private:
	QVector<CBoolDataPtr> m_vecs;
};

#endif //__CVECTOR___
