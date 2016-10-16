#ifndef __MAINDATA__
#define __MAINDATA__

#include <QString>
#include <QVector>
#include <QMap>
#include "iField_collection.h"

//
// Context declaration
//
// This class will be used for declaring each file context (lot,wafer,device)
//
class Context
{
public:
	Context();
	Context(QString, QString, QString);
	QString GetLot() const;
	QString GetWafer() const;
	QString GetDevice() const;
private:
	QString m_lot;
	QString m_wafer;
	QString m_device;
};

//
// MainData declaration
//
// This class will be used for declaring each file content,with context and binData 
// Context is ID of file
// With context can access to file content
//
class MainData
{
public:
	MainData();
	void add(Context, QVector<QVector<IVector*>>);
	QVector<QVector<IVector*>> getBinData(const Context&) const throw();
private:
	QMap<Context, QVector<QVector<IVector*>>> m_data;
};

#endif //__MAINDATA__
