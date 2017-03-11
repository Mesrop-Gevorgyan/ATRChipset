#include "loader.h"

loader::loader(DataStore *ptrDataStore):pDataStore(ptrDataStore)
{
}

void loader::loadData(const CFileInfoList &fileList)
{
    for(int i = 0;i < fileList.count(); ++i )
    {
        parser Parser(fileList[i].m_filePath);
        CVectorCollection data = Parser.loader(fileList[i].m_fileType);
        pDataStore->add(fileList[i].ID,data);
    }
}


