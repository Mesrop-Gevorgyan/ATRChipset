#include "BinPareto.h"

BinPareto::BinPAreto():m_view(new QWidget())
{}

void BinPareto::setConfig(const Configuration & config)
{
	m_config = config;
}

QWidget * BinPareto::getView()const
{
	//return m_view->window();
}

void BinPareto::run()const
{
}

BinPAreto::~BinPareto()
{}
