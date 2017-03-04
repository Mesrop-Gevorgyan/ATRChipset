

// Includes
#include "wm_overlappedwafer.h"

// Qt includes
#include <QHash>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of COverlappedWafer
//
wm::EDieStatus wm::COverlappedWafer::getBin( int nDieX, int nDieY, int& nBin ) const
{
	EDieStatus eDieStatus = EDieStatus::NoDie;
	for (int i = 0; i < m_aWafers.count(); ++i)
	{
		IWaferModel const* pModel = m_aWafers[i];
		Q_ASSERT(pModel);
		EDieStatus eStatus = pModel->getBin( nDieX, nDieY, nBin );
		if (eStatus == EDieStatus::NormalDie)
			eDieStatus = eStatus;
	}
	return eDieStatus;
}

wm::EDieStatus wm::COverlappedWafer::getYield( int nDieX, int nDieY, int& nYield ) const
{
	EDieStatus eDieStatus = EDieStatus::NoDie;
	int nYieldSum = 0;
	int nNormalDieCount = 0;
	for (int i = 0; i < m_aWafers.count(); ++i)
	{
		IWaferModel const* pModel = m_aWafers[i];
		Q_ASSERT(pModel);
		int nTmpYield;
		EDieStatus eStatus = pModel->getYield( nDieX, nDieY, nTmpYield );
		if (eStatus == EDieStatus::NormalDie)
		{
			++nNormalDieCount;
			nYieldSum += nTmpYield;
			eDieStatus = eStatus;
		}
	}
	if (eDieStatus == EDieStatus::NormalDie)
		nYield = int(nYieldSum / nNormalDieCount);
	return eDieStatus;
}

wm::EDieStatus wm::COverlappedWafer::getMostFrequentBin( int nDieX, int nDieY, int& nBin, int& nPercent ) const
{
	EDieStatus eDieStatus = EDieStatus::NoDie;
	QHash<int, int> hasMFBin;
	int nMFBin = 0;
	int nNormalDieCount = 0;
	for (int i = 0; i < m_aWafers.count(); ++i)
	{
		IWaferModel const* pModel = m_aWafers[i];
		Q_ASSERT(pModel);
		int nBin;
		EDieStatus eStatus = pModel->getBin( nDieX, nDieY, nBin );
		if (eStatus == EDieStatus::NormalDie)
		{
			++nNormalDieCount;
			auto it = hasMFBin.find( nBin );
			if (it != hasMFBin.end())
				++it.value();
			else
				it = hasMFBin.insert( nBin, 1 );
			if (!hasMFBin.contains( nMFBin ) || (!hasMFBin.contains( nMFBin ) && it.value() >= hasMFBin[nMFBin]))
				nMFBin = it.key();
			eDieStatus = eStatus;
		}
	}
	if (eDieStatus == EDieStatus::NormalDie)
	{
		nBin = nMFBin;
		nPercent = int(hasMFBin[nMFBin] / nNormalDieCount);
	}
	return eDieStatus;
}

wm::EDieStatus wm::COverlappedWafer::getGroupAggregation( int nDieX, int nDieY, int& nBad, int& nGood ) const
{
	EDieStatus eDieStatus = EDieStatus::NoDie;
	QHash<int, int> hasMFBin;
	int nBadSum = 0;
	int nGoodSum = 0;
	for (int i = 0; i < m_aWafers.count(); ++i)
	{
		IWaferModel const* pModel = m_aWafers[i];
		Q_ASSERT(pModel);
		int nTmpBad;
		int nTmpGood;
		EDieStatus eStatus = pModel->getGroupAggregation( nDieX, nDieY, nTmpBad, nTmpGood );
		if (eStatus == EDieStatus::NormalDie)
		{
			nBadSum += nTmpBad;
			nGoodSum += nTmpGood;
			eDieStatus = eStatus;
		}
	}
	if (eDieStatus == EDieStatus::NormalDie)
	{
		nBad = nBadSum;
		nGood = nGoodSum;
	}
	return eDieStatus;
}

bool wm::COverlappedWafer::addWaferModel( IWaferModel* pNewWafer )
{
	Q_ASSERT(pNewWafer);
	bool bIsCompatible = true;
	if (!m_aWafers.isEmpty())
	{
		IWaferModel const* pWafer = m_aWafers.last();
		Q_ASSERT(pWafer);
		bIsCompatible = (!qFuzzyCompare( pNewWafer->getRadius(), pWafer->getRadius()) ||
						 pNewWafer->getDieSize() != pWafer->getDieSize() ||
						 !qFuzzyCompare( pNewWafer->getDieSpacing(), pWafer->getDieSpacing() ));
	}
	if (bIsCompatible)
	{
		m_aWafers.append( pNewWafer );
		reset();
	}
	return bIsCompatible;
}

void wm::COverlappedWafer::reset()
{
	CDieIndexMapping oDieIndices;
	for (int i = 0; i < m_aWafers.count(); ++i)
	{
		IWaferModel const* pWafer = m_aWafers[i];
		Q_ASSERT(pWafer);
		CDieIndexMapping const oTmp = pWafer->getDieIndices();
		QList<QPair<int, int>> const aValidCordinats = oTmp.getDieCordinats();
		for (int i = 0; i < aValidCordinats.size(); ++i)
			oDieIndices.insert( aValidCordinats[i], -1 );
	}
	setIndices( oDieIndices );
}
///////////////////////////////////////////////////////////////////////////////