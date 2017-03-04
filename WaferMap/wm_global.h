


#ifndef WM_GLOBAL_H
#define WM_GLOBAL_H


// Qt includes
#include <QString>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////


// Configuration constants
QString const csWaferNames = QString("wafernames");
QString const csWaferType = QString("wafertype");
QString const csBinType = QString("bintype");


// Wafer map type
enum class EWaferType
{
	Invalid,
	SingleBin,
	Yield,
	MostFrequentBin,
	GroupAggregation
};

// Wafer dimple position
enum class EDimplePosition
{
	Bottom,
	Top,
	Left,
	Right
};

// Die Status
enum class EDieStatus
{
	NoDie,
	InvalidDie,
	NormalDie
};

// Orientation
enum class EOrientation
{
	Auto,
	Horizontal,
	Vertical
};

// Scale label direction
enum class EScaleDirection
{
	LeftToRight,
	RightToLeft,
	BottomToTop,
	TopToBottom
};

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WM_GLOBAL_H