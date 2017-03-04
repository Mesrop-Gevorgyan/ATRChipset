

// Includes
#include "wm_wafersinglebin.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferSingleBin
//
wm::CWaferSingleBin::CWaferSingleBin( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferSingleBin::~CWaferSingleBin()
{

}

void wm::CWaferSingleBin::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pModel);

	QRectF rcFDie = getDieRect( nDieX, nDieY );
	if (!rcFDie.isValid())
		return;

	int nBin;
	EDieStatus eStatus = m_pModel->getBin( nDieX, nDieY, nBin );
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
	
	QString sLabel = QString::number( nBin );
	QFont oFont = pPainter->font();
	int nPointSize = qMin( rcFDie.height(), rcFDie.width() * 0.8 ) * 0.8;
	oFont.setPointSize( nPointSize );
	pPainter->setFont( oFont );
	pPainter->drawText( rcFDie, Qt::AlignCenter, sLabel );
}

QColor wm::CWaferSingleBin::getBinColor( int nBin ) const
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