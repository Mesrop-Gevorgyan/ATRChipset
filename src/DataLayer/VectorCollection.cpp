#include "VectorCollection.h"

CVectorCollection::CVectorCollection(QVector<IVector*> collection) : m_collection(collection) {}

CVectorCollection::CVectorCollection() : m_collection() {}

IVector * CVectorCollection::operator[](int index)
{
	return m_collection[index];
}

int CVectorCollection::size() const
{
	return m_collection.size();
}

int CVectorCollection::capacity() const
{
	return m_collection.size();
}
