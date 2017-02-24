


#ifndef WS_IWAFERAREA_H
#define WS_IWAFERAREA_H


// Includes
#include "wm_global.h"


// Qt forword declaration
class QPoint;
class QPointF;
class QSize;
class QSizeF;
class QRect;
class QRectF;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Interface IWaferArea
//
class IWaferArea
{
public:
	//
	//! Own Interface
	//
	// Translate data area points to screen
	// Translate one point
	virtual double translate( double fPoint, EScaleDirection eScaleDirection ) const = 0;
	// Translate two point(x, y)
	virtual QPointF translate( double fPoint, EScaleDirection eXScaleDirection, double fYPoint, EScaleDirection eYScaleDirection ) const = 0;
	virtual QPointF translate( QPointF const& pointF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const = 0;
	// Translate size (weight, height)
	virtual QSizeF translate( QSizeF const& sizeF ) const = 0;
	// Translate rect (x1, y1, x2, y2)
	virtual QRectF translate( QRectF const& rectF, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const = 0;

	// Reverse data area point from screen
	// Reverse one point
	virtual double reverse( double fArea, EScaleDirection eScaleDirection ) const = 0;
	// Reverse two point(x, y)
	virtual QPointF reverse( double fXArea, EScaleDirection eXScaleDirection, double fYArea, EScaleDirection eYScaleDirection ) const = 0;
	virtual QPointF reverse( QPointF const& ptFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const = 0;
	// Reverse size (weight, height)
	virtual QSizeF reverse( QSizeF const& szFArea ) const = 0;
	// Reverse rect (x1, y1, x2, y2)
	virtual QRectF reverse( QRectF const& rcFArea, EScaleDirection eXScaleDirection, EScaleDirection eYScaleDirection ) const = 0;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_IWAFERAREA_H
