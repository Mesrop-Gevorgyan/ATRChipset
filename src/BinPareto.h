#ifndef BinPareto_H
#define BinPareto_H

class CBinPareto :public IAnalyser
{
public:
	BinPareto();
	//set configuration
	void setConfig(const Configuration &);
	//set data selection
	void setData(const DataSelection &);
	//shows the window of result
	QWidget *getView()const;
	//runs the analyse 
	void run()const;
	~BinPareto();
private:
	Configuration m_config;
	DataSelection m_data;
	QWidget *m_view;
};

#endif //BinPareto_H

