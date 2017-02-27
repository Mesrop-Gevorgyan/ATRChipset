


#ifndef WS_WAFERMAP_H
#define WS_WAFERMAP_H


// Includes
#include "wm_drawable.h"
#include "wm_waferarea.h"
#include "wm_iwafermodel.h"

// Qt includes
#include <QtCore\QScopedPointer>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferMap, draw wafer map
//	
class CWaferMap : public CDrawable
{
public:
	// Default constructor
	inline CWaferMap();
	// Init constructor
	CWaferMap( IWaferModel const* pModel );
	// Destructor
	virtual ~CWaferMap();

public:
	//
	//! Override CDrawable interface
	//
	// Do layout
	QRect doLayout( QRect const& rc ) override;
	// Draw
	void draw( QPainter* pPainter ) const override;

public:
	//
	//! Own interface
	//
	// Set\Get wefer dimple position
	void setDimplePosition( EDimplePosition eDimplePos );
	EDimplePosition getDimplePosition() const;

protected:
	//
	//! implementation
	//
	virtual void drawDie( QPainter* pPainter, QRect const& rcDie, int nDieX, int nDieY ) const;

private:
	//
	//! Content
	//
	// Wafer model
	IWaferModel const*					m_pModel;
	// Wafer dimple position
	EDimplePosition						m_eDimplePos;
	// Wafer area for data translation
	QScopedPointer<CWaferArea>			m_pArea;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
wm::CWaferMap::CWaferMap()
	: m_pModel(nullptr),
	  m_eDimplePos(EDimplePosition::Bottom),
	  m_pArea(nullptr)
{

}

void wm::CWaferMap::setDimplePosition( EDimplePosition eDimplePos )
{
	m_eDimplePos = eDimplePos;
}

EDimplePosition wm::CWaferMap::getDimplePosition() const
{
	return m_eDimplePos;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERMAP_H