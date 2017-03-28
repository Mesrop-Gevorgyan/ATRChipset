#ifndef __DATAINDEX__
#define __DATAINDEX__

#include <QVector>
#include "global.h"
#include "FileInfo.h"
#include "FileInfoList.h"
#include "selection.h"

class DataIndex
{
public:
	DataIndex();
	void SetFileInfos(CFileInfoList);
	void SetSelection(const CSelection&);
	IDList GetIDList();
	IDList GetIDList(Field field);
	FileInfo GetFileInfo(ID id);
	QVariantList GetFieldList(CSelection,Field);
	QVariantList GetFieldValues(Field field) const;
	QVariantList GetFieldValuesCorrespondingToSelection(const Field& field)const;
private:
	void __indexation();
	IDList __getIDList(QStringList);
	IDList __getFileIDs(QString content);
	IDList __mergeIDLists(QVector<IDList> list);
	QMap <QString, IDList> m_lots;
	QMap <QString, IDList> m_wafers;
	QMap <QString, IDList> m_devices;
	CFileInfoList m_infos;
	CSelection m_selection;
	bool hasSelection;
};

#endif //__DATAINDEX__
