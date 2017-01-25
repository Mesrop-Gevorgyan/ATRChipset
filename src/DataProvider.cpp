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
        //must be parsed from selection
        QList<FileContext> contexts;
        FileContext c;
        c.add("Wafer",QPair<Value, FieldType> ("Wafer1",Context));
        c.add("Device",QPair<Value, FieldType> ("SampleDevice1",Context));
        c.add("Lot",QPair<Value, FieldType> ("Lot1",Context));
        contexts.append(c);

        QSet<FileType> types = getFieldTypes(lstField);
        QList<FileInfo> fileInfo = pDataDirectory->getFiles(types,contexts);
        QList<QString> FilesForLoad;
        loader load(&m_dataStore);
        for(QList<FileInfo>::iterator it = fileInfo.begin(); it != fileInfo.end(); ++it)
        {
            CVectorCollection currentData = m_dataStore.getBinData(*it);
            if (currentData.size() == 0)
            {
                FilesForLoad.append((*it).m_filePath);
            }
        }
        load.loadData(FilesForLoad);



}
QList<FileContext> DataProvider::getContextsList()
{
    if (m_selection.isEmpty())
        std::cout<<"empty selection"<<std::endl;
    SFieldValueSelection deviceSelection = m_selection.getFieldValueSelection("Device");
    SFieldValueSelection waferSelection = m_selection.getFieldValueSelection("Wafer");
    SFieldValueSelection lotSelection = m_selection.getFieldValueSelection("Lot");
    SFieldValueSelection dateSelection = m_selection.getFieldValueSelection("Date");
    
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
