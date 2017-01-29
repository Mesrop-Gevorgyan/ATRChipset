#include "DataProvider.h"

void DataProvider::setDataDirectory(IDataDirectory* pDataDir)
{
      pDataDirectory = pDataDir;
}

void DataProvider::setSelection(const CSelection &oSelection)
{
    m_selection = oSelection;
}

IFieldCollectionPtr DataProvider::GetData(FieldList const& lstField)
{
        QSet<FileType> types = getFieldTypes(lstField);
        CFileInfoList fileInfo = pDataDirectory->getFiles(types,getContextsList()); //contexts is CfileInfoList
        QList<QString> FilesForLoad;
        loader load(&m_dataStore);
        for(int i = 0; i < fileInfo.count(); ++i)
        {
            CVectorCollection currentData = m_dataStore.getBinData(fileInfo[i]);
            if (currentData.size() == 0)
            {
                FilesForLoad.append(fileInfo[i].m_filePath);
            }
        }

        load.loadData(FilesForLoad);



}

CFileInfoList DataProvider::getContextsList()
{
    //if (m_selection.isEmpty())
        //std::cout<<"empty selection"<<std::endl;
    CFileInfoList results;
    const SFieldValueSelection& deviceSelection = m_selection.getFieldValueSelection("Device");
    QRegExp patternForDevice;
    QSet<QString> devices;
    if (deviceSelection.aSelectedValues.size() == 0) //at first get selected values
    {
        devices = pDataDirectory->getDevices();
        if (deviceSelection.eSelectionType == ESelectionPattern::ValueSelection)
        {
            patternForDevice.setPattern(deviceSelection.sPattern);
            for (QSet<QString>::iterator it = devices.begin(); it != devices.end(); ++it)
            {
                if ( patternForDevice.exactMatch(*it) == false)
                    devices.erase(it);//this device does not match with pattern
            }
        }
    }
    else
    {
        QVariantList currentValues = deviceSelection.aSelectedValues;
        for (int i =0; i < currentValues.size(); ++i)
            devices.insert(currentValues[i].toString());
    }

    const SFieldValueSelection& lotSelection = m_selection.getFieldValueSelection("Lot");
    QRegExp patternForLot;
    QSet<QString> lots;
    if (lotSelection.aSelectedValues.size() == 0) //at first get selected values
    {
        lots = pDataDirectory->getLots();
        if (lotSelection.eSelectionType == ESelectionPattern::ValueSelection)
        {
            patternForLot.setPattern(lotSelection.sPattern);
            for (QSet<QString>::iterator it = lots.begin(); it != lots.end(); ++it)
            {
                if ( patternForLot.exactMatch(*it) == false)
                    lots.erase(it);//this device does not match with pattern
            }
        }
    }
    else
    {
        QVariantList currentValues = lotSelection.aSelectedValues;
        for (int i =0; i < currentValues.size(); ++i)
            lots.insert(currentValues[i].toString());
    }

    const SFieldValueSelection& waferSelection = m_selection.getFieldValueSelection("Wafer");
    QRegExp patternForWafer;
    QSet<QString> wafers;
    if (waferSelection.aSelectedValues.size() == 0) //at first get selected values
    {
        wafers = pDataDirectory->getWafers();
        if (waferSelection.eSelectionType == ESelectionPattern::ValueSelection)
        {
            patternForWafer.setPattern(waferSelection.sPattern);
            for (QSet<QString>::iterator it = wafers.begin(); it != wafers.end(); ++it)
            {
                if ( patternForWafer.exactMatch(*it) == false)
                    wafers.erase(it);//this device does not match with pattern
            }
        }
    }
    else
    {
        QVariantList currentValues = waferSelection.aSelectedValues;
        for (int i =0; i < currentValues.size(); ++i)
            wafers.insert(currentValues[i].toString());
    }

    const SFieldValueSelection& dateSelection = m_selection.getFieldValueSelection("Date");
    QRegExp patternForDate;
    QSet<QDateTime> dates;
    if (dateSelection.aSelectedValues.size() == 0) //at first get selected values
    {
        dates = pDataDirectory->getDates();
        if (dateSelection.eSelectionType == ESelectionPattern::ValueSelection)
        {
            patternForDate.setPattern(dateSelection.sPattern);
            for (QSet<QDateTime>::iterator it = dates.begin(); it != dates.end(); ++it)
            {
                if ( patternForDate.exactMatch((*it).toString()) == false)
                    dates.erase(it);//this device does not match with pattern
            }
        }
    }
    else
    {
        QVariantList currentValues = dateSelection.aSelectedValues;
        for (int i =0; i < currentValues.size(); ++i)
            dates.insert(currentValues[i].toDateTime());
    }

    for (QSet<QString>::iterator itDev = devices.begin(); itDev != devices.end(); ++itDev)
    {
        for (QSet<QString>::iterator itL = lots.begin(); itL != lots.end(); ++itL)
        {
            for (QSet<QString>::iterator itW = wafers.begin(); itW != wafers.end(); ++itW)
            {
                for (QSet<QDateTime>::iterator itDate = dates.begin(); itDate != dates.end();
                     ++itDate)
                {
                        FileInfo currentFileInfo;
                        currentFileInfo.m_date = *itDate;
                        currentFileInfo.m_fileContext.add("Device",
                                                          QPair<Value, FieldType> (*itDev,Context));
                        currentFileInfo.m_fileContext.add("Lot",
                                                          QPair<Value, FieldType> (*itL,Context));
                        currentFileInfo.m_fileContext.add("Wafer",
                                                          QPair<Value, FieldType> (*itW,Context));
                        results.append(currentFileInfo);
                }
            }
        }
    }
    return results;
}

QSet<FileType> DataProvider::getFieldTypes(const FieldList& fields)
{
    QSet<FileType> result;
    for(FieldList::const_iterator it = fields.begin(); it != fields.end(); ++it)
    {
        if (*it == "Bin" || *it == "BinType")
        {
            result.insert(BinData);
            result.insert(BinDefinition);
        }
        if (*it == "BinName" || *it == "PassFail")
        {
             result.insert(BinDefinition);
        }
        if (*it == "DieX" || *it == "DieY")
        {
            result.insert(BinData);
            result.insert(ParameterData);
        }
        if (*it == "TestNumber")
        {
            result.insert(ParameterData);
            result.insert(ParameterDefinition);
            result.insert(ParameterLimits);
        }
        if (*it == "Parameter" || *it == "ParameterUnit")
        {
            result.insert(ParameterDefinition);
        }
        if (*it == "Last" || *it == "TestPass")
        {
            result.insert(ParameterData);
            result.insert(ParameterLimits);
        }
        if (*it == "LSL" || *it == "USL" || *it == "Target")
        {
            result.insert(ParameterLimits);
        }
    }
    return result;
}
