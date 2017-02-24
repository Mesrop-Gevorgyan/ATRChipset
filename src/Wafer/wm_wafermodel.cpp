

// Includes
#include "wm_wafermodel.h"

// Qt includs
#include <QtCore\QSize>


///////////////////////////////////////////////////////////////////////////////
//
// Imlementation of CWaferArea
//
void wm::CWaferModel::setName( QString const& sName )
{
	m_sName = sName;
}

void wm::CWaferModel::setLotName( QString const& sName )
{
	m_sLotName = sName;
}

int wm::CWaferModel::getDieCount() const
{
	return 0;
}

int wm::CWaferModel::getValidDieCount() const
{
	return 0;
}

int wm::CWaferModel::getFirstDieX() const
{
	return 0;
}

int wm::CWaferModel::getLastDieX() const
{
	return 0;
}

int wm::CWaferModel::getFirstDieY() const
{
	return 0;
}

int wm::CWaferModel::getLastDieY() const
{
	return 0;
}

QSizeF wm::CWaferModel::getDieSize() const
{
	return QSizeF(0.01, 0.01);
}

double wm::CWaferModel::getDieSpacing() const
{
	return 0.15;
}

wm::EDieStatus wm::CWaferModel::getHBin( int nDieX, int nDieY, int& nHBin ) const
{
	return EDieStatus::NoDie;
}

wm::EDieStatus wm::CWaferModel::getSBin( int nDieX, int nDieY, int& nSBin ) const
{
	return EDieStatus::NoDie;
}
///////////////////////////////////////////////////////////////////////////////