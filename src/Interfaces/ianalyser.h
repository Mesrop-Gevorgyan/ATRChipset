#ifndef IANALYSER_H
#define IANALYSER_H

#include "configuration.h"
#include "selection.h"
#include <QWidget>

class IAnalyser
{
public:
    //set configuration
    virtual void setConfig(const CConfiguration &) = 0;
    //set data selection
    virtual void setData(const CSelection &) = 0;
    //returns the configuration
    virtual CConfiguration getConfig()const = 0;
    //shows the window of result
    virtual QWidget *getView()const = 0;
    //runs the analyse
    virtual void run()const = 0;
};

#endif //IANALYSER_H
