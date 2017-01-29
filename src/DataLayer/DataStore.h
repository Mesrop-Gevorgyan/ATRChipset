#ifndef __DataStore__
#define __DataStore__

#include <QMap>
#include "VectorCollection.h"
#include "global.h"
#include "FileInfo.h"   

class DataStore
{
public:
	DataStore();
	void add(FileInfo, CVectorCollection);
	CVectorCollection getBinData(const FileInfo&) const;
private:
	QMap<FileInfo, CVectorCollection> m_data;
};

#endif //__DataStore__
