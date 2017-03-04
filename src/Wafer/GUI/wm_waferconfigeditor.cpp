


// Includes
#include "wm_global.h"
#include "wm_waferconfigeditor.h"

// Qt includes
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QList>
#include <QIcon>


CWaferConfigEditor::CWaferConfigEditor( QWidget* parent )
	: QWidget( parent ),
	  m_pLstWafer( nullptr ),
	  m_pBtnHBin( nullptr ),
	  m_pBtnSBin( nullptr ),
	  m_pBtnSingleBin( nullptr ),
	  m_pBtnYield( nullptr ),
	  m_pBtnMostFrequentBin( nullptr ),
	  m_pBtnGroupAggregation( nullptr )
{
	setupUi();
}

CWaferConfigEditor::~CWaferConfigEditor()
{

}

void CWaferConfigEditor::addWafer( QString const& aLotName, QString const& sNameWafer )
{
	Q_ASSERT(m_pLstWafer);
	if (aLotName.isEmpty() || sNameWafer.isEmpty())
		return;

	// Lot item
	QTreeWidgetItem* pLot = nullptr;
	QList<QTreeWidgetItem*> pListItem = m_pLstWafer->findItems( aLotName, Qt::MatchFlag::MatchFixedString );
	if (pListItem.isEmpty())
	{
		pLot = new QTreeWidgetItem(m_pLstWafer);
		Q_CHECK_PTR(pLot);
		pLot->setText( 0, aLotName );
		m_pLstWafer->addTopLevelItem( pLot );
		m_pLstWafer->expandItem( pLot );
	}
	else
		pLot = pListItem.first();
	// Wafer item
	QTreeWidgetItem* pWafer = new QTreeWidgetItem(pLot, QStringList(sNameWafer));
	Q_CHECK_PTR(pWafer);
	pWafer->setFlags( Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable );
	pWafer->setCheckState( 0, Qt::Unchecked );
	pLot->addChild( pWafer );
}

CConfiguration CWaferConfigEditor::getConfig() const
{
	CConfiguration oConfig;
	oConfig.setName("Wafer Map");
	oConfig.setType("wafermap");
	oConfig.setVersion(1);
	// Set wafer names
	QStringList sWaferNames = getSelectedWafers();
	oConfig.setParameter(wm::csWaferNames, QVariant(sWaferNames));
	// Set wafer type
	int nWaferType = getWaferType();
	oConfig.setParameter(wm::csWaferType, QVariant(nWaferType));
	// Set bin type
	int nBinType = int(getBinType());
	oConfig.setParameter(wm::csBinType, QVariant(nBinType));
	return oConfig;
}

QStringList CWaferConfigEditor::getSelectedWafers() const
{

	Q_ASSERT(m_pLstWafer);
	QStringList aSelection;
	for (int i = 0; i < m_pLstWafer->topLevelItemCount(); ++i)
	{
		QTreeWidgetItem* pLot = m_pLstWafer->topLevelItem( i );
		Q_ASSERT(pLot);
		QString sLot = pLot->text( 0 );
		for (int j = 0; j < pLot->childCount(); ++j)
		{
			QTreeWidgetItem* pWafer = pLot->child( j );
			Q_ASSERT(pWafer);
			QString sWafer = pWafer->text( 0 );
			aSelection.append( QString("%1::%2").arg( sLot ).arg( sWafer ) );
		}
	}
	return aSelection;
}

EBinType CWaferConfigEditor::getBinType() const
{
	Q_ASSERT(m_pBtnHBin);
	Q_ASSERT(m_pBtnSBin);

	if (m_pBtnHBin->isChecked())
		return EBinType::HBin;
	else if (m_pBtnSBin->isChecked())
		return EBinType::SBin;

	Q_ASSERT(false);
	return EBinType::HBin;
}

int CWaferConfigEditor::getWaferType() const
{
	Q_ASSERT(m_pBtnSingleBin);
	Q_ASSERT(m_pBtnYield);
	Q_ASSERT(m_pBtnMostFrequentBin);
	Q_ASSERT(m_pBtnGroupAggregation);

	if (m_pBtnSingleBin->isChecked())
		return int(wm::EWaferType::SingleBin);
	else if (m_pBtnYield->isChecked())
		return int(wm::EWaferType::Yield);
	else if (m_pBtnMostFrequentBin->isChecked())
		return int(wm::EWaferType::MostFrequentBin);
	else if (m_pBtnGroupAggregation->isChecked())
		return int(wm::EWaferType::GroupAggregation);
	return int(wm::EWaferType::Invalid);
}

void CWaferConfigEditor::setupUi()
{
	setObjectName( "WaferConfigEditor" );
	setWindowTitle( "Wafer Configuration" );
	setWindowIcon( QIcon(":/wm/Resources/editwafer.png") );
	setContentsMargins( 0, 0, 0, 0 );

	// Parameters group box
	QGroupBox* pGroupBox = new QGroupBox(this);
	Q_CHECK_PTR(pGroupBox);
	pGroupBox->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	pGroupBox->setCheckable( false );
	pGroupBox->setTitle( "Parameters" );
	QFont oFont = pGroupBox->font();
	oFont.setPointSize( 13 );
	pGroupBox->setFont( oFont );
	oFont.setPointSize( 9 );

	// Wafers
	m_pLstWafer = new QTreeWidget(this);
	Q_CHECK_PTR(m_pLstWafer);
	m_pLstWafer->setHeaderLabel( "Wafers" );
	m_pLstWafer->setFont( oFont );

	// Left layout
	QVBoxLayout* pLeftLayout = new QVBoxLayout;
	Q_CHECK_PTR(pLeftLayout);
	pLeftLayout->addWidget( m_pLstWafer );

	// Bin type group box
	QGroupBox* pBinTypeBox = new QGroupBox(this);
	Q_CHECK_PTR(pBinTypeBox);
	pBinTypeBox->setCheckable( false );
	pBinTypeBox->setTitle( "Bin Type" );
	pBinTypeBox->setFont( oFont );
	m_pBtnHBin = new QRadioButton("HBin", this);
	Q_CHECK_PTR(m_pBtnHBin);
	m_pBtnHBin->setChecked( true );
	m_pBtnSBin = new QRadioButton("SBin", this);
	Q_CHECK_PTR(m_pBtnSBin);
	QVBoxLayout* pLayout = new QVBoxLayout;
	pLayout->addWidget( m_pBtnHBin, 0, Qt::AlignLeft | Qt::AlignTop );
	pLayout->addWidget( m_pBtnSBin, 1, Qt::AlignLeft | Qt::AlignTop );
	pBinTypeBox->setLayout( pLayout );

	// Wafer type group box
	QGroupBox* pWaferTypeBox = new QGroupBox(this);
	Q_CHECK_PTR(pWaferTypeBox);
	pWaferTypeBox->setCheckable( false );
	pWaferTypeBox->setTitle( "Wafer type" );
	pWaferTypeBox->setFont( oFont );

	pLayout = new QVBoxLayout;
	Q_CHECK_PTR(pLayout);
	//
	m_pBtnSingleBin = new QRadioButton("Single Bin", this);
	Q_CHECK_PTR(m_pBtnSingleBin);
	m_pBtnSingleBin->setChecked( true );
	pLayout->addWidget( m_pBtnSingleBin, 0, Qt::AlignLeft | Qt::AlignTop );
	//
	m_pBtnYield = new QRadioButton("Yield", this);
	Q_CHECK_PTR(m_pBtnYield);
	pLayout->addWidget( m_pBtnYield, 0, Qt::AlignLeft | Qt::AlignTop );
	//
	m_pBtnMostFrequentBin = new QRadioButton("Most frecuent Bin", this);
	Q_CHECK_PTR(m_pBtnMostFrequentBin);
	pLayout->addWidget( m_pBtnMostFrequentBin, 0, Qt::AlignLeft | Qt::AlignTop );
	//
	m_pBtnGroupAggregation = new QRadioButton("Group aggregation", this);
	Q_CHECK_PTR(m_pBtnGroupAggregation);
	pLayout->addWidget( m_pBtnGroupAggregation, 1, Qt::AlignLeft | Qt::AlignTop );
	//
	pWaferTypeBox->setLayout( pLayout );

	// Right layout
	QVBoxLayout* pRightLayout = new QVBoxLayout;
	Q_CHECK_PTR(pRightLayout);
	pRightLayout->addWidget( pWaferTypeBox );
	pRightLayout->addWidget( pBinTypeBox );

	// Main layout
	QHBoxLayout* pMainLayout = new QHBoxLayout;
	Q_CHECK_PTR(pMainLayout);
	pMainLayout->addLayout( pLeftLayout, 1 );
	pMainLayout->addLayout( pRightLayout, 2 );
	pGroupBox->setLayout( pMainLayout );

	// Layout for group box
	QGridLayout* pMLayout = new QGridLayout;
	Q_CHECK_PTR(pMLayout);
	pMLayout->addWidget( pGroupBox );
	setLayout( pMLayout );

	resize( sizeHint() );
}
