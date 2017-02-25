#include "DataIndex.h"

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
			if (context.contains("Lot"))
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
			if (context.contains("Wafer"))
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
			if (context.contains("Device"))
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
