

// Includes
#include "wm_wafermap.h"

// Qt includs
#include <QHBoxLayout>
#include <QVBoxLayout>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferMap
//
void wm::CWaferMap::clear()
{
	m_pwWaferView = nullptr;
}

void wm::CWaferMap::setupUi()
{
	setObjectName( "QWidget::WaferMap" );
	setWindowTitle( "Wafer Map" );

	QHBoxLayout* pMainLayout = new QHBoxLayout;
	Q_CHECK_PTR(pMainLayout);

	// Set wafer view
	Q_ASSERT(m_pwWaferView);
	pMainLayout->addWidget( m_pwWaferView );

	//
	setLayout( pMainLayout );
}
///////////////////////////////////////////////////////////////////////////////