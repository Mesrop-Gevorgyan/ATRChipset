#ifndef __FILEINFO__
#define __FILEINFO__

#include <QString>
#include <QDateTime>
#include "FileContext.h"
#include "global.h"

// Contains info about single file
struct FileInfo
{
        int ID;
        FileContext m_fileContext;
        QDateTime m_date;
        FileType m_fileType;
        QString m_filePath;
        inline bool operator==(const FileInfo& info)
        {
                return this->ID == info.ID;
        }
};
#endif //__FILEINFO__
