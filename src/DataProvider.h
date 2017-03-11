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
    IFieldCollectionPtr GetData();
private:
    IDataDirectory* pDataDirectory;
    DataStore m_dataStore;
    CSelection m_selection;
    CFileInfoList getContextsList();
    QVariantList getFieldValuesCorrespondingToSelection(const Field& field)const;
};

#endif // DATAPROVIDER_H
