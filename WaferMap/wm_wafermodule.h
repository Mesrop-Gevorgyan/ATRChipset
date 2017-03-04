

#ifndef WAFERMODULE_H
#define WAFERMODULE_H


// Includes
#include "ianalyser.h"


// Declar private helper
class CWaferModulData;


///////////////////////////////////////////////////////////////////////////////
//
// class CWaferModul
//
class Q_DECL_EXPORT CWaferModul : public IAnalyser
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
	CConfiguration				m_oConfig;
	// Data provider
	//TODO
	// Private data
	CWaferModulData*			m_pData;
};
///////////////////////////////////////////////////////////////////////////////

#endif //! WAFERMODULE_H
