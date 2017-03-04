


#ifndef WM_SINGLEWAFER_H
#define WM_SINGLEWAFER_H


// Includes
#include "ivector.h"
#include "wm_iwafermodel.h"
#include "wm_dieindexmapping.h"

// Qt includs
#include <QSizeF>
#include <QString>
#include <QPointF>
#include <QRectF>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CSingleWafer
//
class CSingleWafer : public IWaferModel
{
	Q_DISABLE_COPY(CSingleWafer);

public:
	// Default constructor
	inline CSingleWafer();
	// Destructor
	inline ~CSingleWafer();

public:
	//
	//! Override IWafer interface
	//
	// Get wafer name
	QString getName() const override;
	// Get Lot name
	QString getLotName() const override;
	// Get die all cordinats
	QList<QPair<int, int>> getDieCordinats() const override;
	// Get Valid Die Count
	int getValidDieCount() const override;
	// Get wafer radius
	double getRadius() const override;
	// Get wafer center
	QPointF getWaferCenter() const override;
	// Get Die phisicle size
	QSizeF getDieSize() const override;
	// Get die rect
	QRectF getDieRect( int nDieX, int nDieY ) const override;
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
	// Set wafer name
	inline void setName( QString const& sName );
	// Set Lot name
	inline void setLotName( QString const& sName );
	// Set/Get index mapping
	void setIndices( CDieIndexMapping const& aIndices );

	// Set wafer radius
	inline void setWaferRadius( double fRadius );
	// Set Die size
	inline void setDieSize( QSizeF const& szF );
	// Set Die spacing
	inline void setDieSpacing( double fSpacing );

	// Set/Get HBin data
	void setHBin( IIntVector const* cpHBin );
	IIntVector const* getHBin() const;
	// Set/Get HBin data
	void setSBin( IIntVector const* cpSBin );
	IIntVector const* getSBin() const;

private:
	//
	//! Content
	//
	// Lot name witch contains the wafer
	QString						m_sLotName;
	// Wafer name
	QString						m_sName;
	// Wafer radius
	double						m_fRadius;
	// Die size
	QSizeF						m_szFDie;
	// Die spacing
	double						m_fDieSpacing;
	// Die indices
	CDieIndexMapping			m_aDieIndices;
	
	// Wafer data
	// HBin Data
	IIntVector const*			m_cpHBin;
	// SBin Data
	IIntVector const*			m_cpSBin;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
CSingleWafer::CSingleWafer()
	: m_sLotName( "<Lot>" ),
	  m_sName( "<Wafer>" ),
	  m_fRadius( 0.30 ),
	  m_szFDie( QSizeF(0.018, 0.018) ),
	  m_fDieSpacing( 0.00018 ),
	  m_aDieIndices(),
	  m_cpHBin( nullptr ),
	  m_cpSBin( nullptr )

{
	
}

CSingleWafer::~CSingleWafer()
{

}

void wm::CSingleWafer::setName( QString const& sName )
{
	m_sName = sName;
}

void CSingleWafer::setLotName( QString const& sName )
{
	m_sLotName = sName;
}

inline void CSingleWafer::setIndices( CDieIndexMapping const& aIndices )
{
	m_aDieIndices = aIndices;
}

inline void CSingleWafer::setWaferRadius( double fRadius )
{
	Q_ASSERT(m_fDieSpacing >= 0);
	m_fDieSpacing = fRadius;
}

inline void CSingleWafer::setDieSize( QSizeF const& szF )
{
	Q_ASSERT(szF.isValid());
	m_szFDie = szF;
}

inline void CSingleWafer::setDieSpacing( double fSpacing )
{
	Q_ASSERT(fSpacing >= 0);
	m_fDieSpacing = fSpacing;
}

inline void CSingleWafer::setHBin( IIntVector const* cpHBin )
{
	Q_ASSERT(cpHBin);
	m_cpHBin = cpHBin;
}

inline IIntVector const* CSingleWafer::getHBin() const
{
	return m_cpHBin;
}

inline void CSingleWafer::setSBin( IIntVector const* cpSBin )
{
	Q_ASSERT(cpSBin);
	m_cpSBin = cpSBin;
}

inline IIntVector const* CSingleWafer::getSBin() const
{
	return m_cpSBin;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WM_SINGLEWAFER_H