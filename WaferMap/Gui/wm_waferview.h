


#ifndef WS_WAFERVIEW_H
#define WS_WAFERVIEW_H


// Includes
#include "wm_waferdrawer.h"
#include "wm_ruler.h"

// Qt includs
#include <QObject>
#include <QAbstractScrollArea>
#include <QRubberBand>

// Qt forward declarations
class QRect;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferView
//
class CWaferView : public QAbstractScrollArea
{
	Q_OBJECT

	Q_DISABLE_COPY(CWaferView);

	typedef QAbstractScrollArea Base;

public:
	// Default constructor
	inline CWaferView( QWidget* pParent = nullptr );
	// Destructor
	inline ~CWaferView();

public:
	//
	//! Own Interface
	//
	// Set wafer drawer
	inline void setWaferDrawer( CWaferDrawer* pWaferDrawer );
	inline CWaferDrawer* getWaferDrawer() const;

protected:
	//
	//! Implementations
	//
	void setupUi();
	// Handle paint event
	void paintEvent( QPaintEvent* pEvent ) override;
	// Handle mouse press event
	void mousePressEvent( QMouseEvent* pEvent ) override;
	// Handle mouse press event
	void mouseMoveEvent( QMouseEvent* pEvent ) override;
	// Handle mouse release event
	void mouseReleaseEvent( QMouseEvent* pEvent ) override;
	// Handle mouse double click event
	void mouseDoubleClickEvent( QMouseEvent* pEvent ) override;
	// Reset wafer view
	virtual void resetZooming();

protected slots:
	//
	//! Slots
	//
	void onHSliderPosChanged( int nNewPos );
	void onVSliderPosChanged( int nNewPos );

private:
	//
	//! Content
	//
	// Wafer map
	CWaferDrawer*				m_pWaferDrawer;
	// Horizontal ruler
	QScopedPointer<CRuler>		m_pHRuler;
	// Vertical ruler
	QScopedPointer<CRuler>		m_pVRuler;
	// Rubber band
	QRubberBand*				m_pRubberBand;
	// Rabber band rect
	QRect						m_rcBand;
	// H and V Scroll current positions
	int							m_nHScrollPos;
	int							m_nVScrollPos;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
inline CWaferView::CWaferView( QWidget* pParent )
	: QAbstractScrollArea( pParent ),
	  m_pWaferDrawer( nullptr ),
	  m_pHRuler( nullptr ),
	  m_pVRuler( nullptr ),
	  m_pRubberBand( nullptr ),
	  m_rcBand( QRect() ),
	  m_nHScrollPos( 0 ),
	  m_nVScrollPos( 0 )
{
	setupUi();
}

inline CWaferView::~CWaferView()
{

}

inline void CWaferView::setWaferDrawer( CWaferDrawer* pWaferDrawer )
{
	Q_ASSERT(pWaferDrawer);
	Q_ASSERT(m_pHRuler);
	Q_ASSERT(m_pVRuler);

	m_pWaferDrawer = pWaferDrawer;
	IWaferModel const* pModel = pWaferDrawer->getWaferModel();
	Q_ASSERT(pModel);
	m_pHRuler->setWaferModel( pModel );
	m_pVRuler->setWaferModel( pModel );
	resetZooming();
}

inline CWaferDrawer * CWaferView::getWaferDrawer() const
{
	return m_pWaferDrawer;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERVIEW_H