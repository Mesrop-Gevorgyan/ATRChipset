#ifndef __CONTEXT__
#define __CONTEXT__

#include <QString>
#include <QMap>

typedef QString Field;
typedef QString Value;


class Context
{
public:
	Context();
	Context(QMap<Field, Value>);
	QString GetLot() const;
	QString GetWafer() const;
	QString GetDevice() const;
	QString GetTechnology() const;
	QString GetTestProgram() const;
	QString GetStep() const;
	QString GetDate() const;
private:
	QMap <Field,Value> m_context;
};

#endif //__CONTEXT__