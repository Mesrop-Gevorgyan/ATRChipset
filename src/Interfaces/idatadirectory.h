#ifndef __IDATADIRECTORY__
#define __IDATADIRECTORY__


#include <QVariant>
//class QVariantList;
#include "DataStore.h"
#include "FileInfoList.h"
#include "DataIndex.h"

typedef  QStringList FieldList;

class IDataDirectory
{
public:
    virtual QVariantList getFieldValues(Field const& oID) const = 0;
    virtual IDList GetIDList(QStringList pattern) = 0;
    virtual FileInfo GetFileInfo(ID id)  =  0;
    virtual FieldList GetFieldList(QStringList pattern, Field field)  = 0;
    virtual FileInfo GetCompleteFileInfo(const FileInfo&)const = 0;
};

#endif //__IDATADIRECTORY__
