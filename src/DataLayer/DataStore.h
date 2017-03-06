#ifndef __DataStore__
#define __DataStore__

#include <QHash>
#include "VectorCollection.h"
#include "global.h"
#include "FileInfo.h"   

class DataStore
{
public:
	DataStore();
	void add(ID,CVectorCollection);
	CVectorCollection GetSingleFileData(ID id) const;
private:
	QHash<ID,CVectorCollection> m_data;
};

#endif //__DataStore__
