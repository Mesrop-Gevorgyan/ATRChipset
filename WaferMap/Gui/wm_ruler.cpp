

// Includes
#include "wm_ruler.h"

// Qt includs
#include <QRect>
#include <QFont>
#include <QFontMetrics>
#include <QPainter>
#include <QApplication>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CRuler
//
void wm::CRuler::doLayout( QRect const& rc )
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pWaferModel);
	m_pArea->setScreen( rc );

	m_lstTicks.clear();
	if (m_eRulerAlign == ERulerAligment::Top || m_eRulerAlign == ERulerAligment::Bottom)
	{
		int nDieXMin = 0;
		int nDieXMax = 0;
		getDieCoordinates( nDieXMin, nDieXMax );
		if (nDieXMin > nDieXMax)
			return;
		m_lstTicks.reserve( nDieXMax - nDieXMin + 1 );
		for (int i = nDieXMin; i <= nDieXMax; ++i)
		{
			QRectF rcFDie = m_pWaferModel->getDieRect( i, 0 );
			rcFDie = m_pArea->translate( rcFDie, EScaleDirection::LeftToRight, EScaleDirection::TopToBottom );
			STickDie oTick;
			oTick.nStart = rcFDie.left();
			oTick.nEnd = rcFDie.right();
			oTick.sLabel = QString::number( i );
			m_lstTicks.append( oTick );
		}
	}
	else
	{
		int nDieYMin = 0;
		int nDieYMax = 0;
		getDieCoordinates( nDieYMin, nDieYMax );
		if (nDieYMin > nDieYMax)
			return;
		m_lstTicks.reserve( nDieYMax - nDieYMin + 1 );
		for (int i = nDieYMin; i <= nDieYMax; ++i)
		{
			QRectF rcFDie = m_pWaferModel->getDieRect( 0, i );
			rcFDie = m_pArea->translate( rcFDie, EScaleDirection::LeftToRight, EScaleDirection::TopToBottom );
			STickDie oTick;
			oTick.nStart = rcFDie.top();
			oTick.nEnd = rcFDie.bottom();
			oTick.sLabel = QString::number( i );
			m_lstTicks.append( oTick );
		}
	}
}

void wm::CRuler::draw( QPainter* pPainter ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pArea);

	QFont oFont = pPainter->font();
	QFontMetrics fm(oFont);
	int nShift = 3 + fm.height() + 2;
	if (m_eRulerAlign == ERulerAligment::Top || m_eRulerAlign == ERulerAligment::Bottom)
	{
		QLine oLine;
		for (int i = 0; i < m_lstTicks.size(); ++i)
		{
			STickDie oTick = m_lstTicks[i];
			QLine olineTick(oTick.nStart, nShift, oTick.nStart, nShift + 7);
			pPainter->drawLine( olineTick );
			olineTick.setLine( oTick.nEnd, nShift, oTick.nEnd, nShift + 7 );
			pPainter->drawLine( olineTick );
			QRect rcLabel = fm.boundingRect( oTick.sLabel );
			if (rcLabel.width() <= oTick.nEnd - oTick.nStart)
			{
				rcLabel.setLeft( oTick.nStart );
				rcLabel.setRight( oTick.nEnd );
				rcLabel.setTop( 3 );
				rcLabel.setHeight( fm.height() );
				pPainter->drawText( rcLabel, Qt::AlignCenter, oTick.sLabel );
			}
			if (oLine.isNull())
				oLine.setLine( oTick.nStart, nShift + 8, oTick.nEnd, nShift + 8 );
			else
				oLine.setLine( qMin( oTick.nStart, oLine.p1().x() ), nShift + 8, qMax( oTick.nEnd, oLine.p2().x() ), nShift + 8 );
		}
		if (!oLine.isNull())
		{
			QPen oPen = pPainter->pen();
			oPen.setWidth( 2 );
			pPainter->setPen( oPen );
			pPainter->drawLine( oLine );
			oPen.setWidth( 1 );
			pPainter->setPen( oPen );
		}
	}
	else
	{
		QLine oLine;
		for (int i = 0; i < m_lstTicks.size(); ++i)
		{
			STickDie oTick = m_lstTicks[i];
			QLine olineTick(nShift, oTick.nStart, nShift + 7, oTick.nStart);
			pPainter->drawLine( olineTick );
			olineTick.setLine( nShift, oTick.nEnd, nShift + 7, oTick.nEnd );
			pPainter->drawLine( olineTick );
			QRect rcLabel = fm.boundingRect( oTick.sLabel );
			if (rcLabel.width() <= oTick.nEnd - oTick.nStart)
			{
				rcLabel.setLeft( -oTick.nStart );
				rcLabel.setRight( -oTick.nEnd );
				rcLabel.setTop( 3 );
				rcLabel.setHeight( fm.height() );
				pPainter->rotate(-90);
				pPainter->drawText( rcLabel, Qt::AlignCenter, oTick.sLabel );
				pPainter->rotate(90);
			}
			if (oLine.isNull())
				oLine.setLine( nShift + 8, oTick.nStart, nShift + 8, oTick.nEnd );
			else
				oLine.setLine( nShift + 8, qMin( oTick.nStart, oLine.p1().y() ), nShift + 8, qMax( oTick.nEnd, oLine.p2().y() ) );
		}
		if (!oLine.isNull())
		{
			QPen oPen = pPainter->pen();
			oPen.setWidth( 2 );
			pPainter->setPen( oPen );
			pPainter->drawLine( oLine );
			oPen.setWidth( 1 );
			pPainter->setPen( oPen );
		}
	}
}

void wm::CRuler::getDieCoordinates( int& nDieMin, int& nDieMax ) const
{
	Q_ASSERT(m_pWaferModel);

	nDieMin = 1000000;
	nDieMax = -1000000;
	m_pWaferModel->getDieCordinats();
	QList<QPair<int, int>> const aAllDieCordinats = m_pWaferModel->getDieCordinats();
	for (int i = 0; i < aAllDieCordinats.size(); ++i)
	{
		int nDie;
		if (m_eRulerAlign == ERulerAligment::Top || m_eRulerAlign == ERulerAligment::Bottom)
			nDie = aAllDieCordinats[i].first;
		else
			nDie = aAllDieCordinats[i].second;
		if (nDie < nDieMin)
			nDieMin = nDie;
		if (nDie > nDieMax)
			nDieMax = nDie;
	}
}

int wm::CRuler::getPreferedSize() const
{
	return 5 + QApplication::fontMetrics().height() + 10;
}
///////////////////////////////////////////////////////////////////////////////
