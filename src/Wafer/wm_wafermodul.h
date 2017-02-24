

#ifndef WAFERMODUL_H
#define WAFERMODUL_H


#include <ianalyser.h>


///////////////////////////////////////////////////////////////////////////////
//
// class CWafer
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
	void setConfig(const CConfiguration& oConfig) override;
	// Get wafer view
	QWidget *getView() const override;
	// Run wafer making and drawing
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
	QWidget*			m_pwView;
};
///////////////////////////////////////////////////////////////////////////////

#endif // WAFERMODUL_H
