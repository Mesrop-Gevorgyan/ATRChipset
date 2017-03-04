

// Includes
#include "wm_singlewafer.h"


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CSingleWafer
//
wm::EDieStatus wm::CSingleWafer::getBin( int nDieX, int nDieY, int& nBin ) const
{
	Q_ASSERT(m_cpBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Get Bin
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	nBin = m_cpBin->GetAt( nIndex );
	return eDieStatus;
}

wm::EDieStatus wm::CSingleWafer::getYield( int nDieX, int nDieY, int& nYield ) const
{
	Q_ASSERT(m_cpBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Calc yield
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	int nBin = m_cpBin->GetAt( nIndex );
	if (nBin == 1)
		nYield = 100;
	else
		nYield = 0;
	return eDieStatus;
}

wm::EDieStatus wm::CSingleWafer::getMostFrequentBin( int nDieX, int nDieY, int& nBin, int& nPercent ) const
{
	Q_ASSERT(m_cpBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Calc yield
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	nBin = m_cpBin->GetAt( nIndex );
	nPercent = 100;
	return eDieStatus;
}

wm::EDieStatus wm::CSingleWafer::getGroupAggregation( int nDieX, int nDieY, int& nBad, int& nGood ) const
{
	Q_ASSERT(m_cpBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Calc yield
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	int nBin = m_cpBin->GetAt( nIndex );
	if (nBin == 1)
	{
		nBad = 0;
		nGood = 1;
	}
	else
	{
		nBad = 1;
		nGood = 0;
	}
	return eDieStatus;
}
///////////////////////////////////////////////////////////////////////////////