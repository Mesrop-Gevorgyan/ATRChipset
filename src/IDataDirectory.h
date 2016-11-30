#ifndef __IDATADIRECTORY__
#define __IDATADIRECTORY__

#include "DataStore.h"

class QVariantList;
typedef  QStringList FieldList;

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

#endif //__IDATADIRECTORY__
