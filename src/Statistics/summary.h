#ifndef SUMMARY_H
#define SUMMARY_H

#include "configuration.h"
#include "selection.h"
#include "dataprovider.h"
#include "statistics.h"
#include "ianalayser.h"

class CSummary: public IAnalyser
{
public:
    CSummary();

    virtual void init(const IDataProvider* ,
                      const CConfiguration&) override;
    //returns the configuration
    virtual CConfiguration getConfig()const override;
    //returns the Provider
    virtual const IDataProvider* getProvider()const override;
    //runs the analyse
    virtual void run()const override;

private:
    CConfiguration m_config;
    const IDataProvider* m_data_provider;
};

#endif // SUMMARY_H
