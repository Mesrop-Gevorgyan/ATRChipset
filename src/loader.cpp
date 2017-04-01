#include "Loader.h"

CLoader::CLoader(DataStore& DataStore):m_DataStore(DataStore)
{
}

void CLoader::loadData(const CFileInfoList &fileInfoList)
{
    for(int i = 0; i < fileInfoList.count(); ++i )
    {
        CParser Parser(fileInfoList[i].m_filePath);
        FileData data = Parser.loader(fileInfoList[i].m_fileType);
        m_DataStore.add(fileInfoList[i].ID,data);
    }
}
