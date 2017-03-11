#ifndef LOADER_H
#define LOADER_H

#include "DataDirectory.h"
#include "DataStore.h"
#include "FileInfoList.h"
class loader
{
public:
    loader(DataStore* ptrDataStore);
    //loaded data from files to datastore
    void loadData(const CFileInfoList& fileList);
private:
    DataStore* pDataStore;
};

#endif // LOADER_H
