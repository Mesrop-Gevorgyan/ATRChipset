

// Includes
#include "dialogs/wm_waferconfigeditor.h"
#include "wm_wafermodule.h"
#include "wm_global.h"

// Qt includes
#include <QApplication>
#include <QWidget>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	

	//CWaferConfigEditor dlgWaferConfig;
	//dlgWaferConfig.show();
	CConfiguration oConfig/* = dlgWaferConfig.getConfig()*/;
	oConfig.setName( "Wafer Map" );
	oConfig.setType( "wafermap" );
	oConfig.setVersion( 1 );
	oConfig.setParameter( wm::csWaferNames, QStringList(QString("wafer1")) );
	oConfig.setParameter( wm::csWaferType, int(wm::EWaferType::SingleBin) );
	oConfig.setParameter( wm::csBinType, int(EBinType::HBin) );

	CWaferModul oModul;
	oModul.setConfig( oConfig );
	//TODO set data provider
	oModul.run();	
	QWidget* pWwaferMap = oModul.getView();
	Q_ASSERT(pWwaferMap);
	pWwaferMap->show();


	return a.exec();
}