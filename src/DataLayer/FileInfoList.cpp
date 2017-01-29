#include "FileInfoList.h"

CFileInfoList::CFileInfoList() : m_infos()
{
}

CFileInfoList::CFileInfoList(QList<FileInfo> infos) : m_infos(infos)
{
}

/*
 *   Appends a new fileInfo to FileInfoList       
 */
void CFileInfoList::append(const FileInfo & fileInfo)
{
        m_infos.append(fileInfo);       
}

/*
 *   Returns a fileInfo associated with @index 
 */
const FileInfo & CFileInfoList::at(unsigned index) const
{
        return m_infos[index];
}

/*
 *   Returns number of occurences of @fileInfo in the FileInfoList
 */
int CFileInfoList::count(const FileInfo& fileInfo) const
{
        return m_infos.count(fileInfo);
}

/*
 *   Retunrns count of elements in fileInfoList 
 */
int CFileInfoList::count() const
{
        return m_infos.count();
}
/*
 *  Returns true ,in @fileInfo exists in the list
 */
bool CFileInfoList::contains(const FileInfo& fileInfo) const
{
        return m_infos.contains(fileInfo);
}

/*
*  Returns true ,if list is empty,otherwise:false
*/
bool CFileInfoList::isEmpty() const
{
        return m_infos.empty();
}

/*
 *  Returns a fileInfo associated with @index
 */
const FileInfo& CFileInfoList::operator[](unsigned index) const
{
        return m_infos[index];
}
