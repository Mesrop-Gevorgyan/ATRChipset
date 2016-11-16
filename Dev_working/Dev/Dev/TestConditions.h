#ifndef __TESTCONDITIONS__
#define  __TESTCONDITIONS__

#include <QMap>

typedef QString Condition;
typedef QString Value;

class TestConditions
{
public:
	TestConditions();
	TestConditions(QMap<Condition, Value>);
	QString GetCondition(QString) const;
private:
	QMap<Condition,Value> m_conditions;
};

#endif // __TESTCONDITIONS__