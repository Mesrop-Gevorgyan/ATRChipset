#ifndef BinPareto_H
#define BinPareto_H


#include "ianalyser.h"

class CBinPareto :public IAnalyser
{
public:
	BinPareto();
	//set configuration
	void setConfig(const CConfiguration &);
	//set data selection
	void setData(const CSelection &);
	//shows the window of result
	QWidget *getView()const;
	//runs the analyse 
	void run()const;
	~BinPareto();
private:
	CConfiguration m_config;
	CSelection m_data;
	QWidget *m_view;
};

#endif //BinPareto_H

