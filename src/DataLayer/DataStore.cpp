#include "DataStore.h"

DataStore::DataStore(): m_data() {}

void DataStore::add(ID id, FileData fileData)
{
	m_data.insert(id,fileData);
}

FileData DataStore::GetSingleFileData(ID id) const
{
	return m_data[id];	
}

bool DataStore::contains(ID index) const
{
	return false;
}
