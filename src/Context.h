#ifndef __CONTEXT__
#define __CONTEXT__

#include <QString>
#include <QVector>

//
// Context declaration
//
// This class will be used for declaring each file context (lot,wafer,device)
//

class Context
{
public:
	Context();
	Context(QString, QString, QString);
	QString GetLot() const;
	QString GetWafer() const;
	QString GetDevice() const;
private:
	QString m_lot;
	QString m_wafer;
	QString m_device;
};

#endif //__CONTEXT__