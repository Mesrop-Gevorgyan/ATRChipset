#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include "IDataProvider.h"
#include "loader.h"
#include <QRegExp>
#include "FileInfoList.h"

class DataProvider:public IDataProvider
{
public:
    void setSelection(CSelection const& oSelection);
    void setDataDirectory(IDataDirectory* pDataDir);
    IFieldCollectionPtr GetData(const FieldList &lstField);
private:
    IDataDirectory* pDataDirectory;
    DataStore m_dataStore;
    CSelection m_selection;
    QSet<FileType> getFieldTypes(const FieldList&);
    CFileInfoList getContextsList();
};

#endif // DATAPROVIDER_H
