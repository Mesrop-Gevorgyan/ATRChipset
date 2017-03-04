

// Includes
#include "wm_wafergroupaggregation.h"

// Qt includs
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QColor>
#include <QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferGroupAggregation
//
wm::CWaferGroupAggregation::CWaferGroupAggregation( IWaferModel const* pModel )
	: CWaferDrawer( pModel )
{
	
}

wm::CWaferGroupAggregation::~CWaferGroupAggregation()
{

}

void wm::CWaferGroupAggregation::drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const
{
	Q_ASSERT(pPainter);
	

}
///////////////////////////////////////////////////////////////////////////////