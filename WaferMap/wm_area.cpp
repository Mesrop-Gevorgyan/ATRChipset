

// Includes
#include "wm_area.h"

// Qt includs
#include <QtCore\QPoint>
#include <QtCore\QSize>
#include <QtCore\QRect>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CArea
//
double wm::CArea::translate( double fLenght, Qt::Orientation eOrient ) const
{
	double fArea = NAN;
	if (eOrient == Qt::Horizontal)
		fArea = (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * fLenght;
	else
		fArea = (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * fLenght;
	return fArea;
}

double wm::CArea::translate( double fPoint, EScaleDirection eScaleDirection ) const
{
	double fArea = NAN;
	switch (eScaleDirection)
	{
	case EScaleDirection::LeftToRight:
		fArea = m_rcFScreen.left() + (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * (fPoint - m_fXMin);
		break;
	case EScaleDirection::RightToLeft:
		fArea = m_rcFScreen.right() - (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * (fPoint - m_fXMin);
		break;
	case EScaleDirection::BottomToTop:
		fArea = m_rcFScreen.bottom() - (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * (fPoint - m_fYMin);
		break;
	case EScaleDirection::TopToBottom:
		fArea = m_rcFScreen.top() + (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * (fPoint - m_fYMin);
		break;
	}
	return fArea;
}

QPointF wm::CArea::translate( double fXPoint, EScaleDirection eXScaleDirection, double fYPoint, EScaleDirection eYScaleDirection ) const
{
	QPointF ptFArea;
	ptFArea.setX( translate( fXPoint, eXScaleDirection ) );
	ptFArea.setY( translate( fYPoint, eYScaleDirection ) );
	return ptFArea;
}

QPointF wm::CArea::translate( QPointF const& pointF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QPointF ptFArea;
	ptFArea.setX( translate( pointF.x(), eXScaleDirection ) );
	ptFArea.setY( translate( pointF.y(), eYScaleDirection ) );
	return ptFArea;
}

QSizeF wm::CArea::translate( QSizeF const& sizeF ) const
{
	QSizeF szFArea;
	szFArea.setWidth( (m_rcFScreen.width() / (m_fXMax - m_fXMin)) * sizeF.width() );
	szFArea.setHeight( (m_rcFScreen.height() / (m_fYMax - m_fYMin)) * sizeF.height() );
	return szFArea;
}

QRectF wm::CArea::translate( QRectF const& rectF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QRectF rcFArea;
	QPointF ptFTopLeft = translate( rectF.topLeft(), eXScaleDirection, eYScaleDirection );
	QPointF ptFBottomRight = translate( rectF.bottomRight(), eXScaleDirection, eYScaleDirection );
	rcFArea.setTopLeft( ptFTopLeft );
	rcFArea.setBottomRight( ptFBottomRight );
	return rcFArea;
}

double wm::CArea::reverse( double fArea, Qt::Orientation eOrient ) const
{
	double fLength = NAN;
	if (eOrient == Qt::Horizontal)
		fLength = ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * fArea;
	else
		fLength = ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * fArea;
	return fLength;
}

double wm::CArea::reverse( double fArea, EScaleDirection eScaleDirection ) const
{
	double fPoint = NAN;
	switch (eScaleDirection)
	{
	case EScaleDirection::LeftToRight:
		fPoint = m_fXMin + ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * (fArea - m_rcFScreen.left());
		break;
	case EScaleDirection::RightToLeft:
		fPoint = m_fXMax - ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * (fArea - m_rcFScreen.left());
		break;
	case EScaleDirection::BottomToTop:
		fPoint = m_fYMax - ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * (fArea - m_rcFScreen.top());
		break;
	case EScaleDirection::TopToBottom:
		fPoint = m_fYMin + ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * (fArea - m_rcFScreen.top());
		break;
	}
	return fPoint;
}

QPointF wm::CArea::reverse( double fXArea, EScaleDirection eXScaleDirection, double fYArea, EScaleDirection eYScaleDirection ) const
{
	QPointF pointF;
	pointF.setX( reverse( fXArea, eXScaleDirection ) );
	pointF.setY( reverse( fYArea, eYScaleDirection ) );
	return pointF;
}

QPointF wm::CArea::reverse( QPointF const& ptFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QPointF pointF;
	pointF.setX( reverse( ptFArea.x(), eXScaleDirection ) );
	pointF.setY( reverse( ptFArea.y(), eYScaleDirection ) );
	return pointF;
}

QSizeF wm::CArea::reverse( QSizeF const& szFArea ) const
{
	QSizeF sizeF;
	sizeF.setWidth( ((m_fXMax - m_fXMin) / m_rcFScreen.width()) * szFArea.width() );
	sizeF.setWidth( ((m_fYMax - m_fYMin) / m_rcFScreen.height()) * szFArea.height() );
	return sizeF;
}

QRectF wm::CArea::reverse( QRectF const& rcFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const
{
	QRectF rectF;
	QPointF ptFTopLeft = reverse( rcFArea.topLeft(), eXScaleDirection, eYScaleDirection );
	QPointF ptFBottomRight = reverse( rcFArea.bottomRight(), eXScaleDirection, eYScaleDirection );
	rectF.setTopLeft( ptFTopLeft );
	rectF.setBottomRight( ptFBottomRight );
	return rectF;
}
///////////////////////////////////////////////////////////////////////////////