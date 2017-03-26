#ifndef DATADIRECTORY_H
#define DATADIRECTORY_H

#include "idataDirectory.h"
#include "parser.h"
#include <QDir>
#include "fileInfoList.h"

class DataDirectory: public IDataDirectory
{
public:
    DataDirectory(QString);
    QVariantList GetFieldValues(Field const& oID)const;
    IDList GetIDList(QStringList pattern);
    FileInfo GetFileInfo(ID id);
    FieldList GetFieldList(QStringList pattern, Field field);
    FileInfo GetCompleteFileInfo(const FileInfo&) const;
private:
    CFileInfoList m_files;
    DataIndex m_dataIndex;
};

#endif // DATADIRECTORY_H
