#ifndef __DataStore__
#define __DataStore__

#include <QString>
#include <QVector>
#include <QMap>
#include <QDateTime>
#include "IVector.h"
#include "FileContext.h"
#include "VectorCollection.h"
#include "global.h"

// Contains info of single file
struct FileInfo
{
        FileContext m_fileContext;
        QDateTime m_date;
        FileType m_fileType;
        QString m_filePath;
};

class DataStore
{
public:
	DataStore();
	void add(FileInfo, CVectorCollection);
	CVectorCollection getBinData(const FileInfo&) const;
private:
	QMap<FileInfo, CVectorCollection> m_data;
};

#endif //__DataStore__
