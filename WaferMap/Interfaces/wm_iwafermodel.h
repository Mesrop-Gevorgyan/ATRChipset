


#ifndef WS_IWAFERMODEL_H
#define WS_IWAFERMODEL_H


// Includes
#include "global.h"
#include "wm_global.h"
#include "wm_dieindexmapping.h"

// Qt forward declarations
#include <QPair>
#include <QList>
#include <QRectF>
#include <QPointF>

// Qt forward declarations
class QString;
class QSizeF;

///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Interface IWaferModel, provide physicle wafer data
//
class IWaferModel
{
public:
	//
	//! Own Interface
	//
	// Get all die cordinats
	virtual QList<QPair<int, int>> getDieCordinats() const = 0;
	// Get die indices
	virtual CDieIndexMapping getDieIndices() const = 0;
	// Get valid Die Count
	virtual int getValidDieCount() const = 0;
	// Get wafer radius
	virtual double getRadius() const = 0;
	// Get wafer center
	virtual QPointF getWaferCenter() const = 0;
	// Get Die size
	virtual QSizeF getDieSize() const = 0;
	// Get die rect
	virtual QRectF getDieRect( int nDieX, int nDieY ) const = 0;
	// Get Die spacing
	virtual double getDieSpacing() const = 0;
	// Get die status
	virtual EDieStatus getDieSatus( int nDieX, int nDieY ) const = 0;
	// Get Bin
	virtual EDieStatus getBin( int nDieX, int nDieY, int& nBin ) const = 0;
	// Get yield
	virtual EDieStatus getYield( int nDieX, int nDieY, int& nYield ) const = 0;
	// Get most frequent bin
	virtual EDieStatus getMostFrequentBin( int nDieX, int nDieY, int& nBin, int& nPercent ) const = 0;
	// Get bad and good die count
	virtual EDieStatus getGroupAggregation( int nDieX, int nDieY, int& nBad, int& nGood ) const = 0;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_IWAFERMODEL_H