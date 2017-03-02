
#ifndef WAFERCONFIGEDITOR_H
#define WAFERCONFIGEDITOR_H


// Qt includes
#include <QWidget>
#include <QString>
#include <QTreeWidget>
#include <QRadioButton>

#include "wm_global.h"
#include "global.h"


///////////////////////////////////////////////////////////////////////////////
namespace wm {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//! Class CWaferConfigEditor
//
class CWaferConfigEditor : public QWidget
{
public:
	// Default constructor
	CWaferConfigEditor( QWidget* parent = nullptr );
	// Destructor
	~CWaferConfigEditor();

public:
	//
	//! Own Interface
	//
	// Set wafers
	void addWafer( QString const& aLotName, QString const& sNameWafer );
	// Get selected wafers(names)
	QStringList getSelectedWafers() const;
	// Get Wafer analysis mode
	int getWaferType() const;
	// Get Bin type
	BinType getBinType() const;

protected:
	//
	//! Implementation
	//
	void setupUi();

private:
	//
	//! Content
	//
	// List of lots
	QTreeWidget*			m_pLstWafer;

	// Bin type
	QRadioButton*			m_pBtnHBin;
	QRadioButton*			m_pBtnSBin;

	// Wafer types
	QRadioButton*			m_pBtnSingleBin;
	QRadioButton*			m_pBtnIntensity;
	QRadioButton*			m_pBtnYield;
	QRadioButton*			m_pBtnMostFrequentBin;
	QRadioButton*			m_pBtnGroupAggregation;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} // namespace wm
///////////////////////////////////////////////////////////////////////////////

#endif //! WAFERCONFIGEDITOR_H
