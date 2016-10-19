#ifndef IANALYSER_H
#define IANALYSER_H

#include <QWidget>

class IAnalyser
{
public:
	//set configuration
	virtual void setConfig(const Configuration &) = 0;
	//set data selection
	virtual void setData(const DataSelection &) = 0;
	//shows the result of analyse
	QWidget *getView()const = 0;
	//runs the analyse 
	void run()const = 0;
};

#endif //IANALYSER_H
