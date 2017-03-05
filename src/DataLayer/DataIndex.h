#ifndef __DATAINDEX__
#define __DATAINDEX__

#include <QVector>
#include "global.h"
#include "FileInfo.h"
#include "FileInfoList.h"

class DataIndex
{
public:
	DataIndex(CFileInfoList);
	IDList GetFileIDsWithPattern(QStringList pattern);
private:
	void __indexation();
	IDList __getFileIDs(QString content);
	IDList __mergeIDLists(QVector<IDList> list);
	QMap <QString, IDList> m_lots;
	QMap <QString, IDList> m_wafers;
	QMap <QString, IDList> m_devices;
	CFileInfoList m_infos;
};

#endif //__DATAINDEX__
