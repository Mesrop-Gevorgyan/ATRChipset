#ifndef __MAINDATA__
#define __MAINDATA__

#include <QString>
#include <QVector>
#include <QMap>
#include <QDateTime>
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
// This enum use for representation Test Conditions
// Initially we have only temperature,but we can add others
// 
enum TestCondition
{
	Temperature,
};

//
// This enum use for represent file type
//
enum FileType
{
	BinData,
	BinDefinition,
	ParameterDefinition,
	ParameterData,
	ParameterLimits,
};

//
// Use this struct for represent file
// struct or class ??? struct is more comfortable
//
struct FileInfo
{
	Context m_context;
	QDateTime m_date;
	TestCondition m_testCondition;
	FileType m_fileType;
	QString m_fileName;
};

//
// MainData declaration
//
// This class will be used for declaring each file content,with context and binData 
// FileInfo is ID of file
// With FileInfo can access to file content
//
class MainData
{
public:
	MainData();
	void add(FileInfo, QVector<IVector*>);
    QVector<IVector*> getBinData(const FileInfo&) const throw();
private:
	QMap<FileInfo, QVector<IVector*>> m_data;
};

#endif //__MAINDATA__
