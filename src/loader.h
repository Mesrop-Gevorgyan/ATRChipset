#ifndef LOADER_H
#define LOADER_H

#include "DataDirectory.h"
#include "DataStore.h"

class loader
{
public:
    loader(DataStore* ptrDataStore);
    //loaded data from files to datastore
    void loadData(const QList<QString>& fileList);
private:
    DataStore* pDataStore;
};

#endif // LOADER_H
