


#ifndef WM_WAFERMODELBASE_H
#define WM_WAFERMODELBASE_H


// Includes
#include "ivector.h"
#include "wm_iwafermodel.h"
#include "wm_dieindexmapping.h"

// Qt includs
#include <QSizeF>
#include <QRectF>
#include <QPointF>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferModelBase
//
class CWaferModelBase : public IWaferModel
{
	Q_DISABLE_COPY(CWaferModelBase);

public:
	// Default constructor
	inline CWaferModelBase();
	// Destructor
	inline ~CWaferModelBase();

public:
	//
	//! Override IWaferModel interface
	//
	// Get die all cordinats
	QList<QPair<int, int>> getDieCordinats() const override;
	// Get die indices
	CDieIndexMapping getDieIndices() const override;
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
	
public:
	//
	//! Own Interface
	//
	// Set/Get index mapping
	inline void setIndices( CDieIndexMapping const& aIndices );
	// Set wafer radius
	inline void setWaferRadius( double fRadius );
	// Set Die size
	inline void setDieSize( QSizeF const& szF );
	// Set Die spacing
	inline void setDieSpacing( double fSpacing );

	// Set/Get Bin data
	void setBinData( IIntVector const* cpBin );
	IIntVector const* getBinData() const;

protected:
	//
	//! Content
	//
	// Wafer radius
	double						m_fRadius;
	// Die size
	QSizeF						m_szFDie;
	// Die spacing
	double						m_fDieSpacing;
	// Die indices
	CDieIndexMapping			m_aDieIndices;
	
	// Wafer data
	// Bin Data
	IIntVector const*			m_cpBin;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
inline CWaferModelBase::CWaferModelBase()
	: m_fRadius( 0.30 ),
	  m_szFDie( QSizeF(0.018, 0.018) ),
	  m_fDieSpacing( 0.00018 ),
	  m_aDieIndices(),
	  m_cpBin( nullptr )
{
	
}

inline CWaferModelBase::~CWaferModelBase()
{

}

inline void CWaferModelBase::setIndices( CDieIndexMapping const& aIndices )
{
	m_aDieIndices = aIndices;
}

inline void CWaferModelBase::setWaferRadius( double fRadius )
{
	Q_ASSERT(m_fDieSpacing >= 0);
	m_fDieSpacing = fRadius;
}

inline void CWaferModelBase::setDieSize( QSizeF const& szF )
{
	Q_ASSERT(szF.isValid());
	m_szFDie = szF;
}

inline void CWaferModelBase::setDieSpacing( double fSpacing )
{
	Q_ASSERT(fSpacing >= 0);
	m_fDieSpacing = fSpacing;
}

inline void CWaferModelBase::setBinData( IIntVector const* cpBin )
{
	Q_ASSERT(cpBin);
	m_cpBin = cpBin;
}

inline IIntVector const* CWaferModelBase::getBinData() const
{
	return m_cpBin;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WM_WAFERMODELBASE_H