


#ifndef WS_RULER_H
#define WS_RULER_H


// Includs
#include "wm_global.h"
#include "wm_drawer.h"

// Qt forward declarations
class QRect;
class QPainter;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

// Axis types
enum class EAxisType
{
	NoAxis		= 0x00,
	XAxis		= 0x01,
	X2Axis		= 0x02,
	YAxis		= 0x04,
	Y2Axis		= 0x08,
};


///////////////////////////////////////////////////////////////////////////////
//
// class CRuler
//
class CRuler : public CDrawer
{
public:
	// Default constructor
	inline CRuler();
	// Destructor
	inline ~CRuler();

public:
	//
	//! Own Interface
	//
	// Set/Get axis type
	inline void setAxisType( EAxisType eType );
	inline EAxisType getAxisType() const;
	// Set/Get tick label orientation
	inline void setTickLabelOrientation( EOrientation eOrient );
	inline EOrientation getTickLabelOrientation() const;
	// Do layout
	QRect doLayout( QRect const& rc ) override;
	// Draw scale (ticks and labels)
	void draw( QPainter* pPainter ) const override;

protected:
	//
	//! Implementation
	//

private:
	//
	//! Content
	//
	// Axis tpye
	EAxisType		m_eType;
	// Tick label orientation
	EOrientation	m_eTickLabelOrientation;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline implementation
//
inline CRuler::CRuler()
	: m_eType(EAxisType::NoAxis),
	  m_eTickLabelOrientation(EOrientation::Auto)
{

}

inline CRuler::~CRuler()
{

}

inline void CRuler::setAxisType( EAxisType eType )
{
	m_eType = eType;
}

inline EAxisType CRuler::getAxisType() const
{
	return m_eType;
}

inline void CRuler::setTickLabelOrientation( EOrientation eOrient )
{
	m_eTickLabelOrientation = eOrient;
}

inline EOrientation CRuler::getTickLabelOrientation() const
{
	return m_eTickLabelOrientation;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_RULER_H