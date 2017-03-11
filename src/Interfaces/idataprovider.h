#ifndef __IDATAPROVIDER__
#define __IDATAPROVIDER__

#include "selection.h"
#include <QSharedPointer>
#include "DataStore.h"
#include "IDataDirectory.h"
#include "selection.h"
// This interface provide data which was selected and loaded
class IFieldCollection;
typedef QSharedPointer<IFieldCollection> IFieldCollectionPtr;

////////////////////////////////////////////////////////////////
//
// Interfaces IDataProvider
//
class IDataProvider
{
public:
    // Set field data selection
    virtual void setSelection(CSelection const& oSelection) = 0;
    //
    virtual void setDataDirectory(IDataDirectory* pDataDir) = 0;
    // Get Data corresponding of selection
    virtual IFieldCollectionPtr GetData() = 0;
};
////////////////////////////////////////////////////////////////

#endif // __IDATAPROVIDER__
