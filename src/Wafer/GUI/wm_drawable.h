


#ifndef WS_DRAWABLE_H
#define WS_DRAWABLE_H


// Includes
#include "wm_global.h"


// Qt forword declaration
class QRect;
class QPainter;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Interface CDrawable
//
class CDrawable
{
public:
	// Default constructor
	inline CDrawable();
	// Destructor
	inline ~CDrawable();

public:
	//
	//! Own Interface
	//
	// Visibility
	void setVisible( bool b );
	bool getVisible() const;
	// Do layout
	virtual QRect doLayout( QRect const& rc ) = 0;
	// Draw
	virtual void draw( QPainter* pPainter ) const = 0;

private:
	//
	//! Content
	//
	bool		m_bVisible;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline implementation
//
inline CDrawable::CDrawable()
	: m_bVisible(true)
{

}

inline CDrawable::~CDrawable()
{

}

inline void CDrawable::setVisible( bool b )
{
	m_bVisible = b;
}

inline bool CDrawable::getVisible() const
{
	return m_bVisible;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERAREA_H