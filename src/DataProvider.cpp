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
            if (!m_dataStore.contains(*it))
                FilesForLoad.append(pDataDirectory->GetFileInfo(*it));
        load.loadData(FilesForLoad);
        //?????????????????;
    return ITablePtr();
}
