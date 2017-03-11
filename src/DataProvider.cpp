#include "DataProvider.h"

void DataProvider::setDataDirectory(IDataDirectory* pDataDir)
{
      pDataDirectory = pDataDir;
}

void DataProvider::setSelection(const CSelection &oSelection)
{
    m_selection = oSelection;
}

IFieldCollectionPtr DataProvider::GetData()
{
        CFileInfoList fileInfo = getContextsList(); //contexts is CfileInfoList
        CFileInfoList FilesForLoad;
        loader load(&m_dataStore);
        for(int i = 0; i < fileInfo.count(); ++i)
        {
            CVectorCollection currentData = m_dataStore.GetSingleFileData(fileInfo[i].ID);
            if (currentData.size() == 0)
            {
                FilesForLoad.append(fileInfo[i]); //but here is undefined id and path
            }
        }
        load.loadData(FilesForLoad);
        //?????????????????;
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

QVariantList DataProvider::getFieldValuesCorrespondingToSelection(const Field& field)const
{
    const SFieldValueSelection& selection = m_selection.getFieldValueSelection(field);
    QVariantList result;
    if (selection.aSelectedValues.size() == 0) //at first get selected values
    {
        result = pDataDirectory->getFieldValues(field);
        if (selection.eSelectionType == ESelectionPattern::ValueSelection) //no selected values,any pattern
        {
            QRegExp pattern(selection.sPattern);
            for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
            {
                if ( pattern.exactMatch((*it).toString()) == false)
                    result.erase(it);//this does not match with pattern
            }
        }
    }
    else
        result = selection.aSelectedValues;
    return result;
}
