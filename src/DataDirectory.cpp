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
        m_type_file.insert(file_info.m_fileType, file_info);

        if (file_info.m_fileType == BinData ||
                file_info.m_fileType == ParameterData)                //for dataSElecetor
        {
            m_wafers.insert(file_info.m_fileContext.GetValue("Wafer").toString());
            m_lots.insert(file_info.m_fileContext.GetValue("Lot").toString());
            m_dates.insert(file_info.m_date);
        }
        m_devices.insert(file_info.m_fileContext.GetValue("Device").toString());
    }

}



bool operator==(const FileContext& context1,const FileContext& context2)
{
    if (context1.GetValue("Lot") == context2.GetValue("Lot"))
    {
        if (context1.GetValue("Wafer") == context2.GetValue("Wafer"))
        {
            if (context1.GetValue("Device") == context2.GetValue("Device"))
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}


CFileInfoList DataDirectory::getFiles(const QSet<FileType> &fileTypes, const CFileInfoList &contextList) const
{
    CFileInfoList FilesCorrespondingTypes;
    for(QSet<FileType>::const_iterator it = fileTypes.begin(); it != fileTypes.end(); ++it)
    {
        CFileInfoList CurrentList(m_type_file.values(*it));
        for (int i = 0; i < CurrentList.count(); ++i)
            FilesCorrespondingTypes.append(CurrentList[i]);
    }

    CFileInfoList result;

    for(int i = 0 ; i < contextList.count(); ++i)
    {
        for(int j = 0; j < FilesCorrespondingTypes.count(); ++j)
        {
            if (FilesCorrespondingTypes[j].m_fileContext == contextList[i].m_fileContext &&
                    FilesCorrespondingTypes[j].m_date == contextList[i].m_date)
                result.append(FilesCorrespondingTypes[j]);
            if (FilesCorrespondingTypes[j].m_fileContext.GetValue("Device")
                    == contextList[i].m_fileContext.GetValue("Device"))
                result.append(FilesCorrespondingTypes[j]);
        }
    }
    return result;
}


FieldList DataDirectory::getFields()const
{
    FieldList fieldList;
    if (m_wafers.size() != 0)
        fieldList.append("Wafer");
    if (m_lots.size() != 0)
        fieldList.append("Lot");
    if (m_devices.size() != 0)
        fieldList.append("Device");
    if (m_dates.size() != 0)
        fieldList.append("Date");
    return fieldList;
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

QSet<QString> DataDirectory::getWafers()const
{
    return m_wafers;
}

QSet<QString> DataDirectory::getDevices()const
{
    return m_devices;
}

QSet<QString> DataDirectory::getLots()const
{
    return m_lots;
}

QSet<QDateTime> DataDirectory::getDates()const
{
    return m_dates;
}

