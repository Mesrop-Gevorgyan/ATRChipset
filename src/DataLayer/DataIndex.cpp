#include "DataIndex.h"
#include <QVector>
#include <QSet>


DataIndex::DataIndex() :m_lots(), m_wafers(), m_devices(), m_infos()
{}

void DataIndex::SetFileInfos(CFileInfoList infos)
{
	m_infos = infos;
	__indexation();
}

void DataIndex::SetSelection(const CSelection& selection)
{
	m_selection = selection;
}

QVariantList DataIndex::GetFieldValues(Field field) const
{
	QVariantList result;

	if (field == LOT)
		for (auto key : m_lots.keys())
			result << key;

	if (field == WAFER)
		for (auto key : m_wafers.keys())
			result << key;

	if (field == DEVICE)
		for (auto key : m_devices.keys())
			result << key;
	return result;
}
QVariantList DataIndex::GetFieldValuesCorrespondingToSelection(const Field& field)const
{
	const SFieldValueSelection& selection = m_selection.getFieldValueSelection(field);
	QVariantList result;
	if (selection.aSelectedValues.size() == 0) //at first get selected values
	{
		result = GetFieldValues(field);
		if (selection.eSelectionType == ESelectionPattern::ValueSelection) //no selected values,any pattern
		{
			QRegExp pattern(selection.sPattern);
			for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
			{
				if (pattern.exactMatch((*it).toString()) == false)
					result.erase(it);//this does not match with pattern
			}
		}
	}
	else
		result = selection.aSelectedValues;
	return result;

}

/* Helper function,which adds all fileInfos to index */
void DataIndex::__indexation()
{
	for (int i =0;i<m_infos.count();++i)
	{	
		/* Get Context string list of specified fileInfo */
		FieldList context_list = m_infos[i].m_fileContext.GetFields(Context);

		for (auto context : context_list)
		{
			/* indexation of Files containig  info about Lots */
			if (context.contains(LOT))
			{
				if (m_lots.find(context) != m_lots.end())
					m_lots[context].push_back(i);
				else {
					IDList idList;
					idList.push_back(i);
					m_lots[context] = idList;
				}		
			}

			/* indexation of Files containig  info about Wafers */
			if (context.contains(WAFER))
			{
				if (m_lots.find(context) != m_lots.end())
					m_lots[context].push_back(i);
				else {
					IDList idList;
					idList.push_back(i);
					m_lots[context] = idList;
				}
			}

			/* indexation of Files containig  info about Devices */
			if (context.contains(DEVICE))
			{
				if (m_lots.find(context) != m_lots.end())
					m_lots[context].push_back(i);
				else {
					IDList idList;
					idList.push_back(i);
					m_lots[context] = idList;
				}
			}
		}
	}
}

/*
 *  Returns one IDList ,which contains unique IDs from list vector  
 */
IDList DataIndex::__mergeIDLists(QVector<IDList> list)
{
	QSet<int> result;
	for (auto IDs : list)
	{
		for (auto ID : IDs)
			result.insert(ID);
	}
	return IDList::fromSet(result);
}

/*
 *  Returns IDList of files,which Context contains @content
 */
IDList DataIndex::__getFileIDs(QString content)
{
	if (content.contains(LOT)) 
		return m_lots[content];

	if (content.contains(WAFER))
		return m_lots[content];

	if (content.contains(DEVICE))
		return m_lots[content];

	return IDList();
}

/*
 *  Returns merged IDList with unique IDs, corresponding to @pattern  
 */
IDList DataIndex::GetIDList(QStringList pattern)
{
	QVector<IDList> allIDs;
	
	for (auto content : pattern)
	{
		IDList temp = __getFileIDs(content);
		allIDs.push_back(temp);
	}

	return __mergeIDLists(allIDs);
}

/*
 * Returns FileInfo of file with @id 
 */
FileInfo DataIndex::GetFileInfo(ID id)
{
	return m_infos[id];
}

/*
*  Returns FieldList corresponding to @pattern
*  If we pass as @field for example "Lot" ,it returns FieldList containing all Lots ,in selection
*/
FieldList DataIndex::GetFieldList(QStringList pattern, Field field)
{
	IDList ids = this->GetIDList(pattern);
	FieldList result;

	for (auto id : ids)
	{
		if (m_infos[id].m_fileContext.contains(field))
			result.push_back(m_infos[id].m_fileContext.GetValue(field).toString());

	}
		
	return result;
}
