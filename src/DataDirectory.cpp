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
        if (file_info.m_fileType == BinData ||
                file_info.m_fileType == ParameterData)
        {
            m_wafers.insert(file_info.m_fileContext.GetValue(WAFER).toString());
            m_lots.insert(file_info.m_fileContext.GetValue(LOT).toString());
            m_dates.insert(file_info.m_date);
        }
        m_devices.insert(file_info.m_fileContext.GetValue(DEVICE).toString());
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

QVariantList DataDirectory::getFieldValues(Field const& oID)const
{
    QVariantList result;
    if (oID == "Wafer")
    {
        for(QSet<QString>::const_iterator it = m_wafers.begin(); it != m_wafers.end(); ++it)
            result.append(*it);
    }
    if (oID == "Device")
    {
        for(QSet<QString>::const_iterator it = m_devices.begin(); it != m_devices.end(); ++it)
            result.append(*it);
    }
    if (oID == "Lot")
    {
        for(QSet<QString>::const_iterator it = m_lots.begin(); it != m_lots.end(); ++it)
            result.append(*it);
    }
    if (oID == "Date")
    {
        for(QSet<QDateTime>::const_iterator it = m_dates.begin(); it != m_dates.end(); ++it)
            result.append(*it);
    }
    return result;
}
