#include "TestConditions.h"

TestConditions::TestConditions() : m_conditions()
{
}

TestConditions::TestConditions(QMap<Condition, Value> conditions) : m_conditions(conditions)
{
}

QString TestConditions::GetCondition(QString condition) const
{
	if (m_conditions.find(condition) != m_conditions.end())
		return m_conditions[condition];
	else
		return QString();
}
