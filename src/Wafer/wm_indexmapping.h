


#ifndef WS_INDEXMAPPING_H
#define WS_INDEXMAPPING_H


// Qt Includs
#include <QtCore\QVector>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CIndexMapping, inline implementation
//
class CIndexMapping
{
public:
	// Default constructor
	inline CIndexMapping();
	// Init counstructor
	inline CIndexMapping( QVector<int> const& oIndices );
	// Copy constructor
	inline CIndexMapping( CIndexMapping const& other );
	// Destructor
	inline ~CIndexMapping();

public:
	//
	//! Own Interface
	//
	// Set indices
	inline void setIndices( QVector<int> const& oIndices );
	// Get inddces
	inline QVector<int> getIndices() const;
	// Get index count
	inline int getCount() const;
	// Check indecies array is empty
	inline bool isEmpty() const;
	// Clear
	inline void clear();
	// Append index
	inline void append( int nVirtualIndex );
	// Prepend index
	inline void prepend( int nVirtualIndex );
	// Pop back
	inline int popBack();
	// Pop front
	inline int popFront();
	// First index
	inline int getFirst() const;
	// Last index
	inline int getLast() const;
	// Get index
	inline int at( int nVirtualIndex ) const;	
	// Operators
	inline int& operator[]( int nVirtualIndex );
	inline int operator[]( int nVirtualIndex ) const;

private:
	//
	//! Content
	//
	QVector<int>		m_oIndices;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline implementation
//
inline CIndexMapping::CIndexMapping()
{

}

inline CIndexMapping::CIndexMapping( QVector<int> const& oIndices )
	: m_oIndices(oIndices)
{

}

inline CIndexMapping::CIndexMapping( CIndexMapping const& other )
	: m_oIndices(other.m_oIndices)
{

}

inline CIndexMapping::~CIndexMapping()
{

}

inline void CIndexMapping::setIndices( QVector<int> const& oIndices )
{
	m_oIndices = oIndices;
}

inline QVector<int> CIndexMapping::getIndices() const
{
	return m_oIndices;
}

inline int CIndexMapping::getCount() const
{
	return m_oIndices.count();
}

inline bool CIndexMapping::isEmpty() const
{
	return m_oIndices.isEmpty();
}

inline void CIndexMapping::clear()
{
	m_oIndices.clear();
}

inline void CIndexMapping::append( int nVirtualIndex )
{
	m_oIndices.append( nVirtualIndex );
}

inline void CIndexMapping::prepend( int nVirtualIndex )
{
	m_oIndices.prepend( nVirtualIndex );
}

inline int CIndexMapping::popBack()
{
	Q_ASSERT(!m_oIndices.isEmpty());
	int nIndex = m_oIndices.last();
	m_oIndices.pop_back();
	return nIndex;
}

inline int CIndexMapping::popFront()
{
	Q_ASSERT(!m_oIndices.isEmpty());
	int nIndex = m_oIndices.first();
	m_oIndices.pop_front();
	return nIndex;
}

inline int CIndexMapping::getFirst() const
{
	Q_ASSERT(!m_oIndices.isEmpty());;
	return m_oIndices.first();
}

inline int CIndexMapping::getLast() const
{
	Q_ASSERT(!m_oIndices.isEmpty());;
	return m_oIndices.last();
}

inline int CIndexMapping::at( int nVirtualIndex ) const
{
	Q_ASSERT(nVirtualIndex >= 0 && nVirtualIndex < m_oIndices.size());
	return m_oIndices.at(nVirtualIndex);
}

inline int& CIndexMapping::operator[]( int nVirtualIndex )
{
	Q_ASSERT(nVirtualIndex >= 0 && nVirtualIndex < m_oIndices.size());
	return m_oIndices[nVirtualIndex];
}

inline int CIndexMapping::operator[]( int nVirtualIndex ) const
{
	Q_ASSERT(nVirtualIndex >= 0 && nVirtualIndex < m_oIndices.size());
	return m_oIndices[nVirtualIndex];
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_INDEXMAPPING_H
