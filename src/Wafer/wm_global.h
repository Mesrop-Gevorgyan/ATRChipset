


#ifndef WS_GLOBAL_H
#define WS_GLOBAL_H


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

// Wafer map type
enum class WaferMapType
{
	eSingleBIN,
	eIntensity,
	eYield,
	eMostFrequentBIN,
	eGroupAggregation
};

// Die Status
enum class EDieStatus
{
	eNoDie,
	eInvalidDie,
	eNormalDie
};

// Orientation
enum class EOrientation
{
	eAuto,
	eHorizontal,
	eVertical
};

// Scale label direction
enum class EScaleDirection
{
	eLeftToRight,
	eRightToLeft,
	eBottomToTop,
	eTopToBottom
};

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_GLOBAL_H