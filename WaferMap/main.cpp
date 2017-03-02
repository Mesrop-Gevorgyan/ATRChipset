

#include "wm_wafermodule.h"


#include <QApplication>
#include <QWidget>


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	

	wm::CWaferModul oModul;
	//oModul.setConfig();
	//TODO set data provider
	oModul.run();	
	QWidget* pW = oModul.getView();
	Q_ASSERT(pW);
	pW->show();

	return a.exec();
}