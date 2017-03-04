

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

	bool bOk = true;
	QString sError;

	//TODO

	// Create Model
	wm::CSingleWafer* pModel = new wm::CSingleWafer;
	Q_CHECK_PTR(pModel);

	pModel->setHBin(new CIntVector());

	wm::CDieIndexMapping oIndices;
	for (int i = 0; i < 800; ++i)
		oIndices.insert( QPair<int, int>(15 - qrand() % 30, 15 - qrand() % 30), qrand() % 800 );
	pModel->setIndices( oIndices );
	m_pData->m_pModel = pModel;

	// Create drawer
	wm::CWaferDrawer* pDrawer = nullptr;
	wm::EWaferType eType =wm:: EWaferType::SingleBin;
	switch (eType)
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
		bOk = false;
		sError = QString("Invalid wafer Type!");
		break;
	}
	if (bOk)
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
	}
	else
		reset();
}

void CWaferModul::reset()
{
	m_pData->clear();
}
///////////////////////////////////////////////////////////////////////////////