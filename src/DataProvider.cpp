#include "DataProvider.h"

void DataProvider::init(CSelection const& oSelection,IDataDirectoryPtr pDataDir)
{
    m_selection = oSelection;
    pDataDirectory = pDataDir;
}

ITablePtr DataProvider::GetData(const FieldList&)
{
        const IDList& idList = pDataDirectory->GetIDList(m_selection);
        CFileInfoList FilesForLoad;
        loader load(&m_dataStore);
        for(IDList::const_iterator it = idList.begin(); it != idList.end(); ++it)
        {
            FileInfo currentInfo = pDataDirectory->GetFileInfo(*it);
            FileData currentData = m_dataStore.GetSingleFileData(*it);
            if (currentData.GetTable().size() == 0)
                FilesForLoad.append(currentInfo);
        }
        load.loadData(FilesForLoad);
        //?????????????????;
    return ITablePtr();
}
