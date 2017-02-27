


#ifndef WS_WAFERMODEL_H
#define WS_WAFERMODEL_H


// Includes
#include "ivector.h"
#include "wm_iwafermodel.h"
#include "wm_dieindexmapping.h"

// Qt includs
#include <QtCore\QString>


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferModel, provide wafer data
//
class CWaferModel : public IWaferModel
{
	Q_DISABLE_COPY(CWaferModel);

public:
	// Default constructor
	inline CWaferModel();
	// Destructor
	inline ~CWaferModel();

public:
	//
	//! Override IWafer interface
	//
	// Get wafer name
	QString getName() const override;
	// Get Lot name
	QString getLotName() const override;
	// Get All Die Count
	int getDieCount() const override;
	// Get Valid Die Count
	int getValidDieCount() const override;
	// Get First DieX
	int getFirstDieX() const override;
	// Get Last DieX
	int getLastDieX() const override;
	// Get First DieY
	int getFirstDieY() const override;
	// Get Last DieY
	int getLastDieY() const override;
	// Get Die phisicle size
	QSizeF getDieSize() const override;
	// Get Die phisicle spacing
	double getDieSpacing() const override;
	// Get HBin
	EDieStatus getHBin( int nDieX, int nDieY, int& nHBin ) const override;
	// Get SBin
	EDieStatus getSBin( int nDieX, int nDieY, int& nSBin ) const override;

public:
	//
	//! Own Interface
	//
	// Set wafer name
	inline void setName( QString const& sName );
	// Set Lot name
	inline void setLotName( QString const& sName );
	// Set/Get index mapping
	void setIndices( CDieIndexMapping const& aIndices );
	CDieIndexMapping getIndices() const;

	// Set/Get DieX cordinats provider
	void setDieX( IIntVector const* cpDieX );
	IIntVector const* getDieX() const;
	// Set/Get DieY cordinats provider
	void setDieY( IIntVector const* cpDieY );
	IIntVector const* getDieY() const;

	// Set/Get HBin data
	void setHBin( IIntVector const* cpHBin );
	IIntVector const* getHBin() const;
	// Set/Get HBin data
	void setSBin( IIntVector const* cpSBin );
	IIntVector const* getSBin() const;

private:
	//
	//! Content
	//
	// Lot name witch contains the wafer
	QString						m_sLotName;
	// Wafer name
	QString						m_sName;
	// Indices array
	CDieIndexMapping			m_aDieIndices;
	
	// Wafer data provider
	// Die X/Y conrdinats
	IIntVector const*			m_cpDieX;
	IIntVector const*			m_cpDieY;
	// HBin Data
	IIntVector const*			m_cpHBin;
	IIntVector const*			m_cpSBin;
};
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// Inline Implementations
//
CWaferModel::CWaferModel()
{
	
}

CWaferModel::~CWaferModel()
{

}

inline QString CWaferModel::getName() const
{
	return m_sName;
}

inline QString CWaferModel::getName() const
{
	return m_sLotName;
}

inline void CWaferModel::setIndices( CDieIndexMapping const& aIndices )
{
	m_aDieIndices = aIndices;
}

inline CDieIndexMapping CWaferModel::getIndices() const
{
	return m_aDieIndices;
}

inline void CWaferModel::setDieX( IIntVector const* cpDieX )
{
	Q_ASSERT(cpDieX);
	m_cpDieX = cpDieX;
}

inline IIntVector const* CWaferModel::getDieX() const
{
	return m_cpDieX;
}

inline void CWaferModel::setDieX( IIntVector const* cpDieY )
{
	Q_ASSERT(cpDieY);
	m_cpDieY = cpDieY;
}

inline IIntVector const* CWaferModel::getDieY() const
{
	return m_cpDieY;
}

inline void CWaferModel::setHBin( IIntVector const* cpHBin )
{
	Q_ASSERT(cpHBin);
	m_cpHBin = cpHBin;
}

inline IIntVector const* CWaferModel::getHBin() const
{
	return m_cpHBin;
}

inline void CWaferModel::setHBin( IIntVector const* cpSBin )
{
	Q_ASSERT(cpSBin);
	m_cpSBin = cpSBin;
}

inline IIntVector const* CWaferModel::getSBin() const
{
	return m_cpSBin;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WS_WAFERMODEL_H