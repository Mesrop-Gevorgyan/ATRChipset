#include "DataIndex.h"
#include <QVector>
#include <QSet>


DataIndex::DataIndex() :m_lots(), m_wafers(), m_devices(), m_infos()
{	
	hasSelection = false;
}

void DataIndex::SetFileInfos(CFileInfoList infos)
{
	m_infos = infos;
	__indexation();
}

void DataIndex::SetSelection(const CSelection& selection)
{
	m_selection = selection;
	hasSelection = true;
}

/*
 *  Returns file ID list corresponding to  all @selection
 */
IDList DataIndex::GetIDList()
{
	if (hasSelection)
	{
		QStringList pattern;
		for (int i = 0; i < m_selection.getCount(); ++i)
		{
			if (m_selection.getAt(i).eType == ESelectionPattern::Value) {

				QVariantList result = m_selection.getAt(i).aValues;
				for (auto field : result)
					pattern << field.toString();
			}

			if (m_selection.getAt(i).eType == ESelectionPattern::Pattern)
			{
				QVariantList result = GetFieldValues(m_selection.getAt(i).oFieldID);
				QRegExp pattern_exp(m_selection.getAt(i).sPattern);

				for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
				{
					if (pattern_exp.exactMatch((*it).toString()) == false)
						result.erase(it);//this does not match with pattern
				}

				for (auto field : result)
					pattern << field.toString();
			}
		}
		return __getIDList(pattern);
	}

	return IDList();
}

/*
*  Returns file ID list corresponding to  @field of member @selection
*/
IDList DataIndex::GetIDList(Field field)
{
	if (hasSelection)
	{
		QStringList pattern;
		SFieldValueSelection selection = m_selection.getFieldValueSelection(field);
		QVariantList result;

		if (selection.eType == ESelectionPattern::Pattern) 
		{
			result = GetFieldValues(field);
			QRegExp pattern(selection.sPattern);
			for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
			{
				if (pattern.exactMatch((*it).toString()) == false)
					result.erase(it);//this does not match with pattern
			}
		}
		else {
			if (selection.eType == ESelectionPattern::Value)
				result = selection.aValues;
		}	

		for (auto field : result)
			pattern << field.toString();

		return __getIDList(pattern);
	}
	return IDList();
}

/*
 *  Returns all @fields in data index 
 *  If we pass "lot" , function returns all lots in DataIndex
 */
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

/*
 *  Returns all @field values in selection
 *  If we pass "lot" ,function returns all lots in selection
 */

QVariantList DataIndex::GetFieldValuesCorrespondingToSelection(const Field& field)const
{
	SFieldValueSelection selection = m_selection.getFieldValueSelection(field);
	QVariantList result;

	if (selection.eType == ESelectionPattern::Pattern)
	{
		result = GetFieldValues(field);
		QRegExp pattern(selection.sPattern);
		for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
		{
			if (pattern.exactMatch((*it).toString()) == false)
				result.erase(it);//this does not match with pattern
		}
	}
	else {
		if (selection.eType == ESelectionPattern::Value)
			result = selection.aValues;
	}

	return result;

}

/* Helper function,which adds all fileInfos to index */
void DataIndex::__indexation()
{
	
	for (int i =0;i<m_infos.count();++i)
	{	
		/* Get Context string list of specified fileInfo */
		QVariantList context = m_infos[i].m_fileContext.GetValues(Context);
		FieldList context_list;

		for (auto v : context)
			context_list << v.toString();

		for (auto context : context_list)
		{
			std::cout << "Context = " << context.toStdString() << std::endl;

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
				if (m_wafers.find(context) != m_wafers.end())
					m_wafers[context].push_back(i);
				else {
					IDList idList;
					idList.push_back(i);
					m_wafers[context] = idList;
				}
			}

			/* indexation of Files containig  info about Devices */
			if (context.contains(DEVICE))
			{
				if (m_devices.find(context) != m_devices.end())
					m_devices[context].push_back(i);
				else {
					IDList idList;
					idList.push_back(i);
					m_devices[context] = idList;
				}
			}
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < m_lots.keys().count(); ++i)
		std::cout <<"Lots " <<m_lots.keys().at(i).toStdString() << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < m_wafers.keys().count(); ++i)
		std::cout << "Wafer " << m_wafers.keys().at(i).toStdString() << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < m_devices.keys().count(); ++i)
		std::cout << "Devices " << m_devices.keys().at(i).toStdString() << std::endl;
	
	std::cout << std::endl;
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
IDList DataIndex::__getIDList(QStringList pattern)
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
*  Returns FieldList corresponding to @custom_selection
*  If we pass as @field for example "Lot" ,it returns FieldList containing all Lots ,in selection
*/
QVariantList DataIndex::GetFieldList(CSelection custom_selection, Field field)
{
	const SFieldValueSelection& selection = custom_selection.getFieldValueSelection(field);
	QVariantList result;

	if (selection.eType == ESelectionPattern::Pattern)
	{
		result = GetFieldValues(field);
		QRegExp pattern(selection.sPattern);
		for (QVariantList::iterator it = result.begin(); it != result.end(); ++it)
		{
			if (pattern.exactMatch((*it).toString()) == false)
				result.erase(it);//this does not match with pattern
		}
	}
	else {
		if (selection.eType == ESelectionPattern::Value)
			result = selection.aValues;
	}
		
	return result;
}
