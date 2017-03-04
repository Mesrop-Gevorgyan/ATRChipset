

#ifndef VECTOR_H
#define VECTOR_H

#include <QVector>
#include <QVariant>
#include "ivector.h"


class CIntVector : public IIntVector
{
public:
	CIntVector()
	{
		m_aData.reserve(500);
		for (int i = 0; i < 800; ++i)
			m_aData.append(qrand() % 9 + 1);
	}

	QVariant GetValue(unsigned index) const override
	{
		return QVariant(m_aData[index]);
	}

	int GetCount() const override
	{
		return m_aData.count();
	}

	int GetAt(unsigned index) const override
	{
		return m_aData[index];
	}

private:
	QVector<int>  m_aData;
};


#endif //! VECTOR_H