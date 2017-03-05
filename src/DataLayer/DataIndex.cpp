#include "DataIndex.h"
#include <QVector>
#include <QSet>

DataIndex::DataIndex(CFileInfoList infos):m_lots(),m_wafers(),m_devices(),m_infos(infos) 
{
	__indexation();
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
 *  Return merged IDList with unique IDs, corresponding to @pattern  
 */
IDList DataIndex::GetFileIDsWithPattern(QStringList pattern)
{
	QVector<IDList> allIDs;
	
	for (auto content : pattern)
	{
		IDList temp = __getFileIDs(content);
		allIDs.push_back(temp);
	}

	return __mergeIDLists(allIDs);
}
