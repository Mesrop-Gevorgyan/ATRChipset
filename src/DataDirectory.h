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
    IDList GetIDList(CSelection const& oSelection);
    FileInfo GetFileInfo(ID id);
    FieldList GetFieldList(CSelection const& oSelection, Field field);
private:
    CFileInfoList m_files;
    DataIndex m_dataIndex;
};

#endif // DATADIRECTORY_H
