#ifndef LOADER_H
#define LOADER_H

#include "DataDirectory.h"
#include "DataStore.h"
#include "FileInfoList.h"
class CLoader
{
public:
    CLoader(DataStore& DataStore);
    //loaded data from files to datastore
    void loadData(const CFileInfoList &fileInfoList);
private:
    DataStore m_DataStore;
};

#endif // LOADER_H
