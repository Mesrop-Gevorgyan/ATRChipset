


#ifndef WS_OVERLAPPEDWAFER_H
#define WS_OVERLAPPEDWAFER_H


// Includes
#include "wm_iwafermodel.h"

// Qt includes
#include <QList>
#include <QPair>
#include <QHash>
#include <QString>

// Qt forward declarations
class QStringList;

///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class COverlappedWafer
//
class COverlappedWafer : IWaferModel
{
	Q_DISABLE_COPY(COverlappedWafer);

public:
	// Default constructor
	inline COverlappedWafer();
	// Destructor
	inline ~COverlappedWafer();

public:
	//
	//! Override IWaferModel interface
	//
	// Get wafer name
	QString getName() const override;
	// Get Lot name
	QString getLotName() const override;
	// Get die all cordinats
	QList<QPair<int, int>> getDieCordinats() const override;
	// Get Valid Die Count
	int getValidDieCount() const override;
	// Get radius
	double getRadius() const override;
	// Get Die phisicle size
	QSizeF getDieSize() const override;
	// Get Die phisicle spacing
	double getDieSpacing() const override;
	// Get die status
	EDieStatus getDieSatus( int nDieX, int nDieY ) const override;
	// Get HBin
	EDieStatus getHBin( int nDieX, int nDieY, int& nHBin ) const override;
	// Get SBin
	EDieStatus getSBin( int nDieX, int nDieY, int& nSBin ) const override;

public:
	//
	//! Own Interface
	//
	// Get wafer names
	QStringList getWaferNames( QString const& sLotName = QString() ) const;
	// Get wafer names
	QStringList getLotNames() const;
	// Get wafer
	inline IWaferModel const* getWafer( QString const& sLotName, QString const& sWaferName ) const;
	// Add wafer
	bool addWafer( IWaferModel const* pNewWafer );
	// Remove wafer by name
	void removeWafer( QString const& sLotName, QString const& sWaferName );

protected:
	//
	//! Implementation
	// Generate key for the wafer
	inline QString makeKey( QString const& sLotName, QString const& sWaferName ) const;
	// Update die indices
	void reset();

private:
	//
	//! Content
	//
	// Wafers
	QHash<QString, IWaferModel const*>		m_aWafers;
	// Die indices
	QList<QPair<int, int>>					m_aDieCordinats;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
COverlappedWafer::COverlappedWafer()
	: m_aWafers(),
	  m_aDieCordinats()
{
	
}

COverlappedWafer::~COverlappedWafer()
{

}

inline IWaferModel const* COverlappedWafer::getWafer( QString const& sLotName, QString const& sWaferName ) const
{
	return m_aWafers.value( makeKey( sLotName, sWaferName ), nullptr );
}

inline void COverlappedWafer::removeWafer( QString const& sLotName, QString const& sWaferName )
{
	if (m_aWafers.remove( makeKey( sLotName, sWaferName ) ) > 0)
		reset();
}

inline QString COverlappedWafer::makeKey( QString const& sLotName, QString const& sWaferName ) const
{
	return QString("%1::%2").arg( sLotName).arg( sWaferName );
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_OVERLAPPEDWAFER_H