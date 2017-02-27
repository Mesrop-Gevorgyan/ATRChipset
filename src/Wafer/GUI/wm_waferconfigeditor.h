
#ifndef WAFER_CONFIG_EDITOR_H
#define WAFER_CONFIG_EDITOR_H


// Qt includes
#include <QWidget>
#include <QListWidget>
#include <QRadioButton>

#include "global.h"
#include "wm_global.h"


//! Class CWaferConfigEditor, this is a window for parameter selection
//  Parameters used to run wafer analysis
class CWaferConfigEditor : public QWidget
{
public:
	// Default constructor
	CWaferConfigEditor(QWidget* parent = nullptr);
	// Destructor
	~CWaferConfigEditor();

	// Set wafer list s string list
	void setWafers(QStringList const& aWafer);
	// Get selected wafers(names)
	QStringList getSelectedWafers() const;
	// Get Wafer analysis mode
	WaferMode getMode() const;
	// Get Bin type
	BinType getBinType() const;

protected:
	void setupUi();

private:
	// List of wafers
	QListWidget*			m_pLstWafer;
	// Bin type
	QRadioButton*			m_pBtnHBin;
	QRadioButton*			m_pBtnSBin;
	// Wafer mode
	QRadioButton*			m_pBtnMF;
	QRadioButton*			m_pBtnYield;
};




#endif //WAFER_CONFIG_EDITOR_H
