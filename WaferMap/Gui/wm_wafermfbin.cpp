

// Includes
#include "wm_wafermfbin.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferMFBin
//
wm::CWaferMFBin::CWaferMFBin( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferMFBin::~CWaferMFBin()
{

}

void wm::CWaferMFBin::drawValidDie(QPainter* pPainter, int nDieX, int nDieY) const
{
	Q_ASSERT(pPainter);
	

}
///////////////////////////////////////////////////////////////////////////////