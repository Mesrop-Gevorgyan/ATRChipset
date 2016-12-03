

#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H


// Qt includes
#include <QSharedPointer>

#include "selection.h"
#include "idatadirectory.h"


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
	// Set fields data selection
	virtual void setSelection(CSelection const& oSelection) = 0;
	// Set Data directory
	virtual void setDataDirectory(IDataDirectory* pDataDir) = 0;
	// Get Data corresponding of selection
	virtual IFieldCollectionPtr GetData(FieldList const& lstField) = 0;
};
////////////////////////////////////////////////////////////////

#endif // IDATAPROVIDER_H