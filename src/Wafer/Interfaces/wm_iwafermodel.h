


#ifndef WS_IWAFERMODEL_H
#define WS_IWAFERMODEL_H


// Includes
#include "wm_global.h"

// Qt forward declarations
class QString;

///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Interface IWaferModel, provide wafer data
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
	// Get All Die Count
	virtual int getDieCount() const = 0;
	// Get Valid Die Count
	virtual int getValidDieCount() const = 0;
	// Get First DieX
	virtual int getFirstDieX() const = 0;
	// Get Last DieX
	virtual int getLastDieX() const = 0;
	// Get First DieY
	virtual int getFirstDieY() const = 0;
	// Get Last DieY
	virtual int getLastDieY() const = 0;
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
