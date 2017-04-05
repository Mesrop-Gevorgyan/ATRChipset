#include "DataDirectory.h"

DataDirectory::DataDirectory(QString path)
{
    QDir direction(path);
    direction.setFilter(QDir::Files);
    QStringList NamesOfFiles = direction.entryList();
    if(NamesOfFiles.size() == 0)
        throw std::out_of_range("there is no any file");
    for (int i = 0; i < NamesOfFiles.size(); ++i)
    {
        CParser Parser(path +"/"+ NamesOfFiles.at(i));
        FileInfo file_info(Parser.scanner());
        m_files.append(file_info);
    }
    m_dataIndex.SetFileInfos(m_files);
}

void DataDirectory::SetSelection(const CSelection& oSelection)
{
    m_dataIndex.SetSelection(oSelection);
}

IDList DataDirectory::GetIDList()
{
    return m_dataIndex.GetIDList();
}

IDList DataDirectory::GetIDList(Field field)
{
    return m_dataIndex.GetIDList(field);
}

FileInfo DataDirectory::GetFileInfo(ID id)
{
    return m_dataIndex.GetFileInfo(id);
}

QVariantList DataDirectory::GetFieldList(CSelection oSelection, Field field)
{
    return m_dataIndex.GetFieldList(oSelection,field);
}

QVariantList DataDirectory::GetFieldValues(Field field) const
{
    return m_dataIndex.GetFieldValues(field);
}
QVariantList DataDirectory::GetFieldValuesCorrespondingToSelection(const Field& field)const
{
    return m_dataIndex.GetFieldValuesCorrespondingToSelection(field);
}

