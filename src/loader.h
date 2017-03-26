#ifndef LOADER_H
#define LOADER_H

#include "DataDirectory.h"
#include "DataStore.h"
#include "FileInfoList.h"
class loader
{
public:
    loader(DataStorePtr ptrDataStore);
    //loaded data from files to datastore
    void loadData(const CFileInfoList &fileInfoList);
private:
    DataStorePtr pDataStore;
};

#endif // LOADER_H
