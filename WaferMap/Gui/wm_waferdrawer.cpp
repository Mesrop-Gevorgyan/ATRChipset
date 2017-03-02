

// Includes
#include "wm_waferdrawer.h"
#include "wm_dieindexmapping.h"

// Qt includs
#include <QPointF>
#include <QLineF>
#include <QSizeF>
#include <QRectF>
#include <QList>
#include <QPair>
#include <QPen>
#include <QPainter>
#include <QPainterPath>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CArea
//
wm::CWaferDrawer::CWaferDrawer( IWaferModel const* pModel )
	: m_pModel( pModel ),
	  m_eDimplePos( EDimplePosition::Bottom ),
	  m_oColor( QColor( Qt::darkGray ) ),
	  m_pArea( nullptr )
{
	Q_ASSERT(pModel);
	m_pArea.reset(new CArea);
	Q_ASSERT(m_pArea);
	adjust();
}

wm::CWaferDrawer::~CWaferDrawer()
{

}

QRect wm::CWaferDrawer::doLayout( QRect const& rc )
{
	Q_ASSERT(m_pArea);
	m_pArea->setScreen( rc );
	return rc;
}

void wm::CWaferDrawer::draw( QPainter* pPainter ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);
	
	QRectF const rcFScreen = m_pArea->getScreen();
	if (!rcFScreen.isValid())
		return;

	// Setup painter
	pPainter->save();
	QPen oPen;
	oPen.setWidth( 1 );
	oPen.setColor( getColor() );
	QPen oSelPen;
	oSelPen.setWidth( 3 );
	oSelPen.setColor( QColor(qRgba(255, 100, 0, 0)) );
	pPainter->setPen( oPen );
	pPainter->setRenderHint( QPainter::Antialiasing );
	// Set cliping
	pPainter->setClipPath( getClipping(), Qt::ReplaceClip );

	// Draw wafer contur
	drawWaferContur( pPainter );

	// Draw dies
	QList<QPair<int, int>> const aAllDieCordinats = m_pModel->getDieCordinats();
	for (int i = 0; i < aAllDieCordinats.size(); ++i)
	{
		int nDieX = aAllDieCordinats[i].first;
		int nDieY = aAllDieCordinats[i].second;
		QRectF rcFDie = getDieRect( nDieX, nDieY );
		if (canDraw( rcFDie ))
		{
			// Draw contur
			if (isSelected( nDieX, nDieY ))
				pPainter->setPen( oSelPen );
			pPainter->drawRect( rcFDie );
			pPainter->setPen( oPen );
			if (m_pModel->getDieSatus( nDieX, nDieY ) == EDieStatus::NormalDie)
			{
				// Draw content of valid die
				drawValidDie( pPainter, nDieX, nDieY );
			}
			else
			{
				// Draw content of invalid die
				drawInvalidDie( pPainter, nDieX, nDieY );
			}
		}
	}

	// Restore painter
	pPainter->restore();
}

bool wm::CWaferDrawer::zoom( QRectF rcZoom )
{
	if (qAbs(rcZoom.width()) < 30 && qAbs(rcZoom.height()) < 30)
		return false;
	Q_ASSERT(m_pArea);
	double fXMin;
	double fXMax;
	double fYMin;
	double fYMax;
	if (rcZoom.bottom() > rcZoom.top())
	{ // Zoom in
		fXMin = m_pArea->reverse( rcZoom.left(), getXRulerDirection() );
		fXMax = m_pArea->reverse( rcZoom.right(), getXRulerDirection() );
		fYMin = m_pArea->reverse( rcZoom.top(), getYRulerDirection() );
		fYMax = m_pArea->reverse( rcZoom.bottom(), getYRulerDirection() );
	}
	else
	{ // Zoom out
		m_pArea->getXRange( fXMin, fXMax );
		m_pArea->getYRange( fYMin, fYMax );
		QRectF rcCurr = m_pArea->getScreen();
		rcZoom = rcZoom.normalized();
		double fXFactor = qMax( 1.0, rcCurr.width() / rcZoom.width() );
		double fYFactor = qMax( 1.0, rcCurr.height() / rcZoom.height() );
		fXMin -= fXFactor * m_pArea->reverse( qAbs( rcCurr.left() - rcZoom.left() ), Qt::Horizontal );
		fXMax += fXFactor * m_pArea->reverse( qAbs( rcCurr.right() - rcZoom.right() ), Qt::Horizontal );
		fYMin -= fYFactor * m_pArea->reverse( qAbs( rcCurr.top() - rcZoom.top() ), Qt::Vertical );
		fYMax += fYFactor * m_pArea->reverse( qAbs( rcCurr.bottom() - rcZoom.bottom() ), Qt::Vertical );
	}
	m_pArea->setXRange( fXMin, fXMax );
	m_pArea->setYRange( fYMin, fYMax );
	return true;
}

bool wm::CWaferDrawer::scrollLR( int iShift )
{
	Q_ASSERT(m_pArea);
	if (iShift > -1 && iShift < 1)
		return false;
	double fXMin;
	double fXMax;
	m_pArea->getXRange( fXMin, fXMax );
	double fShift = m_pArea->reverse( iShift, Qt::Horizontal );
	fXMin += fShift;
	fXMax += fShift;
	m_pArea->setXRange( fXMin, fXMax );
	return true;
}

bool wm::CWaferDrawer::scrollTB( int iShift )
{
	Q_ASSERT(m_pArea);
	if (iShift > -1 && iShift < 1)
		return false;
	double fYMin;
	double fYMax;
	m_pArea->getYRange( fYMin, fYMax );
	double fShift = m_pArea->reverse( iShift, Qt::Vertical );
	fYMin += fShift;
	fYMax += fShift;
	m_pArea->setYRange( fYMin, fYMax );
	return true;
}

void wm::CWaferDrawer::selectDie( QPointF const& ptF )
{
	if (ptF.isNull())
		return;
	QList<QPair<int, int>> const aAllDieCordinats = m_pModel->getDieCordinats();
	for (int i = 0; i < aAllDieCordinats.size(); ++i)
	{
		int nDieX = aAllDieCordinats[i].first;
		int nDieY = aAllDieCordinats[i].second;
		QRectF rcFDie = getDieRect( nDieX, nDieY );
		if (rcFDie.contains( ptF ))
		{
			if (isSelected( nDieX, nDieY ))
				removeSelection( nDieX, nDieY );
			else
				selectDie( nDieX, nDieY );
		}
	}
}

void wm::CWaferDrawer::selectDies( QRectF const& rcSel )
{

	if (rcSel.isNull())
		return;
	QList<QPair<int, int>> const aAllDieCordinats = m_pModel->getDieCordinats();
	for (int i = 0; i < aAllDieCordinats.size(); ++i)
	{
		int nDieX = aAllDieCordinats[i].first;
		int nDieY = aAllDieCordinats[i].second;
		QRectF rcFDie = getDieRect( nDieX, nDieY );
		if (rcSel.contains( rcFDie ))
		{
			if (rcSel.bottom() > rcSel.top())
				selectDie( nDieX, nDieY );
			else
				removeSelection( nDieX, nDieY );
		}
	}
}

void wm::CWaferDrawer::clearSelection()
{
	m_aSelectedDies.clear();
}

void wm::CWaferDrawer::adjust()
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);
	double fWaferRadius = m_pModel->getRadius();
	fWaferRadius += fWaferRadius * 0.05;
	m_pArea->setXRange( -fWaferRadius, fWaferRadius );
	m_pArea->setYRange( -fWaferRadius, fWaferRadius );
}

QRect wm::CWaferDrawer::getPreferedArea() const
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);
	double fWaferRadius = m_pModel->getRadius();
	fWaferRadius += fWaferRadius * 0.05;
	QRectF rcFArea;
	rcFArea.setLeft( -fWaferRadius );
	rcFArea.setTop( -fWaferRadius );
	rcFArea.setRight( fWaferRadius );
	rcFArea.setBottom( fWaferRadius );
	return m_pArea->translate( rcFArea, getXRulerDirection(), getYRulerDirection() ).toRect();
}

QPointF wm::CWaferDrawer::getWaferCenter() const
{
	Q_ASSERT(m_pArea);
	return m_pArea->translate( QPointF(0, 0), getXRulerDirection(), getYRulerDirection() );
}

QRectF wm::CWaferDrawer::getWaferGeometry() const
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);

	QPointF ptFWaferCenter = getWaferCenter();
	double const fWaferRadius = m_pModel->getRadius();
	QSizeF szFWafer(fWaferRadius * 2, fWaferRadius * 2);
	szFWafer = m_pArea->translate( szFWafer );
	QRectF rcFWafer;
	rcFWafer.setTopLeft( ptFWaferCenter );
	rcFWafer.setSize( szFWafer );
	rcFWafer.adjust( -szFWafer.width() / 2, -szFWafer.height() / 2,
					 -szFWafer.width() / 2, -szFWafer.height() / 2 );
	return rcFWafer;
}

void wm::CWaferDrawer::getDimpleInfo( QRectF& rcFDimple, double& nWaferStartAngel ) const
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);

	nWaferStartAngel = 271;
	int const nSpanAngle = 358;
	QPointF ptFWaferCenter = getWaferCenter();
	QRectF rcFWafer = getWaferGeometry();
	EDimplePosition eDimplePos = getDimplePosition();
	switch (eDimplePos)
	{
	case wm::EDimplePosition::Bottom:
		nWaferStartAngel = 271;
		rcFDimple.setLeft( ptFWaferCenter.x() );
		rcFDimple.setTop( rcFWafer.bottom() );
		break;
	case wm::EDimplePosition::Top:
		nWaferStartAngel = 91;
		rcFDimple.setLeft( ptFWaferCenter.x() );
		rcFDimple.setTop( rcFWafer.top() );
		break;
	case wm::EDimplePosition::Left:
		nWaferStartAngel = 181;
		rcFDimple.setLeft( rcFWafer.left() );
		rcFDimple.setTop( ptFWaferCenter.y() );
		break;
	case wm::EDimplePosition::Right:
		nWaferStartAngel = 1;
		rcFDimple.setLeft( rcFWafer.right() );
		rcFDimple.setTop( ptFWaferCenter.y() );
		break;
	}

	double const fDimpleRadius = m_pModel->getRadius() / 57.00445;
	QSizeF szFDimple(fDimpleRadius * 2, fDimpleRadius * 2);
	szFDimple = m_pArea->translate( szFDimple );
	rcFDimple.setSize( szFDimple );
	rcFDimple.adjust( -szFDimple.width() / 2, -szFDimple.height() / 2,
					  -szFDimple.width() / 2, -szFDimple.height() / 2 );
}

QRectF wm::CWaferDrawer::getDieRect( int nDieX, int nDieY ) const
{
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);
	QRectF rcFDie(0, 0, 0, 0);

	// Resolve die rect on the screen
	int nTmpDieX = nDieX;
	if (nTmpDieX < 0)
		nTmpDieX = qAbs( nTmpDieX + 1 );
	int nTmpDieY = nDieY;
	if (nTmpDieY < 0)
		nTmpDieY = qAbs( nTmpDieY + 1 );
	//
	double fDieSpacing = m_pModel->getDieSpacing();
	double fXSpacing = fDieSpacing / 2 + qMax( 0, nTmpDieX ) * fDieSpacing;
	double fYSpacing = fDieSpacing / 2 + qMax( 0, nTmpDieY ) * fDieSpacing;
	double fX = NAN;
	double fY = NAN;
	QSizeF szFDie = m_pModel->getDieSize();
	Q_ASSERT(szFDie.isValid());
	// Resolve x
	if (nDieX >= 0)
		fX = fXSpacing + nTmpDieX * szFDie.width();
	else
		fX = -(fXSpacing + (nTmpDieX + 1) * szFDie.width());
	// Resolve y
	if (nDieY >= 0)
		fY = fYSpacing + nTmpDieY * szFDie.height();
	else
		fY = -(fYSpacing + (nTmpDieY + 1) * szFDie.height());
	//
	rcFDie.setTopLeft( QPointF(fX, fY) );
	rcFDie.setSize( szFDie );
	// Translate rect to screen
	return m_pArea->translate( rcFDie, getXRulerDirection(), getYRulerDirection() );
}

void wm::CWaferDrawer::drawWaferContur( QPainter* pPainter ) const
{
	Q_ASSERT(pPainter);
	Q_ASSERT(m_pArea);
	Q_ASSERT(m_pModel);

	// Make wafer contur
	double nWStartAngle = 271;
	double fDStartAngle = 0.5;
	int const nSpanAngle = 358;
	QRectF rcFDimple;
	getDimpleInfo( rcFDimple, nWStartAngle );
	fDStartAngle = qAbs( 360 - (nWStartAngle + 88.5) );
	// Draw wafer bound
	QRectF rcFWafer = getWaferGeometry();
	pPainter->drawArc( rcFWafer, 16 * nWStartAngle, 16 * nSpanAngle );
	// Draw dimple
	pPainter->drawArc( rcFDimple, qRound( 16 * fDStartAngle ), 16 * 179 );
}

void wm::CWaferDrawer::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	// Noting to do, subclasses should override
}

void wm::CWaferDrawer::drawInvalidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);

	QRectF const rcFDie = getDieRect( nDieX, nDieY );
	if (!rcFDie.isValid())
		return;
	// Draw cross
	double fXFactor = rcFDie.width() * 0.2;
	double fYFactor = rcFDie.height() * 0.2;
	QLineF fLine1 = QLineF(rcFDie.left() + fXFactor, rcFDie.top() + fYFactor,
						   rcFDie.right() - fXFactor, rcFDie.bottom() - fYFactor);
	QLineF fLine2 = QLineF(rcFDie.left() + fXFactor, rcFDie.bottom() - fYFactor,
						   rcFDie.right() - fXFactor, rcFDie.top() + fYFactor);
	pPainter->drawLine( fLine1 );
	pPainter->drawLine( fLine2 );
}

QPainterPath wm::CWaferDrawer::getClipping(  ) const
{
	// Cliping
	QPainterPath oPainterPath;
	QRectF rcFWafer = getWaferGeometry();
	rcFWafer.adjust( -1, -1, 1, 1 );
	oPainterPath.addEllipse( rcFWafer );
	QRectF rcFDimple;
	double fTmp;
	//rcFDimple.adjust( 0, 0, 0, rcFDimple.height() / 2 );
	getDimpleInfo( rcFDimple, fTmp );
	oPainterPath.addEllipse( rcFDimple );
	return oPainterPath;
}

bool wm::CWaferDrawer::canDraw( QRectF const& rcFDie ) const
{
	Q_ASSERT(m_pArea);

	bool bCanDraw = false;
	if (!rcFDie.isValid())
		return bCanDraw;
	QRectF const rcFArea = m_pArea->getScreen();
	if (rcFArea.intersects( rcFDie ))
	{
		QPainterPath oPainterPath = getClipping();
		bCanDraw = oPainterPath.contains( rcFDie );
	}
	return bCanDraw;
}

void wm::CWaferDrawer::selectDie( int nDieX, int nDieY )
{
	m_aSelectedDies.insert( QPair<int, int>(nDieX, nDieY) );
}

void wm::CWaferDrawer::removeSelection( int nDieX, int nDieY )
{
	m_aSelectedDies.remove( QPair<int, int>(nDieX, nDieY) );
}

bool wm::CWaferDrawer::isSelected( int nDieX, int nDieY ) const
{
	return m_aSelectedDies.contains( QPair<int, int>(nDieX, nDieY) );
}
///////////////////////////////////////////////////////////////////////////////