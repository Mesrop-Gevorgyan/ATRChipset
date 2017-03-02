

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
	// Do layout
	QRect rcViewport = viewport()->rect();;
	m_pWaferDrawer->doLayout( rcViewport );
	// Draw wafer map
	QPainter oPainter(viewport());
	m_pWaferDrawer->draw( &oPainter );
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
			m_pRubberBand->setGeometry( QRect() );
			m_pRubberBand->hide();
			m_rcBand = QRect();
			pEvent->accept();
			update();
		}
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