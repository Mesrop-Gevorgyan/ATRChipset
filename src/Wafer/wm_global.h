


#ifndef WS_GLOBAL_H
#define WS_GLOBAL_H


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

// Wafer map type
enum class EWaferMapType
{
	SingleBIN,
	Intensity,
	Yield,
	MostFrequentBIN,
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

#endif //! WS_GLOBAL_H