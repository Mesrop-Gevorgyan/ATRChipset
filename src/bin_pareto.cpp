#include "bin_pareto.h"

CBinPareto::CBinPAreto():m_view(new QWidget())
{}

void CBinPareto::setConfig(const CConfiguration & config)
{
	m_config = config;
}

QWidget * CBinPareto::getView()const
{
	//return m_view->window();
}

void CBinPareto::run()const
{
}

CBinPAreto::~CBinPareto()
{}
