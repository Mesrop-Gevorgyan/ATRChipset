#ifndef __IDATAPROVIDER__
#define __IDATAPROVIDER__

#include "selection.h"
#include <QSharedPointer>
#include "DataStore.h"
#include "IDataDirectory.h"
#include "global.h"

//
// Interfaces IDataProvider
//
class IDataProvider
{
public:
	// Init
	virtual  void init(CSelection const&,IDataDirectory*) = 0;
	// Get Data corresponding of selection
	virtual ITablePtr GetData(const FieldList& ) = 0;
};

#endif // __IDATAPROVIDER__
