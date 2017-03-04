

// Includes
#include "wm_wafermap.h"

// Qt includs
#include <QRect>
#include <QIcon>
#include <QPainter>
#include <QPaintEvent>
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

	QVBoxLayout* pMainLayout = new QVBoxLayout;
	Q_CHECK_PTR(pMainLayout);

	// Set wafer view
	Q_ASSERT(m_pwWaferView);
	pMainLayout->addWidget( m_pwWaferView );

	// Wafer info
	m_lblWaferType = new QLabel(this);
	Q_CHECK_PTR(m_lblWaferType);
	pMainLayout->addWidget( m_lblWaferType );

	m_lblBinType = new QLabel(this);
	Q_CHECK_PTR(m_lblBinType);
	pMainLayout->addWidget( m_lblBinType );

	setLayout( pMainLayout );
}

void wm::CWaferMap::setBinType( EBinType eBinType )
{
	Q_ASSERT(m_lblBinType);
	QString sLabel("Bin Type: ");
	switch (eBinType)
	{
	case EBinType::HBin:
		sLabel += QString("HBin");
		break;
	case EBinType::SBin:
		sLabel += QString("SBin");
		break;
	default:
		sLabel += QString("Invalid");
		break;
	}
	m_lblBinType->setText( sLabel );
}

void wm::CWaferMap::setWaferType( EWaferType eWaferType )
{
	Q_ASSERT(m_lblWaferType);
	QString sLabel("Wafer Type: ");
	switch (eWaferType)
	{
	case wm::EWaferType::SingleBin:
		sLabel += QString("Single Bin");
		break;
	case wm::EWaferType::Yield:
		sLabel += QString("Yield");
		break;
	case wm::EWaferType::MostFrequentBin:
		sLabel += QString("Most Frequent Bin");
		break;
	case wm::EWaferType::GroupAggregation:
		sLabel += QString("Group Aggregation");
		break;
	default:
		sLabel += QString("Invalid");
		break;
	}
	m_lblWaferType->setText( sLabel );
}
///////////////////////////////////////////////////////////////////////////////