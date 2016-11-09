#ifndef STATISTIC_ANALYSER_H
#define STATISTIC_ANALYSER_H

#include "IAnalyser.h"
#include "dataselection_interfaces.h"
#include "configuration.h"

class CStatistics: public IAnalyser
{
public:
    CStatistics();
    //set configuration
    virtual void setConfig(const CConfiguration & configuration) override;
    //set data selection
    virtual void setData(const CSelection & selection)override;
    //shows the result of analyse
    QWidget *getView()const;
    //runs the analyse
    void run()const;
private:
    CConfiguration m_config;
    QWidget * m_viwer;
    CSelection m_selection_data;
};

#endif // STATISTIC_ANALYSER_H
