

// Includes
#include "wm_singlewafer.h"

// Qt includs
#include <QList>
#include <QPair>
#include <QRectF>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CSingleWafer
//
QString wm::CSingleWafer::getName() const
{
	return m_sName;
}

QString wm::CSingleWafer::getLotName() const
{
	return m_sLotName;
}

QList<QPair<int,int>> wm::CSingleWafer::getDieCordinats() const
{
	QList<QPair<int, int>> aDieCordinats;
	// Fill die cordinats
	int const nDieXMaxCount = ceil( (m_fRadius * 2) / (m_szFDie.width() + m_fDieSpacing) ) + 1;
	int const nDieYMaxCount = ceil( (m_fRadius * 2) / (m_szFDie.height() + m_fDieSpacing) ) + 1;
	Q_ASSERT(nDieXMaxCount > 0);
	Q_ASSERT(nDieYMaxCount > 0);
	aDieCordinats.reserve( nDieXMaxCount * nDieYMaxCount );
	int nDieX = nDieXMaxCount / 2 - nDieXMaxCount;
	int nDieY = nDieYMaxCount / 2 - nDieYMaxCount;
	for (int i = 0; i < nDieYMaxCount; ++i)
	{
		for (int j = 0; j < nDieXMaxCount; ++j)
		{
			aDieCordinats.append( QPair<int, int>(nDieX, nDieY) );
			++nDieX;
		}
		++nDieY;
		nDieX = nDieXMaxCount / 2 - nDieXMaxCount;
	}
	return aDieCordinats;
}

int wm::CSingleWafer::getValidDieCount() const
{
	return m_aDieIndices.getCount();
}

double wm::CSingleWafer::getRadius() const
{
	return m_fRadius;
}

QSizeF wm::CSingleWafer::getDieSize() const
{
	return m_szFDie;
}

double wm::CSingleWafer::getDieSpacing() const
{
	return m_fDieSpacing;
}

wm::EDieStatus wm::CSingleWafer::getDieSatus( int nDieX, int nDieY ) const
{
	int nTmpDieX = nDieX;
	if (nTmpDieX < 0)
		nTmpDieX = qAbs( nTmpDieX + 1 );
	int nTmpDieY = nDieY;
	if (nTmpDieY < 0)
		nTmpDieY = qAbs( nTmpDieY + 1 );
	//
	double fXSpacing = m_fDieSpacing / 2 + qMax( 0, nTmpDieX ) * m_fDieSpacing;
	double fX = fXSpacing + (nTmpDieX + 1) * m_szFDie.width();
	//
	double fYSpacing = m_fDieSpacing / 2 + qMax( 0, nTmpDieY ) * m_fDieSpacing;
	double fY = fYSpacing + (nTmpDieY + 1) * m_szFDie.height();
	// Check is die outside
	if (fX * fX + fY * fY >= m_fRadius * m_fRadius)
		return EDieStatus::NoDie;	
	// Check is die defined
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	if (nIndex < 0)
		return EDieStatus::InvalidDie;
	// Normal die
	return EDieStatus::NormalDie;
}

wm::EDieStatus wm::CSingleWafer::getHBin( int nDieX, int nDieY, int& nHBin ) const
{
	Q_ASSERT(m_cpHBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Get HBin
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	nHBin = m_cpHBin->GetAt( nIndex );
	return eDieStatus;
}

wm::EDieStatus wm::CSingleWafer::getSBin( int nDieX, int nDieY, int& nSBin ) const
{
	Q_ASSERT(m_cpSBin);
	EDieStatus eDieStatus = getDieSatus( nDieX, nDieY );
	if (eDieStatus != EDieStatus::NormalDie)
		return eDieStatus;

	// Get SBin
	int nIndex = m_aDieIndices.at( nDieX, nDieY );
	nSBin = m_cpSBin->GetAt( nIndex );
	return eDieStatus;
}
///////////////////////////////////////////////////////////////////////////////