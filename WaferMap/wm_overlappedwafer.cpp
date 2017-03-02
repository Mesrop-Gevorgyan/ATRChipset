

// Includes
#include "wm_overlappedwafer.h"

// Qt includs
#include <qglobal.h>
#include <QPair>
#include <QSizeF>
#include <QRectF>
#include <QStringList>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CArea
//
QString wm::COverlappedWafer::getName() const
{
	return QString();
}

QString wm::COverlappedWafer::getLotName() const
{
	return QString();
}

QList<QPair<int,int>> wm::COverlappedWafer::getDieCordinats() const
{
	QList<QPair<int, int>> lstDieCordinats;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.begin().value();
		Q_ASSERT(pWafer);
		lstDieCordinats = pWafer->getDieCordinats();
	}
	return lstDieCordinats;
}

int wm::COverlappedWafer::getValidDieCount() const
{
	return m_aDieCordinats.count();
}

double wm::COverlappedWafer::getRadius() const
{
	double fRadius = NAN;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.begin().value();
		Q_ASSERT(pWafer);
		fRadius = pWafer->getRadius();
	}
	return fRadius;
}

QSizeF wm::COverlappedWafer::getDieSize() const
{
	QSizeF szFDie;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.begin().value();
		Q_ASSERT(pWafer);
		szFDie = pWafer->getDieSize();
	}
	return szFDie;
}

double wm::COverlappedWafer::getDieSpacing() const
{
	double fDieSpacing = NAN;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.begin().value();
		Q_ASSERT(pWafer);
		fDieSpacing = pWafer->getDieSpacing();
	}
	return fDieSpacing;
}

wm::EDieStatus wm::COverlappedWafer::getDieSatus( int nDieX, int nDieY ) const
{
	return EDieStatus::NoDie;
}

wm::EDieStatus wm::COverlappedWafer::getHBin( int nDieX, int nDieY, int& nHBin ) const
{
	return EDieStatus::NoDie;
}

wm::EDieStatus wm::COverlappedWafer::getSBin( int nDieX, int nDieY, int& nSBin ) const
{
	return EDieStatus::NoDie;
}

QStringList	wm::COverlappedWafer::getWaferNames( QString const& sLotName ) const
{
	QStringList aNames;
	for (auto it = m_aWafers.begin(); it != m_aWafers.end(); ++it)
	{
		IWaferModel const* pWafer = it.value();
		Q_ASSERT(pWafer);
		aNames.append( pWafer->getName() );
	}
	return aNames;
}

QStringList	wm::COverlappedWafer::getLotNames() const
{
	QStringList aLotNames;
	for (auto it = m_aWafers.begin(); it != m_aWafers.end(); ++it)
	{
		IWaferModel const* pWafer = it.value();
		Q_ASSERT(pWafer);
		aLotNames.append( pWafer->getLotName() );
	}
	return aLotNames;
}

bool wm::COverlappedWafer::addWafer( IWaferModel const* pNewWafer )
{
	Q_ASSERT(pNewWafer);
	bool bIsCompatible = true;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.begin().value();
		Q_ASSERT(pWafer);
		bIsCompatible = (!qFuzzyCompare( pNewWafer->getRadius(), pWafer->getRadius()) ||
						 pNewWafer->getDieSize() != pWafer->getDieSize() ||
						 !qFuzzyCompare( pNewWafer->getDieSpacing(), pWafer->getDieSpacing() ));
	}
	if (bIsCompatible)
	{
		m_aWafers.insert( makeKey( pNewWafer->getLotName(), pNewWafer->getName() ) , pNewWafer );
		reset();
	}
	return bIsCompatible;
}

void wm::COverlappedWafer::reset()
{
	m_aDieCordinats.clear();
	QHash<QPair<int, int>, int> aCordinats;
	for (auto it = m_aWafers.begin(); it != m_aWafers.end(); ++it)
	{
		IWaferModel const* pWafer = it.value();
		Q_ASSERT(pWafer);
		QList<QPair<int, int>> aTmpCordinats = pWafer->getDieCordinats();
		for (int i = 0; i < aTmpCordinats.size(); ++i)
			aCordinats.insert( aTmpCordinats[i], -1 );
	}
	//
	m_aDieCordinats.reserve( aCordinats.size() );
	for (auto it = aCordinats.begin(); it != aCordinats.end(); ++it)
		m_aDieCordinats.append( it.key() );
}
///////////////////////////////////////////////////////////////////////////////