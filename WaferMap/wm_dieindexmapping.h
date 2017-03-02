


#ifndef WS_INDEXMAPPING_H
#define WS_INDEXMAPPING_H


// Qt Includs
#include <QPair>
#include <QHash>
#include <QList>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CDieIndexMapping, with inline implementation
//
class CDieIndexMapping
{
public:
	// Default constructor
	inline CDieIndexMapping();
	// Destructor
	inline ~CDieIndexMapping();

public:
	//
	//! Own Interface
	//
	// Get index count
	inline int getCount() const;
	// Check indecies array is empty
	inline bool isEmpty() const;
	inline bool contains( QPair<int, int> const& parDieXY ) const;
	// Get die cordinats
	inline QList<QPair<int, int>> getDieCordinats() const;
	// Clear
	inline void clear();
	// Append index
	inline void insert( QPair<int, int> const& parDieXY, int nIndex );
	// Prepend index
	inline void remove( QPair<int, int> const& parDieXY );
	// Get index
	inline int at( int nDieX, int nDieY ) const;
	// Operators
	inline int& operator[]( QPair<int, int> const& parDieXY );
	inline int operator[]( QPair<int, int> const& parDieXY ) const;

private:
	//
	//! Content
	//
	QHash<QPair<int, int>, int>		m_oDieIndices;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline implementation
//
inline CDieIndexMapping::CDieIndexMapping()
{

}

inline CDieIndexMapping::~CDieIndexMapping()
{

}

inline int CDieIndexMapping::getCount() const
{
	return m_oDieIndices.count();
}

inline bool CDieIndexMapping::isEmpty() const
{
	return m_oDieIndices.isEmpty();
}

inline bool CDieIndexMapping::contains( QPair<int, int> const& parDieXY ) const
{
	return m_oDieIndices.contains( parDieXY );
}

inline QList<QPair<int, int>> CDieIndexMapping::getDieCordinats() const
{
	return m_oDieIndices.keys();
}

inline void CDieIndexMapping::clear()
{
	m_oDieIndices.clear();
}

inline void CDieIndexMapping::insert( QPair<int, int> const& parDieXY, int nIndex )
{
	m_oDieIndices.insert( parDieXY, nIndex );
}

inline void CDieIndexMapping::remove( QPair<int, int> const& parDieXY )
{
	m_oDieIndices.remove( parDieXY );
}

inline int CDieIndexMapping::at( int nDieX, int nDieY ) const
{
	return m_oDieIndices.value( QPair<int, int>(nDieX, nDieY), -1 );
}

inline int& CDieIndexMapping::operator[]( QPair<int, int> const& parDieXY )
{
	auto it = m_oDieIndices.find( parDieXY );
	if (it == m_oDieIndices.end())
		it = m_oDieIndices.insert( parDieXY , -1 );
	return it.value();
}

inline int CDieIndexMapping::operator[]( QPair<int, int> const& parDieXY ) const
{
	return m_oDieIndices.value( parDieXY, -1 );
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_INDEXMAPPING_H