#ifndef SUMMARY_H
#define SUMMARY_H

#include "configuration.h"
#include "selection.h"
#include "dataprovider.h"
#include "statistics.h"
#include "ianalayser.h"
#include "itable.h"
#include "table.h"

class CSummary: public IAnalyser
{
public:
    CSummary();

    virtual void init(DataProvider* ,
                      const CConfiguration&) override;
    //returns the configuration
    virtual CConfiguration getConfig()const override;
    //returns the Provider
    virtual const IDataProvider* getProvider()const override;
    //runs the analyse
    virtual void run()const override;
    void view_results() const;
    //void view_results(ITablePtr) const;

private:
    CConfiguration m_config;
    DataProvider* m_data_provider;
    mutable ITablePtr m_result_table;
};

#endif // SUMMARY_H
