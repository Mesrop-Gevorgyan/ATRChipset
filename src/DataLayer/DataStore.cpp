#include "DataStore.h"

DataStore::DataStore(): m_data() {}

void DataStore::add(ID id, CVectorCollection binData)
{
	m_data.insert(id,binData);
}

CVectorCollection DataStore::GetSingleFileData(ID id) const
{
	if (m_data.contains(id))
		return m_data[id];
	else
		return CVectorCollection();
}

CVectorCollection DataStore::GetDataByPattern(IDList ids) const
{
	QVector<CVectorCollection> data;
	
	for (auto id : ids)
	{
		CVectorCollection temp = GetSingleFileData(id);
		data.push_back(temp);
	}

}
