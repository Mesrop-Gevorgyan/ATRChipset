#include "VectorCollection.h"

CVectorCollection::CVectorCollection(QVector<IVectorPtr> collection) : m_collection(collection) {}

CVectorCollection::CVectorCollection() : m_collection() {}

IVectorPtr CVectorCollection::operator[](unsigned index)
{
        if (index >= this->size())
                return IVectorPtr();
	return m_collection[index];
}

int CVectorCollection::size() const
{
	return m_collection.size();
}

int CVectorCollection::capacity() const
{
	return m_collection.capacity();
}
