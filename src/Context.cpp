#include "Context.h"

Context::Context() : m_context() {}

Context::Context(QMap<QString,QString> context)  : m_context(context) {}

QString Context::GetLot() const
{
	if (m_context.find("Lot") != m_context.end())
		return m_context["Lot"];
	else
		return QString();
}

QString Context::GetWafer() const
{
	if (m_context.find("Wafer") != m_context.end())
		return m_context["Wafer"];
	else
		return QString();
}

QString Context::GetDevice() const
{
	if (m_context.find("Device") != m_context.end())
		return m_context["Device"];
	else
		return QString();
}

QString Context::GetTechnology() const
{
	if (m_context.find("Technology") != m_context.end())
		return m_context["Technology"];
	else
		return QString();
}

QString Context::GetTestProgram() const
{
	if (m_context.find("TestProgram") != m_context.end())
		return m_context["TestProgram"];
	else
		return QString();
}

QString Context::GetStep() const
{
	if (m_context.find("Step") != m_context.end())
		return m_context["Step"];
	else
		return QString();
}

QString Context::GetDate() const
{
	if (m_context.find("Date") != m_context.end())
		return m_context["Date"];
	else
		return QString();
}
