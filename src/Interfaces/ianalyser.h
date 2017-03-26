#ifndef IANALYSER_H
#define IANALYSER_H

#include "configuration.h"
#include "selection.h"
#include <QWidget>

class IAnalyser
{
public:

    //init 
    virtual void init(const IDataProvider* ,
					  const CConfiguration&) = 0;
    //returns the configuration
    virtual CConfiguration getConfig()const = 0;
	//returns the Provider
	virtual const IDataProvider* getProvider()const = 0;
    //runs the analyse
    virtual void run()const = 0;
};

#endif //IANALYSER_H
