#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include "idataProvider.h"
#include "loader.h"
#include <QRegExp>
#include "fileInfoList.h"

class DataProvider:public IDataProvider
{
public:
	void init(CSelection const& selection, IDataDirectory* directory);
	ITablePtr GetData();
private:
    IDataDirectory* pDataDirectory;
    DataStore m_dataStore;
    CSelection m_selection;
};

#endif // DATAPROVIDER_H
