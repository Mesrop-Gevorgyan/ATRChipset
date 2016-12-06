#include "loader.h"

loader::loader(DataStore *ptrDataStore):pDataStore(ptrDataStore)
{
}

void loader::loadData(const QList<QString> & fileList)
{
    for(QList<QString>::const_iterator it = fileList.begin(); it != fileList.end();++it)
    {
        parser Parser(*it);
        QPair<FileInfo, CVectorCollection> data = Parser.loader();
        pDataStore->add(data.first,data.second);
    }
}
