


#ifndef WS_WAFERDRAWER_H
#define WS_WAFERDRAWER_H


// Includes
#include "wm_drawer.h"
#include "wm_area.h"
#include "wm_iwafermodel.h"

// Qt includes
#include <QScopedPointer>
#include <QColor>
#include <QList>
#include <QPair>
#include <QSet>


// Qt forward declarations
class QPointF;
class QPointF;
class QRectF;
class QPainterPath;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferDrawer, draw wafer map
//	
class CWaferDrawer : public CDrawer
{
public:
	// Init constructor
	CWaferDrawer( IWaferModel const* pModel );
	// Destructor
	virtual ~CWaferDrawer();

public:
	//
	//! Override CDrawable interface
	//
	// Do layout
	QRect doLayout( QRect const& rc ) override;
	// Draw
	void draw( QPainter* pPainter ) const override;

public:
	//
	//! Own interface
	//
	// Set\Get wefer dimple position
	inline void setDimplePosition( EDimplePosition eDimplePos );
	inline EDimplePosition getDimplePosition() const;
	// Set\Get wafer color
	inline void setColor( QColor const& oColor );
	inline QColor getColor() const;
	// Get area rect
	inline QRectF getArea() const;
	// Zoom in/zoom out
	bool zoom( QRectF rcZoom );
	// Scroll left-right
	bool scrollLR( int iShift );
	// Scroll top-bottom
	bool scrollTB( int iShift );
	// Select die
	void selectDie( QPointF const& ptF );
	// Select dies
	void selectDies( QRectF const& rcSel );
	// Clear selection
	void clearSelection();
	// Adjust zoom
	virtual void adjust();
	// Resolve prefered area for drawing
	QRect getPreferedArea() const;


protected:
	//
	//! Implementation
	//
	// Get X Ruler direction
	EScaleDirection getXRulerDirection() const;
	// Get Y Ruler direction
	EScaleDirection getYRulerDirection() const;
	// Get wafer center
	QPointF getWaferCenter() const;
	// Get wafer rect
	QRectF getWaferGeometry() const;
	// Get dimple info
	void getDimpleInfo( QRectF& rcFDimple, double& nWaferStartAngel ) const;
	// Draw die
	void drawWaferContur( QPainter* pPainter ) const;
	// Get die rect
	QRectF getDieRect( int nDieX, int nDieY ) const;
	// Draw valid (defined) die
	virtual void drawValidDie( QPainter* pPainter, int nDieX, int nDieY ) const;
	// Draw invalid (undefined) die
	virtual void drawInvalidDie( QPainter* pPainter, int nDieX, int nDieY ) const;
	// Get painter path for clipping
	virtual QPainterPath getClipping() const;
	// Check can die draw
	virtual bool canDraw( QRectF const& rcFDie ) const;
	// Select die
	void selectDie( int nDieX, int nDieY );
	// Remove die selection
	void removeSelection( int nDieX, int nDieY );
	// Check is selected
	bool isSelected( int nDieX, int nDieY ) const;

private:
	//
	//! Content
	//
	// Wafer model
	IWaferModel const*					m_pModel;
	// Selected dies
	QSet<QPair<int, int>>				m_aSelectedDies;
	//Wafer die selection
	QList<QPair<int, int>>				m_aDieSelection;
	// Wafer dimple position
	EDimplePosition						m_eDimplePos;
	// Wafer lines color
	QColor								m_oColor;
	// Wafer area for data translation
	QScopedPointer<CArea>				m_pArea;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
void wm::CWaferDrawer::setDimplePosition( EDimplePosition eDimplePos )
{
	m_eDimplePos = eDimplePos;
}

EDimplePosition wm::CWaferDrawer::getDimplePosition() const
{
	return m_eDimplePos;
}

inline void CWaferDrawer::setColor( QColor const & oColor )
{
	m_oColor = oColor;
}

inline QColor CWaferDrawer::getColor() const
{
	return m_oColor;
}

inline QRectF CWaferDrawer::getArea() const
{
	Q_ASSERT(m_pArea);
	return m_pArea->getScreen();
}

inline EScaleDirection CWaferDrawer::getXRulerDirection() const
{
	switch (getDimplePosition())
	{
	case EDimplePosition::Bottom:
		return EScaleDirection::LeftToRight;
	case EDimplePosition::Top:
		return EScaleDirection::RightToLeft;
	case EDimplePosition::Left:
		return EScaleDirection::TopToBottom;
	case EDimplePosition::Right:
		return EScaleDirection::BottomToTop;
	}
	Q_ASSERT(false);
	return EScaleDirection::LeftToRight;
}

inline EScaleDirection CWaferDrawer::getYRulerDirection() const
{
	switch (getDimplePosition())
	{
	case EDimplePosition::Bottom:
		return EScaleDirection::TopToBottom;
	case EDimplePosition::Top:
		return EScaleDirection::BottomToTop;
	case EDimplePosition::Left:
		return EScaleDirection::RightToLeft;
	case EDimplePosition::Right:
		return EScaleDirection::LeftToRight;
	}
	Q_ASSERT(false);
	return EScaleDirection::TopToBottom;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERDRAWER_H