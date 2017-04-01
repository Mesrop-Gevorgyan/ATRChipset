#ifndef DATADIRECTORY_H
#define DATADIRECTORY_H

#include "idataDirectory.h"
#include "Parser.h"
#include <QDir>
#include "fileInfoList.h"

class DataDirectory: public IDataDirectory
{
public:
    DataDirectory(QString);
    void SetFileInfos(CFileInfoList);
    void SetSelection(const CSelection&);
    IDList GetIDList();
    IDList GetIDList(Field field);
    FileInfo GetFileInfo(ID id);
    QVariantList GetFieldList(CSelection,Field);
    QVariantList GetFieldValues(Field field) const;
    QVariantList GetFieldValuesCorrespondingToSelection(const Field& field)const;

private:
    CFileInfoList m_files;
    DataIndex m_dataIndex;
};

#endif // DATADIRECTORY_H
