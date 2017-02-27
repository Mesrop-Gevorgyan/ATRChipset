

// Includes
#include "wm_wafermap.h"

// Qt includs
#include <QtGui\QPainter>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferArea
//
wm::CWaferMap::CWaferMap( IWaferModel const* pModel )
	: m_pModel( pModel ),
	  m_pArea( QScopedPointer<CWaferArea>(new CWaferArea) )
{
	Q_ASSERT(pModel);
	Q_ASSERT(m_pArea);
}

wm::CWaferMap::~CWaferMap()
{

}

QRect wm::CWaferMap::doLayout( QRect const& rc )
{
	return QRect();
}

void wm::CWaferMap::draw( QPainter* pPainter ) const
{

}

void wm::CWaferMap::drawDie( QPainter* pPainter, QRect const& rcDie, int nDieX, int nDieY ) const
{

}
///////////////////////////////////////////////////////////////////////////////