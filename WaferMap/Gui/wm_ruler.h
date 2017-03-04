


#ifndef WS_RULER_H
#define WS_RULER_H


// Includs
#include "wm_global.h"
#include "wm_drawer.h"
#include "wm_area.h"
#include "wm_iwafermodel.h"


// Qt includs
#include <QScopedPointer>
#include <QString>
#include <QList>

// Qt forward declarations
class QRect;
class QPainter;


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

// Ruler aligment
enum class ERulerAligment
{
	Left,
	Right,
	Top,
	Bottom
};


///////////////////////////////////////////////////////////////////////////////
//
// class CRuler
//
class CRuler : public CDrawer
{
public:
	// Default constructor
	inline CRuler();
	// Destructor
	inline ~CRuler();

public:
	//
	//! Override CDrawer interface
	//
	// Do layout
	void doLayout( QRect const& rc ) override;
	// Draw scale (ticks and labels)
	void draw( QPainter* pPainter ) const override;

public:
	//
	//! Own Interface
	//
	// get prefered size
	int getPreferedSize() const;
	// Set/Get ruler aligment
	inline void setAligment( ERulerAligment eAlign );
	inline ERulerAligment getAligment() const;
	// Set/Get range
	inline void setRange( double fMin, double fMax );
	inline void getRange( double& fMin, double& fMax ) const;
	// Set/Get wafer model
	inline void setWaferModel( IWaferModel const* pWaferModel );
	inline IWaferModel const* setWaferModel() const;

protected:
	//
	//! Tick
	//
	struct STickDie
	{
		QString		sLabel;
		int			nStart;
		int			nEnd;
	};

protected:
	//
	//! Implementation
	//
	void getDieCoordinates( int& nDieMin, int& nDieMax ) const;

private:
	//
	//! Content
	//
	// Ruler aligment
	ERulerAligment			m_eRulerAlign;
	// Wafer model
	IWaferModel const*		m_pWaferModel;
	// Area translator
	QScopedPointer<CArea>	m_pArea;
	// Die Ticks
	QList<STickDie>			m_lstTicks;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline implementation
//
inline CRuler::CRuler()
	: m_eRulerAlign( ERulerAligment::Bottom ),
	  m_pWaferModel( nullptr ),
	  m_pArea( nullptr ),
	  m_lstTicks()
{
	m_pArea.reset(new CArea);
	Q_ASSERT(m_pArea);
}

inline CRuler::~CRuler()
{

}

inline void CRuler::setAligment( ERulerAligment eAlign )
{
	m_eRulerAlign = eAlign;
}

inline ERulerAligment CRuler::getAligment() const
{
	return m_eRulerAlign;
}

void CRuler::setRange( double fMin, double fMax )
{
	Q_ASSERT(m_pArea);
	if (m_eRulerAlign == ERulerAligment::Top || m_eRulerAlign == ERulerAligment::Bottom)
		m_pArea->setXRange( fMin, fMax );
	else
		m_pArea->setYRange( fMin, fMax );
}

void CRuler::getRange( double& fMin, double& fMax ) const
{
	Q_ASSERT(m_pArea);
	if (m_eRulerAlign == ERulerAligment::Top || m_eRulerAlign == ERulerAligment::Bottom)
		m_pArea->getXRange( fMin, fMax );
	else
		m_pArea->getYRange( fMin, fMax );
}

inline void CRuler::setWaferModel( IWaferModel const* pWaferMode  )
{
	Q_ASSERT(pWaferMode);
	m_pWaferModel = pWaferMode;
}

inline IWaferModel const* CRuler::setWaferModel() const
{
	return m_pWaferModel;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_RULER_H