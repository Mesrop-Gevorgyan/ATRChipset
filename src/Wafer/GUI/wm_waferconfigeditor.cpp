

#include "waferconfigeditor.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>



CWaferConfigEditor::CWaferConfigEditor(QWidget* parent)
	: QWidget(parent),
	  m_pLstWafer(nullptr),
	  m_pBtnHBin(nullptr),
	  m_pBtnSBin(nullptr),
	  m_pBtnMF(nullptr),
	  m_pBtnYield(nullptr)
{
	setObjectName("WaferConfigEditor");
	setWindowTitle("Wafer configuration");
	setContentsMargins(0, 0, 0, 0);
	setupUi();
	resize(sizeHint());
}

CWaferConfigEditor::~CWaferConfigEditor()
{

}

void CWaferConfigEditor::setWafers(QStringList const & aWafer)
{
	Q_ASSERT(m_pLstWafer);
	m_pLstWafer->addItems(aWafer);
}

QStringList CWaferConfigEditor::getSelectedWafers() const
{
	Q_ASSERT(m_pLstWafer);
	QModelIndexList lstIndex = m_pLstWafer->selectionModel()->selectedIndexes();
	QStringList aSelection;
	aSelection.reserve(lstIndex.size());
	for (int i = 0; i < lstIndex.size(); ++i)
		aSelection.append(lstIndex[i].data().toString());
	return aSelection;
}

BinType CWaferConfigEditor::getBinType() const
{
	Q_ASSERT(m_pBtnHBin);
	Q_ASSERT(m_pBtnSBin);
	if (m_pBtnHBin->isChecked())
		return BinType::HBin;
	else if (m_pBtnSBin->isChecked())
		return BinType::SBin;
	Q_ASSERT(false);
}

WaferMode CWaferConfigEditor::getMode() const
{
	Q_ASSERT(m_pBtnMF);
	Q_ASSERT(m_pBtnYield);
	if (m_pBtnMF->isChecked())
		return WaferMode::MF;
	else if (m_pBtnYield->isChecked())
		return WaferMode::Yield;
	Q_ASSERT(false);
}

void CWaferConfigEditor::setupUi()
{
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
	m_pLstWafer = new QListWidget(this);
	m_pLstWafer->setFont(oFont);

	// Light layout
	QVBoxLayout* pLightLayout = new QVBoxLayout;
	pLightLayout->addWidget(pLabel, 0, Qt::AlignLeft | Qt::AlignBottom);
	pLightLayout->addWidget(m_pLstWafer);

	// Bin type group box
	QGroupBox* pBinTypeBox = new QGroupBox(this);
	pBinTypeBox->setCheckable(false);
	pBinTypeBox->setTitle("Bin Type");
	pBinTypeBox->setFont(oFont);
	m_pBtnHBin = new QRadioButton("HBin", this);
	m_pBtnHBin->setChecked(true);
	m_pBtnSBin = new QRadioButton("SBin", this);
	QVBoxLayout* pLayout = new QVBoxLayout;
	pLayout->addWidget(m_pBtnHBin, 0, Qt::AlignLeft | Qt::AlignTop);
	pLayout->addWidget(m_pBtnSBin, 1, Qt::AlignLeft | Qt::AlignTop);
	pBinTypeBox->setLayout(pLayout);

	// Wafer mode group box
	QGroupBox* pModeBox = new QGroupBox(this);
	pModeBox->setCheckable(false);
	pModeBox->setTitle("Mode");
	pModeBox->setFont(oFont);
	m_pBtnMF = new QRadioButton("MF", this);
	m_pBtnMF->setChecked(true);
	m_pBtnYield = new QRadioButton("Yield", this);
	pLayout = new QVBoxLayout;
	pLayout->addWidget(m_pBtnMF, 0, Qt::AlignLeft | Qt::AlignTop);
	pLayout->addWidget(m_pBtnYield, 1, Qt::AlignLeft | Qt::AlignTop);
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
}
