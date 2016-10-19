#ifndef BinPareto_H
#define BinPareto_H

class BinPareto :public IAnalyser
{
public:
	BinPareto();
	void setConfig(const Configuration &);
	void setData(const DataSelection &);
	QWidget *getView()const;
	void run()const;
	~BinPareto();
private:
	Configuration m_config;
	DataSelection m_data;
	QWidget *m_view;
};

#endif //BinPareto_H
