#include "DataProvider.h"

void DataProvider::init(CSelection const& oSelection,IDataDirectoryPtr pDataDir)
{
    m_selection = oSelection;
    pDataDirectory = pDataDir;
}

ITablePtr DataProvider::GetData(const FieldList& fieldList)
{
        pDataDirectory->SetSelection(m_selection);
        const IDList& idList = pDataDirectory->GetIDList();
        CFileInfoList FilesForLoad;
        CLoader loader(m_dataStore);
        for(IDList::const_iterator it = idList.begin(); it != idList.end(); ++it)
            if (!m_dataStore.contains(*it))
                FilesForLoad.append(pDataDirectory->GetFileInfo(*it));
        loader.loadData(FilesForLoad);

        QVector<QVector<IVectorPtr> > columns;
        const QSet<FileType>& fileTypes = getFileTypes(fieldList);
        for(IDList::const_iterator it = idList.begin(); it != idList.end(); ++it)
        {
            const FileType& currentFileType = pDataDirectory->GetFileInfo(*it).m_fileType;
            if (fileTypes.find(currentFileType) == fileTypes.end())
                continue;
            const FileData& currentData = m_dataStore.GetSingleFileData(*it);
            const TableInfo& currentTableInfo = currentData.GetTableInfo();
            for (int i = 0; i < fieldList.size(); ++i)
            {
                int indexOfColumn = currentTableInfo.GetColumnIndex(fieldList[i]);
                columns[i].push_back(currentData.GetTable()[indexOfColumn]);
            }
        }
        CTable tb;
        for (int i = 0; i  < columns.size(); ++i)
        {
            if (columns[i].size() == 1)
            {
                IColumnPtr p = IColumnPtr(new CColumn(columns[i][0],fieldList[i]));
                tb.addColumn(p);
            }
            else
            {
                IVectorPtr p;
                switch (columns[i][0]->GetType())
                {
                case INT:
                        
                    break;
                case DOUBLE:
                
                        break;
                case STRING:
                        
                        break;
                case BOOL:
                
                        break;
                case DATETIME:
                
                        break;
                }
                IColumnPtr ptr = IColumnPtr(new CColumn(p,fieldList[i]));
                tb.addColumn(ptr);
            }
        }
    return ITablePtr(&tb);
}


QSet<FileType> DataProvider::getFileTypes(const FieldList& fields)
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
