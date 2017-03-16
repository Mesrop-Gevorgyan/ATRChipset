#ifndef __CVECTORCOLLECTION__
#define __CVECTORCOLLECTION__

#include "ivector.h"
#include "global.h"
#include <Qvector>

class CVectorCollection
{
public:
	CVectorCollection(QVector<IVectorPtr>);
	CVectorCollection();
	IVectorPtr operator[](unsigned);
	int size() const;
	int capacity() const;
private:
	QVector<IVectorPtr> m_collection;
};

#endif //__CVECTORCOLLECTION__
