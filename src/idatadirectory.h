#ifndef IDATADIRECTORY_H
#define IDATADIRECTORY_H


// Qt includes
#include <QList>
#include <QVariantList>

#include "DataStore.h"
#include "global.h"


///////////////////////////////////////////////////////////////////////////////
//
// Interface IDataDirectory
//
class IDataDirectory
{
public:
	// Get field list of all field types
	virtual FieldList getFields() const = 0;
	// Get values as QVariant of field
	virtual QVariantList getFieldValues() const = 0;
	//Get information corresponding files
	virtual QList<FileInfo> getFiles(const QList<FileType>&)const = 0;
};
///////////////////////////////////////////////////////////////////////////////

#endif // IDATADIRECTORY_H