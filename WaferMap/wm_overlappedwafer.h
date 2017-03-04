


#ifndef WM_OVERLAPPEDWAFER_H
#define WM_OVERLAPPEDWAFER_H


// Includes
#include "wm_wafermodelbase.h"

// Qt includes
#include <QList>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class COverlappedWafer
//
class COverlappedWafer : public CWaferModelBase
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
	// Get Bin
	EDieStatus getBin( int nDieX, int nDieY, int& nBin ) const;
	// Get yield
	EDieStatus getYield( int nDieX, int nDieY, int& nYield ) const;
	// Get most frequent bin
	EDieStatus getMostFrequentBin( int nDieX, int nDieY, int& nBin, int& nPercent ) const;
	// Get bad and good die count
	EDieStatus getGroupAggregation( int nDieX, int nDieY, int& nBad, int& nGood ) const;

public:
	//
	//! Own Interface
	//
	// Add wafer
	bool addWaferModel( IWaferModel* pNewWafer );

protected:
	//
	//! Implementation
	//
	// Reset die indices
	void reset();

private:
	//
	//! Content
	//
	// Wafers
	QList<IWaferModel*>		m_aWafers;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
inline COverlappedWafer::COverlappedWafer()
	: CWaferModelBase()
{
	
}

inline COverlappedWafer::~COverlappedWafer()
{
	for (int i = 0; i < m_aWafers.size(); ++i)
		delete m_aWafers[i];
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WM_OVERLAPPEDWAFER_H