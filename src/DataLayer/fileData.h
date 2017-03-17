#ifndef  __FILEDATA__
#define  __FILEDATA__

#include "VectorCollection.h"
#include "tableInfo.h"

class FileData
{
public:
	FileData();
	FileData(CVectorCollection, TableInfo);
	FileData(const FileData&);
	CVectorCollection GetTable() const;
	TableInfo GetTableInfo() const;
private:
	CVectorCollection m_table;
	TableInfo m_tableinfo;
}; 

#endif // ! __FILEDATA__
