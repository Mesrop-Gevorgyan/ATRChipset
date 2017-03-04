

// Includes
#include "wm_waferview.h"

// Qt includs
#include <QWidget>
#include <QScrollBar>
#include <QPaintEvent>
#include <QPainter>
#include <QRubberBand>
#include <QRect>
#include <QSize>
#include <QPalette>
#include <QColor>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QApplication>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferView
//
void wm::CWaferView::setupUi()
{
	setObjectName( "CWaferView" );
	setWindowTitle( "Wafer View" );
	setWindowFlags( Qt::Dialog );
	setContentsMargins( 0, 0, 0, 0 );

	// Create viewport
	QWidget* pViewport = new QWidget;
	Q_CHECK_PTR(pViewport);
	pViewport->setContentsMargins( 0, 0, 0, 0 );
	pViewport->setWindowFlags( Qt::Widget );
	setViewport( pViewport );

	// Setup scrolling
	setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
	setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
	QObject::connect( horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onHSliderPosChanged(int)) );
	QObject::connect( verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onVSliderPosChanged(int)) );

	// Setup Horizontal ruler
	m_pHRuler.reset( new CRuler );
	m_pHRuler->setAligment( ERulerAligment::Top );
	// Setup vertical ruler
	m_pVRuler.reset( new CRuler );
	m_pVRuler->setAligment( ERulerAligment::Left );

	// Setup rubber band
	m_pRubberBand = new QRubberBand(QRubberBand::Rectangle, this);
	m_pRubberBand->setObjectName( "QRubberBand" );
	Q_CHECK_PTR(m_pRubberBand);
	resetZooming();
}

void wm::CWaferView::paintEvent( QPaintEvent * pEvent )
{
	Base::paintEvent( pEvent );
	Q_ASSERT(m_pWaferDrawer);
	Q_ASSERT(m_pHRuler);
	Q_ASSERT(m_pVRuler);

	QPainter oPainter(viewport());
	QRect const rcViewport = viewport()->rect();
	QRect const rcWafer = rcViewport.adjusted( m_pVRuler->getPreferedSize(), m_pHRuler->getPreferedSize(), 0, 0 );
	// Draw wafer
	m_pWaferDrawer->doLayout( rcWafer );
	m_pWaferDrawer->draw( &oPainter );

	QPalette oPalette = palette();
	QColor clrfill = oPalette.color( QPalette::Background );
	QRect rcHRuler = rcViewport;
	rcHRuler.setHeight( m_pHRuler->getPreferedSize() );
	oPainter.fillRect( rcHRuler, clrfill );
	rcHRuler.adjust( m_pVRuler->getPreferedSize(), 0, 0, 0 );
	//
	QRect rcVRuler = rcViewport;
	rcVRuler.setWidth( m_pVRuler->getPreferedSize() );
	oPainter.fillRect( rcVRuler, clrfill );
	rcVRuler.adjust( 0, m_pHRuler->getPreferedSize(), 0, 0 );

	CArea const* pArea = m_pWaferDrawer->getArea();
	Q_ASSERT(pArea);
	double fMin;
	double fMax;
	pArea->getXRange( fMin, fMax );
	m_pHRuler->setRange( fMin, fMax );
	//
	pArea->getYRange( fMin, fMax );
	m_pVRuler->setRange( fMin, fMax );

	// Draw horizontal ruler
	oPainter.setClipRect( rcHRuler );
	m_pHRuler->doLayout( rcHRuler );
	m_pHRuler->draw( &oPainter );
	// Draw vertical ruler
	oPainter.setClipRect( rcVRuler );
	m_pVRuler->doLayout( rcVRuler );
	m_pVRuler->draw( &oPainter );
}

void wm::CWaferView::mousePressEvent( QMouseEvent * pEvent )
{
	Q_ASSERT(pEvent);
	Q_ASSERT(m_pWaferDrawer);
	Q_ASSERT(m_pRubberBand);

	if (pEvent->button() == Qt::LeftButton)
	{
		m_rcBand.setTopLeft( pEvent->pos() );
		m_rcBand.setSize( QSize() );
		m_pRubberBand->setGeometry( QRect(pEvent->pos(), QSize()) );
		m_pRubberBand->show();
		pEvent->accept();
	}
	else
		Base::mousePressEvent( pEvent );
}

void wm::CWaferView::mouseMoveEvent( QMouseEvent * pEvent )
{
	Q_ASSERT(pEvent);
	Q_ASSERT(m_pRubberBand);

	if (pEvent->buttons() == Qt::LeftButton)
	{
		m_rcBand.setBottomRight( pEvent->pos() );
		m_pRubberBand->setGeometry( QRect(m_rcBand.topLeft(), m_rcBand.bottomRight()).normalized() );
		pEvent->accept();
	}
	else
		Base::mouseMoveEvent( pEvent );
}

void wm::CWaferView::mouseReleaseEvent( QMouseEvent * pEvent )
{
	Q_ASSERT(pEvent);
	Q_ASSERT(m_pWaferDrawer);

	if (pEvent->button() == Qt::LeftButton)
	{
		if (QApplication::keyboardModifiers() == Qt::ControlModifier)
		{
			if (m_rcBand.topLeft() == pEvent->pos())
				m_pWaferDrawer->selectDie( pEvent->pos() );
			else
			{
				m_pWaferDrawer->selectDies( m_rcBand );
				m_pRubberBand->setGeometry( QRect() );
				m_pRubberBand->hide();
			}
			pEvent->accept();
			update();
		}
		else if(m_pWaferDrawer->zoom( m_rcBand ))
		{
			QRect rcPrefered = m_pWaferDrawer->getPreferedArea();
			verticalScrollBar()->setPageStep( rect().height() );
			horizontalScrollBar()->setPageStep( rect().width() );
			verticalScrollBar()->setRange( rcPrefered.top(), rcPrefered.bottom() );
			horizontalScrollBar()->setRange( rcPrefered.left(), rcPrefered.right() );
			pEvent->accept();
			update();
		}
		m_pRubberBand->setGeometry( QRect() );
		m_pRubberBand->hide();
		m_rcBand = QRect();
	}
	else
		Base::mouseReleaseEvent( pEvent );
}

void wm::CWaferView::mouseDoubleClickEvent( QMouseEvent * pEvent )
{
	Q_ASSERT(pEvent);
	Q_ASSERT(m_pWaferDrawer);

	if (pEvent->button() == Qt::LeftButton)
	{
		if (QApplication::keyboardModifiers() == Qt::ControlModifier)
		{
			// Clear selection
			m_pWaferDrawer->clearSelection();
		}
		else
			resetZooming();
		pEvent->accept();
		update();
	}
	else
		Base::mouseDoubleClickEvent( pEvent );
}

void wm::CWaferView::resetZooming()
{
	if (m_pWaferDrawer)
		m_pWaferDrawer->adjust();
	m_nHScrollPos = 0;
	m_nVScrollPos = 0;
	verticalScrollBar()->setPageStep( 0 );
	horizontalScrollBar()->setPageStep( 0 );
	verticalScrollBar()->setRange( 0, 0 );
	horizontalScrollBar()->setRange( 0, 0 );
}

void wm::CWaferView::onHSliderPosChanged( int nNewPos )
{
	Q_ASSERT(m_pWaferDrawer);
	m_pWaferDrawer->scrollLR( nNewPos - m_nHScrollPos );
	m_nHScrollPos = nNewPos;
}

void wm::CWaferView::onVSliderPosChanged( int nNewPos )
{
	Q_ASSERT(m_pWaferDrawer);
	m_pWaferDrawer->scrollTB( nNewPos - m_nVScrollPos );
	m_nVScrollPos = nNewPos;
}
///////////////////////////////////////////////////////////////////////////////