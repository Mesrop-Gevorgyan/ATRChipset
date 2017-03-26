#ifndef __IDATADIRECTORY__
#define __IDATADIRECTORY__

#include <QVariant>
#include "DataStore.h"
#include "FileInfoList.h"
#include "DataIndex.h"
#include "global.h"

class IDataDirectory
{
public:
    virtual QVariantList getFieldValues(Field const& oID) const = 0;
    virtual IDList GetIDList(CSelection const& oSelection) = 0;
    virtual FileInfo GetFileInfo(ID id)  =  0;
    virtual FieldList GetFieldList(CSelection const& oSelection, Field field)  = 0;
};

#endif //__IDATADIRECTORY__
