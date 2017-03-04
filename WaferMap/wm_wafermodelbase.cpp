

// Includes
#include "wm_wafermodelbase.h"

// Qt includs
#include <QList>
#include <QPair>
#include <QRectF>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferModelBase
//
QList<QPair<int,int>> wm::CWaferModelBase::getDieCordinats() const
{
	QList<QPair<int, int>> aDieCordinats;
	// Fill die cordinats
	int const nDieXMaxCount = ceil( (m_fRadius * 2) / (m_szFDie.width() + m_fDieSpacing) );
	int const nDieYMaxCount = ceil( (m_fRadius * 2) / (m_szFDie.height() + m_fDieSpacing) );
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

wm::CDieIndexMapping wm::CWaferModelBase::getDieIndices() const
{
	return m_aDieIndices;
}

int wm::CWaferModelBase::getValidDieCount() const
{
	return m_aDieIndices.getCount();
}

double wm::CWaferModelBase::getRadius() const
{
	return m_fRadius;
}

QPointF wm::CWaferModelBase::getWaferCenter() const
{
	return QPointF(0, 0);
}

QSizeF wm::CWaferModelBase::getDieSize() const
{
	return m_szFDie;
}

QRectF wm::CWaferModelBase::getDieRect( int nDieX, int nDieY ) const
{
	QRectF rcFDie(0, 0, 0, 0);

	// Resolve die rect on the screen
	int nTmpDieX = nDieX;
	if (nTmpDieX < 0)
		nTmpDieX = qAbs( nTmpDieX + 1 );
	int nTmpDieY = nDieY;
	if (nTmpDieY < 0)
		nTmpDieY = qAbs( nTmpDieY + 1 );
	//
	double fDieSpacing = getDieSpacing();
	double fXSpacing = fDieSpacing / 2 + qMax( 0, nTmpDieX ) * fDieSpacing;
	double fYSpacing = fDieSpacing / 2 + qMax( 0, nTmpDieY ) * fDieSpacing;
	double fX = NAN;
	double fY = NAN;
	QSizeF szFDie = getDieSize();
	Q_ASSERT(szFDie.isValid());
	// Resolve x
	if (nDieX >= 0)
		fX = fXSpacing + nTmpDieX * szFDie.width();
	else
		fX = -(fXSpacing + (nTmpDieX + 1) * szFDie.width());
	// Resolve y
	if (nDieY >= 0)
		fY = fYSpacing + nTmpDieY * szFDie.height();
	else
		fY = -(fYSpacing + (nTmpDieY + 1) * szFDie.height());
	//
	rcFDie.setTopLeft( QPointF(fX, fY) );
	rcFDie.setSize( szFDie );
	return rcFDie;
}

double wm::CWaferModelBase::getDieSpacing() const
{
	return m_fDieSpacing;
}

wm::EDieStatus wm::CWaferModelBase::getDieSatus( int nDieX, int nDieY ) const
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
	if (!m_aDieIndices.contains( QPair<int, int>(nDieX, nDieY) ))
		return EDieStatus::InvalidDie;
	// Normal die
	return EDieStatus::NormalDie;
}
///////////////////////////////////////////////////////////////////////////////