


#ifndef WS_IWAFERMODEL_H
#define WS_IWAFERMODEL_H


// Includes
#include "wm_global.h"

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
	// Get wafer name
	virtual QString getName() const = 0;
	// Get Lot name
	virtual QString getLotName() const = 0;
	// Get all die cordinats
	virtual QList<QPair<int, int>> getDieCordinats() const = 0;
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
	// Get HBin
	virtual EDieStatus getHBin( int nDieX, int nDieY, int& nHBin ) const = 0;
	// Get SBin
	virtual EDieStatus getSBin( int nDieX, int nDieY, int& nSBin ) const = 0;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_IWAFERMODEL_H