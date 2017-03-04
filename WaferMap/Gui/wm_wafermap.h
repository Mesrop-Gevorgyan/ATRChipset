


#ifndef WS_WAFERMAP_H
#define WS_WAFERMAP_H


// Includes
#include "wm_waferview.h"

// Qt includs
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QLabel>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferMap
//
class CWaferMap : public QWidget
{
	Q_DISABLE_COPY(CWaferMap);

	typedef QWidget Base;

public:
	// Init constructor
	inline CWaferMap( CWaferView* pWaferView, QWidget* pParent = nullptr );
	// Destructor
	inline ~CWaferMap();

public:
	//
	//! Own interface
	//
	// Bin type
	void setBinType( EBinType eBinType );
	// Wafer type
	void setWaferType( EWaferType eWaferType );

protected:
	//
	//! Implementations
	//
	void setupUi();

private:
	//
	//! Content
	//
	// Wafer view
	CWaferView*			m_pwWaferView;
	//
	QLabel*				m_lblWaferType;
	QLabel*				m_lblBinType;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
inline CWaferMap::CWaferMap( CWaferView* pWaferView, QWidget* pParent )
	: QWidget( pParent ),
	  m_pwWaferView( nullptr ),
	  m_lblWaferType( nullptr ),
	  m_lblBinType( nullptr )
{
	Q_ASSERT(pWaferView);
	m_pwWaferView = pWaferView;
	setupUi();
}

inline CWaferMap::~CWaferMap()
{
	
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERMAP_H