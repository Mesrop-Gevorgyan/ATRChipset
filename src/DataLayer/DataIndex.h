#ifndef __DATAINDEX__
#define __DATAINDEX__

#include "global.h"
#include "FileInfo.h"
#include "FileInfoList.h"

class DataIndex
{
public:
	DataIndex(CFileInfoList);
private:
	void __indexation();
	QMap <QString, IDList> m_lots;
	QMap <QString, IDList> m_wafers;
	QMap <QString, IDList> m_devices;
	CFileInfoList m_infos;
};

#endif //__DATAINDEX__
