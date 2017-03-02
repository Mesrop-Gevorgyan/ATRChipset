

// Includes
#include "wm_wafermodule.h"
//
#include "wm_iwafermodel.h"
#include "wm_singlewafer.h"
#include "wm_overlappedwafer.h"
#include "wm_waferdrawer.h"
#include "wm_waferview.h"
#include "wm_wafermap.h"

// Qt includes
#include <QWidget>


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
	void clear()
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
wm::CWaferModul::CWaferModul()
	: m_oConfig(),
	  m_pData( nullptr )
{
	m_pData.reset( new CWaferModulData() );
	Q_CHECK_PTR(m_pData);
}

wm::CWaferModul::~CWaferModul()
{
	reset();
}

void wm::CWaferModul::setConfig( const CConfiguration& oConfig )
{
	m_oConfig = oConfig;
}

QWidget* wm::CWaferModul::getView() const
{
	return qobject_cast<QWidget*>(m_pData->m_pwWaferMap);
}

void wm::CWaferModul::run()
{
	reset();

	// Create Model
	m_pData->m_pModel = new wm::CSingleWafer;
	Q_CHECK_PTR(m_pData->m_pModel);

	// Create drawer
	m_pData->m_pDrawer = new wm::CWaferDrawer(m_pData->m_pModel);
	Q_CHECK_PTR(m_pData->m_pDrawer);

	// Create View
	m_pData->m_pwView = new wm::CWaferView;
	Q_CHECK_PTR(m_pData->m_pwView);
	m_pData->m_pwView->setWaferDrawer( m_pData->m_pDrawer );

	// Create Wafer Map
	m_pData->m_pwWaferMap = new wm::CWaferMap(m_pData->m_pwView);
	Q_CHECK_PTR(m_pData->m_pwWaferMap);
}

void wm::CWaferModul::reset()
{
	m_pData->clear();
}
///////////////////////////////////////////////////////////////////////////////