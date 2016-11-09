#include "statistic_analyser.h"

CStatistics::CStatistics():m_viwer(new QWidget)
{}

void CStatistics::setConfig(const CConfiguration & configuration) override
{
    m_config = configuration;
}

void CStatistics::setData(const CSelection & selection)override
{
    m_selection_data = selection;
}

QWidget * CStatistics::getView()const
{
    m_viwer ->show();
}

void CStatistics::run()const
{
    //run analys
}
