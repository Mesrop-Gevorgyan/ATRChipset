

// Includes
#include "wm_wafermfbin.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferMFBin
//
wm::CWaferMFBin::CWaferMFBin( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferMFBin::~CWaferMFBin()
{

}

void wm::CWaferMFBin::drawValidDie(QPainter* pPainter, int nDieX, int nDieY) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pModel);

	QRectF rcFDie = getDieRect( nDieX, nDieY );
	if (!rcFDie.isValid())
		return;

	int nBin;
	int nPercent;
	EDieStatus eStatus = m_pModel->getMostFrequentBin( nDieX, nDieY, nBin, nPercent );
	if (eStatus != EDieStatus::NormalDie)
	{
		Q_ASSERT(false);
		drawInvalidDie( pPainter, rcFDie );
		return;
	}

	QBrush oBrush(Qt::SolidPattern);
	oBrush.setColor( getBinColor( nBin ) );
	rcFDie.adjust( 1, 1, -1, -1 );
	pPainter->fillRect( rcFDie, oBrush );
	
	QString sLabel = QString("%1\n%2%").arg( nBin ).arg( nPercent );
	QFont oFont = pPainter->font();
	int nPointSize = qMin( rcFDie.height() * 0.45, rcFDie.width() * 0.35 ) * 0.8;
	oFont.setPointSize( nPointSize );
	pPainter->setFont( oFont );
	pPainter->drawText( rcFDie, Qt::AlignCenter, sLabel );
}

QColor wm::CWaferMFBin::getBinColor( int nBin ) const
{
	QColor oColor;
	if (nBin < 1)
		return oColor;

	if (nBin == 1)
		oColor = QColor(Qt::green);
	else
	{
		int hue = QColor(Qt::green).hue() + 20 * nBin;
		oColor.setHsl( hue, 255, 127 );
	}

	return oColor;
}
///////////////////////////////////////////////////////////////////////////////