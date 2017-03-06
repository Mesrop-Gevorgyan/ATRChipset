#ifndef __IDATADIRECTORY__
#define __IDATADIRECTORY__

#include <QVariant>
#include "global.h"
#include "DataStore.h"
#include "FileInfoList.h"

class IDataDirectory
{
public:
    // Get field list of all field types
    virtual FieldList getFields() const = 0;
    // Get values as QVariant of field
    virtual QVariantList getFieldValues(Field const& oID) const = 0;
    //Get information corresponding files
    virtual CFileInfoList getFiles(const QSet<FileType>&,const CFileInfoList &) const = 0;
    //Get wafer names
    virtual QSet<QString> getWafers() const = 0;
    //Get device name
    virtual QSet<QString> getDevices() const = 0;
    //Get Lot name
    virtual QSet<QString> getLots() const = 0;
    //Get dates
    virtual QSet<QDateTime> getDates()const = 0;
};

#endif //__IDATADIRECTORY__
