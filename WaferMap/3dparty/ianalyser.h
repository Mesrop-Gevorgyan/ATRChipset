
#ifndef  ANALYSER_H
#define  ANALYSER_H


#include <configuration.h>


// Froesord declaration
class QWidget;


///////////////////////////////////////////////////////////////////////////////
//
// Interface IAnalyser
//
class IAnalyser
{
public:
	// Set configuration
	virtual void setConfig(const CConfiguration& oCfg) = 0;
	// Show the window of result
	virtual QWidget *getView() const = 0;
	// Run the analyse 
	virtual void run() = 0;
};
///////////////////////////////////////////////////////////////////////////////

#endif // ANALYSER_H