

// Includes
#include "wm_global.h"
#include "wm_wafermodule.h"
//
#include "wm_iwafermodel.h"
#include "wm_singlewafer.h"
#include "wm_overlappedwafer.h"
#include "wm_wafersinglebin.h"
#include "wm_waferyield.h"
#include "wm_wafermfbin.h"
#include "wm_wafergroupaggregation.h"
#include "wm_waferview.h"
#include "wm_wafermap.h"
#include "vector.h"

// Qt includes
#include <QWidget>
#include <QString>

// STL includes
#include <exception>


///////////////////////////////////////////////////////////////////////////////
//
// struct CWaferModulData
//
struct CWaferModulData
{
	// Wafer data provider
	wm::IWaferModel*		m_pModel;
	wm::CWaferDrawer*		m_pDrawer;
	wm::CWaferView*			m_pwView;
	wm::CWaferMap*			m_pwWaferMap;

	CWaferModulData()
		: m_pModel( nullptr ),
		  m_pDrawer( nullptr ),
		  m_pwView( nullptr ),
		  m_pwWaferMap( nullptr )
	{}
	~CWaferModulData()
	{
		clear();
	}
	inline void clear()
	{
		delete m_pModel;
		delete m_pDrawer;
		delete m_pwView;
		delete m_pwWaferMap;

		m_pModel = nullptr;
		m_pDrawer = nullptr;
		m_pwView = nullptr;
		m_pwWaferMap = nullptr;
	}
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// struct CWaferModulData
//
CWaferModul::CWaferModul()
	: m_oConfig(),
	  m_pData( nullptr )
{
	m_pData = new CWaferModulData();
	Q_CHECK_PTR(m_pData);
}

CWaferModul::~CWaferModul()
{
	reset();
	delete m_pData;
}

void CWaferModul::setConfig( const CConfiguration& oConfig )
{
	m_oConfig = oConfig;
}

QWidget* CWaferModul::getView() const
{
	return qobject_cast<QWidget*>(m_pData->m_pwWaferMap);
}

void CWaferModul::run()
{
	reset();
	QString sError;

	// Check config
	if (m_oConfig.getName().isEmpty())
		sError = QString("Wafer Map: Coniguration name is empty!");
	if (m_oConfig.getType() != QString("wafermap"))
		sError = QString("Wafer Map: Invalid configuration type!");
	if (m_oConfig.getVersion() < 0)
		sError = QString("Wafer Map: Invalid configuration version!");

	QStringList const sWafers = m_oConfig.getParameter( wm::csWaferNames ).toStringList();
	if (sWafers.isEmpty())
		sError = QString("Wafer Map: Empty wafer input!");

	// Get data
	EBinType eBinType = EBinType(m_oConfig.getParameter( wm::csBinType ).toInt());
	IIntVector const* pBinData = new CIntVector(); //TODO
	if (eBinType == EBinType::HBin)
	{
		//TODO
		// get HBin data from data provider
	}
	else if (eBinType == EBinType::SBin)
	{
		//TODO
		// get SBin data from data provider
	}
	else
		sError = QString("Wafer Map: Invalid bin type!");

	// Create wafer model
	if (sError.isEmpty())
	{
		if (sWafers.count() == 1)
		{
			QString const sTmp = sWafers.first();
			QString sLotName("Unknown");
			if (sTmp.contains( "::" ))
				sLotName = sTmp.section( "::", 0 );
			QString sWaferName = sTmp.section( "::", 1 );
			//TODO
			wm::CDieIndexMapping oIndices;
			for (int i = 0; i < 800; ++i)
				oIndices.insert(QPair<int, int>(15 - qrand() % 30, 15 - qrand() % 30), qrand() % 800);

			// Create single wafer model
			if (sError.isEmpty())
			{
				wm::CSingleWafer* pModel = new wm::CSingleWafer;
				Q_CHECK_PTR(pModel);
				pModel->setBinData( pBinData );
				pModel->setIndices( oIndices );
				m_pData->m_pModel = pModel;
			}
		}
		else
		{
			// Create overlapped wafer model
			wm::COverlappedWafer* pOverlappedModel = new wm::COverlappedWafer;
			Q_CHECK_PTR(pOverlappedModel);
			for (int i = 0; i < sWafers.count(); ++i)
			{
				QString const sTmp = sWafers[i];
				QString sLotName("Unknown");
				if (sTmp.contains( "::" ))
					sLotName = sTmp.section( "::", 0 );
				QString sWaferName = sTmp.section( "::", 1 );
				//TODO
				wm::CDieIndexMapping oIndices;
				for (int i = 0; i < 800; ++i)
					oIndices.insert(QPair<int, int>(15 - qrand() % 30, 15 - qrand() % 30), qrand() % 800);
				if (sError.isEmpty())
				{
					wm::CSingleWafer* pModel = new wm::CSingleWafer;
					Q_CHECK_PTR(pModel);
					pModel->setBinData( pBinData );
					pModel->setIndices( oIndices );
					// Add model
					pOverlappedModel->addWaferModel( pModel );
				}
			}
			m_pData->m_pModel = pOverlappedModel;
		}
	}

	// Create drawer
	wm::CWaferDrawer* pDrawer = nullptr;
	wm::EWaferType eWaferType = wm::EWaferType(m_oConfig.getParameter( wm::csWaferType ).toInt());
	if (sError.isEmpty())
	{
		switch (eWaferType)
		{
		case wm::EWaferType::SingleBin:
			pDrawer = new wm::CWaferSingleBin(m_pData->m_pModel);
			Q_CHECK_PTR(pDrawer);
			break;
		case wm::EWaferType::Yield:
			pDrawer = new wm::CWaferYield(m_pData->m_pModel);
			Q_CHECK_PTR(pDrawer);
			break;
		case wm::EWaferType::MostFrequentBin:
			pDrawer = new wm::CWaferMFBin(m_pData->m_pModel);
			Q_CHECK_PTR(pDrawer);
			break;
		case wm::EWaferType::GroupAggregation:
			pDrawer = new wm::CWaferGroupAggregation(m_pData->m_pModel);
			Q_CHECK_PTR(pDrawer);
			break;
		default:
			sError = QString("Invalid wafer Type!");
			break;
		}
	}

	// Create Wafer map
	if (sError.isEmpty())
	{
		m_pData->m_pDrawer = pDrawer;
		// Create View
		m_pData->m_pwView = new wm::CWaferView;
		Q_CHECK_PTR(m_pData->m_pwView);
		m_pData->m_pwView->setWaferDrawer(m_pData->m_pDrawer);

		// Create Wafer Map
		m_pData->m_pwWaferMap = new wm::CWaferMap(m_pData->m_pwView);
		Q_CHECK_PTR(m_pData->m_pwWaferMap);
		m_pData->m_pwWaferMap->resize( 850, 800 );
		m_pData->m_pwWaferMap->setWaferType( eWaferType );
		m_pData->m_pwWaferMap->setBinType( eBinType );
	}
	else
	{
		reset();
		throw std::exception(sError.toStdString().data());
	}
}

void CWaferModul::reset()
{
	m_pData->clear();
}
///////////////////////////////////////////////////////////////////////////////