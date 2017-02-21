


#ifndef WS_WAFERAREA_H
#define WS_WAFERAREA_H


// Includes
#include "wm_iwaferarea.h"

// Qt includes
#include <QtCore/QRect>

// STL includs
#include <cmath>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferArea, Translate data area points to screen area corresponding scale and opposite
//
class CWaferArea : public IWaferArea
{
public:
	// Default constructor
	inline CWaferArea();
	// Init constructor
	inline CWaferArea( double fXMin, double fXMax, double fYMin, double fYMax, QRectF const& rcScreen );
	// Destructor
	inline ~CWaferArea();

public:
	//
	//! Override IWaferArea Interface
	//
	// Translate data area points to screen
	// Translate one point
	double translate( double fPoint, EScaleDirection eScaleDirection ) const override;
	// Translate two point(x, y)
	QPointF translate( double fPoint, EScaleDirection eXScaleDirection, double fYPoint, EScaleDirection eYScaleDirection ) const override;
	QPointF translate( QPointF const& pointF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const override;
	// Translate size (weight, height)
	QSizeF translate( QSizeF const& sizeF ) const override;
	// Translate rect (x1, y1, x2, y2)
	QRectF translate( QRectF const& rectF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const override;

	// Reverse data area point from screen
	// Reverse one point
	double reverse( double fArea, EScaleDirection eScaleDirection ) const override;
	// Reverse two point(x, y)
	QPointF reverse( double fXArea, EScaleDirection eXScaleDirection, double fYArea, EScaleDirection eYScaleDirection ) const override;
	QPointF reverse( QPointF const& ptFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const override;
	// Reverse size (weight, height)
	QSizeF reverse( QSizeF const& szFArea ) const override;
	// Reverse rect (x1, y1, x2, y2)
	QRectF reverse( QRectF const& rcFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const override;

public:
	//
	//! Own Interface
	//
	// Set/Get X range
	inline void setXRange( double fXMin, double fXMax );
	inline void getXRange( double& fXMin, double& fXMax ) const;
	// Set/Get Y range
	inline void setYRange( double fYMin, double fYMax );
	inline void getYRange( double& fYMin, double& fYMax ) const;
	// Set/Get screen rect
	inline void setScreen( QRectF const& rcScreen );
	inline QRectF getScreen() const;

private:
	//
	//! Content
	//
	double		m_fXMin;
	double		m_fXMax;
	double		m_fYMin;
	double		m_fYMax;
	QRectF		m_rcFScreen;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
CWaferArea::CWaferArea()
	: m_fXMin(NAN),
	  m_fXMax(NAN),
	  m_fYMin(NAN),
	  m_fYMax(NAN),
	  m_rcFScreen(QRectF())
{
	
}

CWaferArea::CWaferArea( double fXMin, double fXMax, double fYMin, double fYMax, QRectF const& rcScreen )
	: m_fXMin(fXMin),
	  m_fXMax(fXMax),
	  m_fYMin(fYMin),
	  m_fYMax(fYMax),
	  m_rcFScreen(rcScreen)
{
	
}

CWaferArea::~CWaferArea()
{

}

inline void CWaferArea::setXRange( double fXMin, double fXMax )
{
	m_fXMin = fXMin;
	m_fXMax = fXMax;
}

inline void CWaferArea::getXRange( double& fXMin, double& fXMax ) const
{
	fXMin = m_fXMin;
	fXMax = m_fXMax;
}

inline void CWaferArea::setYRange( double fYMin, double fYMax )
{
	m_fYMin = fYMin;
	m_fYMax = fYMax;
}

inline void CWaferArea::getYRange( double& fYMin, double& fYMax ) const
{
	fYMin = m_fYMin;
	fYMax = m_fYMax;
}

inline void CWaferArea::setScreen( QRectF const& rcScreen )
{
	m_rcFScreen = rcScreen;
}

inline QRectF CWaferArea::getScreen() const
{
	return m_rcFScreen;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERAREA_H