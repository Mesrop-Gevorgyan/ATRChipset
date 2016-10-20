

#include "waferconfigeditor.h"
#include <QtGui\QGroupBox>
#include <QtGui\QGridLayout>
#include <QtGui\QHBoxLayout>
#include <QtGui\QVBoxLayout>
#include <QtGui\QLabel>



CWaferConfigEditor::CWaferConfigEditor(QWidget* parent)
	: QWidget(parent)
{
	setObjectName("WaferConfigEditor");
	setWindowTitle("Wafer configuration");
	setContentsMargins(0, 0, 0, 0);

	// Parameters group box
	QGroupBox* pGroupBox = new QGroupBox(this);
	pGroupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	pGroupBox->setCheckable(false);
	pGroupBox->setTitle("Parameters");
	QFont oFont = pGroupBox->font();
	oFont.setPointSize(16);
	pGroupBox->setFont(oFont);

	// Wafer label
	QLabel* pLabel = new QLabel("Wafers:", this);
	oFont.setPointSize(12);
	pLabel->setFont(oFont);

	// Wafers
	m_pWafers = new QListWidget(this);
	m_pWafers->setFont(oFont);

	// Light layout
	QVBoxLayout* pLightLayout = new QVBoxLayout;
	pLightLayout->addWidget(pLabel, 0, Qt::AlignLeft | Qt::AlignBottom);
	pLightLayout->addWidget(m_pWafers);

	// Bin type group box
	QGroupBox* pBinTypeBox = new QGroupBox(this);
	pBinTypeBox->setCheckable(false);
	pBinTypeBox->setTitle("Bin Type");
	pBinTypeBox->setFont(oFont);
	m_pHBin = new QRadioButton("HBin", this);
	m_pHBin->setChecked(true);
	m_pSBin = new QRadioButton("SBin", this);
	QVBoxLayout* pLayout = new QVBoxLayout;
	pLayout->addWidget(m_pHBin, 0, Qt::AlignLeft | Qt::AlignTop);
	pLayout->addWidget(m_pSBin, 1, Qt::AlignLeft | Qt::AlignTop);
	pBinTypeBox->setLayout(pLayout);

	// Wafer mode group box
	QGroupBox* pModeBox = new QGroupBox(this);
	pModeBox->setCheckable(false);
	pModeBox->setTitle("Mode");
	pModeBox->setFont(oFont);
	m_pMF = new QRadioButton("MF", this);
	m_pMF->setChecked(true);
	m_pYield = new QRadioButton("Yield", this);
	pLayout = new QVBoxLayout;
	pLayout->addWidget(m_pMF, 0, Qt::AlignLeft | Qt::AlignTop);
	pLayout->addWidget(m_pYield, 1, Qt::AlignLeft | Qt::AlignTop);
	pModeBox->setLayout(pLayout);

	// Right layout
	QVBoxLayout* pRightLayout = new QVBoxLayout;
	pRightLayout->addWidget(pBinTypeBox);
	pRightLayout->addWidget(pModeBox);

	// Main layout
	QHBoxLayout* pMainLayout = new QHBoxLayout;
	pMainLayout->addLayout(pLightLayout, 1);
	pMainLayout->addLayout(pRightLayout, 1);
	pGroupBox->setLayout(pMainLayout);

	// Layout for group box
	QGridLayout* pMLayout = new QGridLayout;
	pMLayout->addWidget(pGroupBox);
	setLayout(pMLayout);
	resize(sizeHint());
}

CWaferConfigEditor::~CWaferConfigEditor()
{

}

void CWaferConfigEditor::setupUi()
{

}