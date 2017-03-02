


#ifndef WS_AREA_H
#define WS_AREA_H


// Includes
#include "wm_global.h"

// Qt includes
#include <QRect>

// STL includs
#include <cmath>


// Qt forword declaration
class QPoint;
class QPointF;
class QSize;
class QSizeF;
class QRect;
class QRectF;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CArea, Translate data area points to screen area corresponding scale and opposite
//
class CArea
{
public:
	// Default constructor
	inline CArea();
	// Init constructor
	inline CArea( double fXMin, double fXMax, double fYMin, double fYMax, QRectF const& rcScreen );
	// Destructor
	inline ~CArea();

public:
	//
	//! Own Interface
	//
	// Get horizontal scale
	inline double getHScale() const;
	// Get vertical scale
	inline double getVScale() const;
	// Translate data area points to screen
	// Translate lenght
	double translate( double fLenght, Qt::Orientation eOrient ) const;
	// Translate one point
	double translate( double fPoint, EScaleDirection eScaleDirection ) const;
	// Translate two point(x, y)
	QPointF translate( double fPoint, EScaleDirection eXScaleDirection, double fYPoint, EScaleDirection eYScaleDirection ) const;
	QPointF translate( QPointF const& pointF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const;
	// Translate size (weight, height)
	QSizeF translate( QSizeF const& sizeF ) const;
	// Translate rect (x1, y1, x2, y2)
	QRectF translate( QRectF const& rectF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const;

	// Reverse data area point from screen
	// Reverse lenght
	double reverse( double fArea, Qt::Orientation eOrient ) const;
	// Reverse one point
	double reverse( double fArea, EScaleDirection eScaleDirection ) const;
	// Reverse two point(x, y)
	QPointF reverse( double fXArea, EScaleDirection eXScaleDirection, double fYArea, EScaleDirection eYScaleDirection ) const;
	QPointF reverse( QPointF const& ptFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const;
	// Reverse size (weight, height)
	QSizeF reverse( QSizeF const& szFArea ) const;
	// Reverse rect (x1, y1, x2, y2)
	QRectF reverse( QRectF const& rcFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const;

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
CArea::CArea()
	: m_fXMin(NAN),
	  m_fXMax(NAN),
	  m_fYMin(NAN),
	  m_fYMax(NAN),
	  m_rcFScreen(QRectF())
{
	
}

CArea::CArea( double fXMin, double fXMax, double fYMin, double fYMax, QRectF const& rcScreen )
	: m_fXMin(fXMin),
	  m_fXMax(fXMax),
	  m_fYMin(fYMin),
	  m_fYMax(fYMax),
	  m_rcFScreen(rcScreen)
{
	
}

CArea::~CArea()
{

}

inline void CArea::setXRange( double fXMin, double fXMax )
{
	m_fXMin = fXMin;
	m_fXMax = fXMax;
}

inline void CArea::getXRange( double& fXMin, double& fXMax ) const
{
	fXMin = m_fXMin;
	fXMax = m_fXMax;
}

inline void CArea::setYRange( double fYMin, double fYMax )
{
	m_fYMin = fYMin;
	m_fYMax = fYMax;
}

inline void CArea::getYRange( double& fYMin, double& fYMax ) const
{
	fYMin = m_fYMin;
	fYMax = m_fYMax;
}

inline void CArea::setScreen( QRectF const& rcScreen )
{
	m_rcFScreen = rcScreen;
}

inline QRectF CArea::getScreen() const
{
	return m_rcFScreen;
}

inline double wm::CArea::getHScale() const
{
	return (m_rcFScreen.width() / (m_fXMax - m_fXMin));
}

inline double wm::CArea::getVScale() const
{
	return (m_rcFScreen.height() / (m_fYMax - m_fYMin));
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_AREA_H