

// Includes
#include "wm_waferarea.h"

// Qt includs
#include <QtCore\QPoint>
#include <QtCore\QSize>
#include <QtCore\QRect>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferArea
//
double wm::CWaferArea::translate( double fPoint, EScaleDirection eScaleDirection ) const
{
	double fArea = NAN;
	switch (eScaleDirection)
	{
	case eLeftToRight:
		fArea = m_rcFScreen.left() + (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * (fPoint - m_fXMin);
		break;
	case eRightToLeft:
		fArea = m_rcFScreen.right() - (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * (fPoint - m_fXMin);
		break;
	case eBottomToTop:
		fArea = m_rcFScreen.bottom() - (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * (fPoint - m_fYMin);
		break;
	case eTopToBottom:
		fArea = m_rcFScreen.top() + (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * (fPoint - m_fYMin);
		break;
	}
	return fArea;
}

QPointF wm::CWaferArea::translate( double fXPoint, EScaleDirection eXScaleDirection, double fYPoint, EScaleDirection eYScaleDirection ) const
{
	QPointF ptFArea(NAN, NAN);
	ptFArea.setX( translate( fXPoint, eXScaleDirection ) );
	ptFArea.setY( translate( fYPoint, eYScaleDirection ) );
	return ptFArea;
}

QPointF wm::CWaferArea::translate( QPointF const& pointF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QPointF ptFArea(NAN, NAN);
	ptFArea.setX( translate( pointF.x(), eXScaleDirection ) );
	ptFArea.setY( translate( pointF.y(), eYScaleDirection ) );
	return ptFArea;
}

QSizeF wm::CWaferArea::translate( QSizeF const& sizeF ) const
{
	QSizeF szFArea(NAN, NAN);
	szFArea.setWidth( (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * sizeF.width() );
	szFArea.setWidth( (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * sizeF.height() );
	return szFArea;
}

QRectF wm::CWaferArea::translate( QRectF const& rectF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QRectF rcFArea(NAN, NAN, NAN, NAN);
	QPointF ptFTopLeft = translate( rectF.topLeft(), eXScaleDirection, eYScaleDirection );
	QPointF ptFBottomRight = translate( rectF.bottomRight(), eXScaleDirection, eYScaleDirection );
	rcFArea.setTopLeft( ptFTopLeft );
	rcFArea.setBottomRight( ptFBottomRight );
	return rcFArea;
}

double wm::CWaferArea::reverse( double fArea, EScaleDirection eScaleDirection ) const
{
	double fPoint = NAN;
	switch (eScaleDirection)
	{
	case eLeftToRight:
		fPoint = m_fXMin + ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * (fArea - m_rcFScreen.left());
		break;
	case eRightToLeft:
		fPoint = m_fXMax - ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * (fArea - m_rcFScreen.left());
		break;
	case eBottomToTop:
		fPoint = m_fYMax - ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * (fArea - m_rcFScreen.top());
		break;
	case eTopToBottom:
		fPoint = m_fYMin + ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * (fArea - m_rcFScreen.top());
		break;
	}
	return fArea;
}

QPointF wm::CWaferArea::reverse( double fXArea, EScaleDirection eXScaleDirection, double fYArea, EScaleDirection eYScaleDirection ) const
{
	QPointF pointF(NAN, NAN);
	pointF.setX( reverse( fXArea, eXScaleDirection ) );
	pointF.setY( reverse( fYArea, eYScaleDirection ) );
	return pointF;
}

QPointF wm::CWaferArea::reverse( QPointF const& ptFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QPointF pointF(NAN, NAN);
	pointF.setX( reverse( ptFArea.x(), eXScaleDirection ) );
	pointF.setY( reverse( ptFArea.y(), eYScaleDirection ) );
	return pointF;
}

QSizeF wm::CWaferArea::reverse( QSizeF const& szFArea ) const
{
	QSizeF sizeF(NAN, NAN);
	sizeF.setWidth( ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * szFArea.width() );
	sizeF.setWidth( ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * szFArea.height() );
	return sizeF;
}

QRectF wm::CWaferArea::reverse( QRectF const& rcFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QRectF rectF(NAN, NAN, NAN, NAN);
	QPointF ptFTopLeft = reverse( rcFArea.topLeft(), eXScaleDirection, eYScaleDirection );
	QPointF ptFBottomRight = reverse( rcFArea.bottomRight(), eXScaleDirection, eYScaleDirection );
	rectF.setTopLeft( ptFTopLeft );
	rectF.setBottomRight( ptFBottomRight );
	return rectF;
}
///////////////////////////////////////////////////////////////////////////////
