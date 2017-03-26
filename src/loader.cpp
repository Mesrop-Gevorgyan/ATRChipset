#include "loader.h"

loader::loader(DataStorePtr ptrDataStore):pDataStore(ptrDataStore)
{
}

void loader::loadData(const CFileInfoList &fileInfoList)
{
    for(int i = 0; i < fileInfoList.count(); ++i )
    {
        parser Parser(fileInfoList[i].m_filePath);
        FileData data = Parser.loader(fileInfoList[i].m_fileType);
        pDataStore->add(fileInfoList[i].ID,data);
    }
}
