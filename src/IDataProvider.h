#ifndef __IDATAPROVIDER__
#define __IDATAPROVIDER__

#include "CSelection.h"
#include <QSharedPointer>

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
	// Get Data corresponding of selection
	virtual IFieldCollectionPtr GetData(FieldList const& lstField) = 0;
};
////////////////////////////////////////////////////////////////

#endif // __IDATAPROVIDER__
