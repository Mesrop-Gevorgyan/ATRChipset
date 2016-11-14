#ifndef __MAINDATA__
#define __MAINDATA__

#include <QString>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include "IVector.h"
#include "Context.h"

enum TestCondition
{
	Temperature,
};

enum FileType
{
	BinData,
	BinDefinition,
	ParameterDefinition,
	ParameterData,
	ParameterLimits,
};

struct FileInfo
{
	Context m_context;
	QDateTime m_date;
	TestCondition m_testCondition;
	FileType m_fileType;
	QString m_fileName;
};

class MainData
{
public:
	MainData();
	void add(FileInfo, QVector<IVector*>);
    QVector<IVector*> getBinData(const FileInfo&) const;
private:
	QMap<FileInfo, QVector<IVector*>> m_data;
};

#endif //__MAINDATA__
