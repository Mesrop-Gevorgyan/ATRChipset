#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include "IDataProvider.h"
#include "Loader.h"
#include <QRegExp>
#include "FileInfoList.h"
#include "table.h"
#include "column.h"
#include "global.h"

#include <QSet>

class DataProvider:public IDataProvider
{
public:
    void init(CSelection const& oSelection, IDataDirectoryPtr pDataDir);
    ITablePtr GetData(const FieldList& fieldList); //getBinData,,as arg FieldList
private:
    IDataDirectoryPtr pDataDirectory;
    DataStore m_dataStore;
    CSelection m_selection;
private:
    QSet<FileType> getFileTypes(const FieldList& fields);
};

#endif // DATAPROVIDER_H

