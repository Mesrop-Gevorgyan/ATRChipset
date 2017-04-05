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
    virtual void SetSelection(const CSelection&) = 0;
    virtual IDList GetIDList() = 0;
    virtual IDList GetIDList(Field field) = 0;
    virtual FileInfo GetFileInfo(ID id) = 0;
    virtual QVariantList GetFieldList(CSelection,Field) = 0;
    virtual QVariantList GetFieldValues(Field field) const = 0;
    virtual QVariantList GetFieldValuesCorrespondingToSelection(const Field& field)const = 0;
};

#endif //__IDATADIRECTORY__
