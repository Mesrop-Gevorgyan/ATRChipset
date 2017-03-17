#ifndef __DataStore__
#define __DataStore__

#include <QHash>
#include "VectorCollection.h"
#include "global.h"
#include "FileInfo.h"  
#include "fileData.h"

class DataStore
{
public:
	DataStore();
	void add(ID,FileData);
	FileData GetSingleFileData(ID id) const;
	bool contains(ID) const;
private:
	QHash<ID,FileData> m_data;
};

#endif //__DataStore__
