

// Includes
#include "dialogs/wm_waferconfigeditor.h"
#include "wm_wafermodule.h"

// Qt includes
#include <QApplication>
#include <QWidget>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	

	//CWaferConfigEditor dlgWaferConfig;
	//dlgWaferConfig.show();
	//CConfiguration oConfig = dlgWaferConfig.getConfig();

	CWaferModul oModul;
	//oModul.setConfig( oConfig );
	//TODO set data provider
	oModul.run();	
	QWidget* pWwaferMap = oModul.getView();
	Q_ASSERT(pWwaferMap);
	pWwaferMap->show();


	return a.exec();
}