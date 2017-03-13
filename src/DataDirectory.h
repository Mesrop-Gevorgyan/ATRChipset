#ifndef DATADIRECTORY_H
#define DATADIRECTORY_H

#include "idataDirectory.h"
#include "parser.h"
#include <QDir>
#include <QSet>
#include "fileInfoList.h"

class DataDirectory: public IDataDirectory
{
public:
    DataDirectory(QString);
    QVariantList getFieldValues(Field const& oID)const;
    IDList GetIDList(QStringList pattern);
    FileInfo GetFileInfo(ID id);
    FieldList GetFieldList(QStringList pattern, Field field);
    FileInfo GetCompleteFileInfo(const FileInfo&) const;
private:
    CFileInfoList m_files;
    DataIndex m_dataIndex;
    QSet<QString> m_wafers,m_lots,m_devices;
    QSet<QDateTime> m_dates;
};


#endif // DATADIRECTORY_H
