#include "CBinPareto.h"

CBinPareto::CBinPAreto():m_view(new QWidget())
{}

void CBinPareto::setConfig(const Configuration & config)
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

BinPAreto::~BinPareto()
{}
