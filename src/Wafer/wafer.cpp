

#include "wafer.h"



CWafer::CWafer()
	: m_oConfig(),
	  m_pwView(nullptr)
{

}


CWafer::~CWafer()
{
	if (m_pwView != nullptr)
		delete m_pwView;
}


void CWafer::setConfig(const CConfiguration & oConfig)
{
	m_oConfig = oConfig;
}


QWidget* CWafer::getView() const
{
	return nullptr;
}


void CWafer::run()
{

}


