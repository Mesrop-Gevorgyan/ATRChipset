

// Includes
#include "wm_wafermap.h"

// Qt includs
#include <QRect>
#include <QIcon>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferMap
//
void wm::CWaferMap::setupUi()
{
	setObjectName( "QWidget::WaferMap" );
	setWindowTitle( "Wafer Map" );
	setWindowIcon( QIcon(":/wm/Resources/wafer.png") );
	setContentsMargins( 0, 0, 0, 0 );

	QHBoxLayout* pMainLayout = new QHBoxLayout;
	Q_CHECK_PTR(pMainLayout);

	// Set wafer view
	Q_ASSERT(m_pwWaferView);
	pMainLayout->addWidget( m_pwWaferView );

	//
	setLayout( pMainLayout );
}


///////////////////////////////////////////////////////////////////////////////