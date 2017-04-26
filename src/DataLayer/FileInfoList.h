#ifndef __FILEINFOLIST__
#define __FILEINFOLIST__

#include <QList>
#include "FileInfo.h"

class CFileInfoList
{
public:
        CFileInfoList();
        CFileInfoList(QList<FileInfo>);
        void append(const FileInfo&);
        const FileInfo& at(unsigned) const;
        int count(const FileInfo&) const;
        int count() const;
	IDList getIDList() const;
	int indexof(const FileInfo&) const;
        bool contains(const FileInfo&) const; 
        bool isEmpty() const;
        const FileInfo& operator[](unsigned ) const;
private:
        QList <FileInfo> m_infos;
};


#endif // __FILEINFOLIST__
