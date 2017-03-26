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
        parser Parser(path +"/"+ NamesOfFiles.at(i));
        FileInfo file_info(Parser.scanner());
        m_files.append(file_info);
    }
    m_dataIndex.SetFileInfos(m_files);
}


IDList DataDirectory::GetIDList(QStringList pattern)
{
    return m_dataIndex.GetIDList(pattern);
}

FileInfo DataDirectory::GetFileInfo(ID id)
{
    return m_dataIndex.GetFileInfo(id);
}

FieldList DataDirectory::GetFieldList(QStringList pattern, Field field)
{
    return m_dataIndex.GetFieldList(pattern,field);
}


bool operator==(const FileContext& context1,const FileContext& context2)
{
    if (context1.GetValue(LOT) == context2.GetValue(LOT))
    {
        if (context1.GetValue(WAFER) == context2.GetValue(WAFER))
        {
            if (context1.GetValue(DEVICE) == context2.GetValue(DEVICE))
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

QVariantList DataDirectory::GetFieldValues(Field const& oID)const
{
	return m_dataIndex.GetFieldValues(oID);
}

FileInfo DataDirectory::GetCompleteFileInfo(const FileInfo& fileInfo)const
{
    int index = m_files.count(fileInfo);
    return m_files[index];
}
