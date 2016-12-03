

#ifndef WAFER_H
#define WAFER_H


#include <ianalyser.h>


///////////////////////////////////////////////////////////////////////////////
//
// class CWafer
//
class CWafer : public IAnalyser
{
public:
	// Constructors
	CWafer();
	// Destructor
	~CWafer();

public:
	// Set configuration
	void setConfig(const CConfiguration& oConfig) override;
	// Get wafer view
	QWidget *getView() const override;
	// Run wafer making and drowing
	void run() override;

protected:
	//
	// Implementataion
	//

private:
	//
	// Content
	//
	CConfiguration			m_oConfig;
	QWidget*				m_pwView;
};
///////////////////////////////////////////////////////////////////////////////

#endif // WAFER_H