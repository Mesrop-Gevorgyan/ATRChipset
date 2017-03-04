

// Includes
#include "wm_waferyield.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferYield
//
wm::CWaferYield::CWaferYield( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferYield::~CWaferYield()
{

}

void wm::CWaferYield::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	

}
///////////////////////////////////////////////////////////////////////////////