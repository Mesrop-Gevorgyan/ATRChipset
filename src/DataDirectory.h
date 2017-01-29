#ifndef DATADIRECTORY_H
#define DATADIRECTORY_H

#include "IDataDirectory.h"
#include "parser.h"
#include <QDir>
#include <QSet>
#include "FileInfoList.h"

class DataDirectory: public IDataDirectory
{
public:
    DataDirectory(QString);
    FieldList getFields()const;
    QVariantList getFieldValues(Field const& oID)const;
    CFileInfoList getFiles(const QSet<FileType>& fileTypes, const CFileInfoList &contextList)const;
    QSet<QString> getWafers()const;
    QSet<QString> getDevices()const;
    QSet<QString> getLots()const;
    QSet<QDateTime> getDates()const;
private:
    QMultiMap<FileType,FileInfo> m_type_file;

    QSet<QString> m_wafers,m_lots,m_devices;
    QSet<QDateTime> m_dates;
};


#endif // DATADIRECTORY_H
