#include "DataProvider.h"

void DataProvider::init(const CSelection& oSelection, IDataDirectory* pDataDir)
{
	pDataDirectory = pDataDir;
	m_selection = oSelection;
}

ITablePtr DataProvider::GetData()
{
        CFileInfoList fileInfo = getContextsList(); //contexts is CfileInfoList
        CFileInfoList FilesForLoad;
        loader load(&m_dataStore);
        for(int i = 0; i < fileInfo.count(); ++i)
        {
            FileInfo currentInfo = pDataDirectory->GetCompleteFileInfo(fileInfo[i]);
            FileData currentData = m_dataStore.GetSingleFileData(currentInfo.ID);
            if (currentData.GetTable().size() == 0)
            {
                FilesForLoad.append(currentInfo);
            }
        }
        load.loadData(FilesForLoad);
        //?????????????????;
	return ITablePtr();
}

CFileInfoList DataProvider::getContextsList()
{
    CFileInfoList results;
    QVariantList devices = getFieldValuesCorrespondingToSelection(DEVICE);
    QVariantList lots = getFieldValuesCorrespondingToSelection(LOT);
    QVariantList wafers = getFieldValuesCorrespondingToSelection(WAFER);
    QVariantList dates = getFieldValuesCorrespondingToSelection(DATE);
    for (QVariantList::iterator itDev = devices.begin(); itDev != devices.end(); ++itDev)
    {
        for (QVariantList::iterator itL = lots.begin(); itL != lots.end(); ++itL)
        {
            for (QVariantList::iterator itW = wafers.begin(); itW != wafers.end(); ++itW)
            {
                for (QVariantList::iterator itDate = dates.begin(); itDate != dates.end();
                     ++itDate)
                {
                        FileInfo currentFileInfo;
                        currentFileInfo.m_date = (*itDate).toDateTime();
                        currentFileInfo.m_fileContext.add(DEVICE,
                                                          QPair<Value, FieldType> (*itDev,Context));
                        currentFileInfo.m_fileContext.add(LOT,
                                                          QPair<Value, FieldType> (*itL,Context));
                        currentFileInfo.m_fileContext.add(WAFER,
                                                          QPair<Value, FieldType> (*itW,Context));
                        results.append(currentFileInfo);
                }
            }
        }
    }
    return results;
}

