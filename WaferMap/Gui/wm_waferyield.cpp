

// Includes
#include "wm_waferyield.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferYield
//
wm::CWaferYield::CWaferYield( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferYield::~CWaferYield()
{

}

void wm::CWaferYield::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pModel);

	QRectF rcFDie = getDieRect( nDieX, nDieY );
	if (!rcFDie.isValid())
		return;

	int nYield;
	EDieStatus eStatus = m_pModel->getYield( nDieX, nDieY, nYield );
	if (eStatus != EDieStatus::NormalDie)
	{
		Q_ASSERT(false);
		drawInvalidDie( pPainter, rcFDie );
		return;
	}

	QBrush oBrush(Qt::SolidPattern);
	QColor oColor;
	if (nYield > 67)
		oColor = Qt::green;
	else if (nYield > 34)
		oColor = Qt::yellow;
	else
		oColor = Qt::red;
	oBrush.setColor( oColor );
	rcFDie.adjust( 1, 1, -1, -1 );
	pPainter->fillRect( rcFDie, oBrush );
	
	QString sLabel = QString("%1%").arg( nYield );
	QFont oFont = pPainter->font();
	int nPointSize = qMin( rcFDie.height(), rcFDie.width() * 0.35 ) * 0.8;
	oFont.setPointSize( nPointSize );
	pPainter->setFont( oFont );
	pPainter->drawText( rcFDie, Qt::AlignCenter, sLabel );
}
///////////////////////////////////////////////////////////////////////////////