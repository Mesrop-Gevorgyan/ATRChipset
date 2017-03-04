

// Includes
#include "wm_wafergroupaggregation.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferGroupAggregation
//
wm::CWaferGroupAggregation::CWaferGroupAggregation( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferGroupAggregation::~CWaferGroupAggregation()
{

}

void wm::CWaferGroupAggregation::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pModel);

	QRectF rcFDie = getDieRect( nDieX, nDieY );
	if (!rcFDie.isValid())
		return;

	int nBad;
	int nGood;
	EDieStatus eStatus = m_pModel->getGroupAggregation( nDieX, nDieY, nBad, nGood );
	if (eStatus != EDieStatus::NormalDie)
	{
		Q_ASSERT(false);
		drawInvalidDie( pPainter, rcFDie );
		return;
	}

	rcFDie.adjust( 1, 1, -1, -1 );
	int nGoodRectHeight = 0;
	if (nBad == 0)
		nGoodRectHeight = rcFDie.height() * 0.7;
	else
		nGoodRectHeight = rcFDie.height() * qBound( 0.3, double(nGood / (nBad + nGood)), 0.7 );

	// Draw good rect
	QBrush oBrush(Qt::SolidPattern);
	oBrush.setColor( Qt::green );
	QRect rc = rcFDie.toRect();
	rc.setHeight( nGoodRectHeight );
	pPainter->fillRect( rc, oBrush );

	QFont oFont = pPainter->font();
	int nPointSize = qMin( rc.height() * 0.45, rc.width() * 0.35 ) * 0.8;
	oFont.setPointSize( nPointSize );
	pPainter->setFont( oFont );
	QString sLabel = QString("Good: %1").arg( nGood );
	pPainter->drawText( rc, Qt::AlignCenter, sLabel );

	// Draw bad rect
	oBrush.setColor( Qt::red );
	rc = rcFDie.toRect();
	rc.adjust( 0, nGoodRectHeight, 0, 0 );
	pPainter->fillRect( rc, oBrush );

	oFont = pPainter->font();
	nPointSize = qMin( rc.height() * 0.45, rc.width() * 0.35 ) * 0.8;
	oFont.setPointSize( nPointSize );
	pPainter->setFont( oFont );
	sLabel = QString("Bad: %1").arg( nBad );
	pPainter->drawText( rc, Qt::AlignCenter, sLabel );
}
///////////////////////////////////////////////////////////////////////////////