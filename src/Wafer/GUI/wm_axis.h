


#ifndef WS_AXIS_H
#define WS_AXIS_H


// Includs
#include "wm_global.h"
#include "wm_drawable.h"

// Qt forward declarations
class QRect;
class QPainter;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

// Axis types
enum class EAxisType
{
	eNoAxis		= 0x00,
	eXAxis		= 0x01,
	eX2Axis		= 0x02,
	eYAxis		= 0x04,
	eY2Axis		= 0x08,
};


///////////////////////////////////////////////////////////////////////////////
//
// class CAxis
//
class CAxis : public CDrawable
{
public:
	// Default constructor
	inline CAxis();
	// Destructor
	inline ~CAxis();

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
inline CAxis::CAxis()
	: m_eType(EAxisType::eNoAxis),
	  m_eTickLabelOrientation(EOrientation::eAuto)
{

}

inline CAxis::~CAxis()
{

}

inline void CAxis::setAxisType( EAxisType eType )
{
	m_eType = eType;
}

inline EAxisType CAxis::getAxisType() const
{
	return m_eType;
}

inline void CAxis::setTickLabelOrientation( EOrientation eOrient )
{
	m_eTickLabelOrientation = eOrient;
}

inline EOrientation CAxis::getTickLabelOrientation() const
{
	return m_eTickLabelOrientation;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_AXIS_H
