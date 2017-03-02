

#ifndef WAFERMODULE_H
#define WAFERMODULE_H


// Includes
#include "ianalyser.h"

// Qt includes
#include <QScopedPointer>

// Declar private helper
class CWaferModulData;

///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// class CWaferModul
//
class CWaferModul : public IAnalyser
{
public:
	// Constructors
	CWaferModul();
	// Destructor
	~CWaferModul();

public:
	// Set configuration
	void setConfig( const CConfiguration& oConfig ) override;
	// Set data provider
	//TODO
	// Get wafer view
	QWidget* getView() const override;
	// Run wafer
	void run() override;

protected:
	//
	// Implementataion
	//
	// Reset modul
	void reset();

private:
	//
	// Content
	//
	// Wafer config
	CConfiguration						m_oConfig;
	// Data provider
	//TODO
	// Private data
	QScopedPointer<CWaferModulData>		m_pData;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WAFERMODULE_H
