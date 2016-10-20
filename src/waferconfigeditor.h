

#ifndef WAFER_CONFIG_EDITOR_H
#define WAFER_CONFIG_EDITOR_H


#include <QtGui\QWidget>
#include <QtGui\QListWidget>
#include <QtGui\QRadioButton>



class CWaferConfigEditor : public QWidget
{
public:
	CWaferConfigEditor(QWidget* parent = nullptr);
	~CWaferConfigEditor();

protected:
	void setupUi();

private:
	// List of wafers
	QListWidget*			m_pWafers;
	// Bin type
	QRadioButton*			m_pHBin;
	QRadioButton*			m_pSBin;
	// Wafer mode
	QRadioButton*			m_pMF;
	QRadioButton*			m_pYield;
};




#endif //WAFER_CONFIG_EDITOR_H

