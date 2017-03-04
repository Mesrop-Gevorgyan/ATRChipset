
#ifndef WAFERCONFIGEDITOR_H
#define WAFERCONFIGEDITOR_H


// Includes
#include "global.h"
#include "configuration.h"

// Qt includes
#include <QWidget>
#include <QString>
#include <QTreeWidget>
#include <QRadioButton>


///////////////////////////////////////////////////////////////////////////////
//
//! Class CWaferConfigEditor
//
class Q_DECL_EXPORT CWaferConfigEditor : public QWidget
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
	// Add wafers
	void addWafer( QString const& aLotName, QString const& sNameWafer );
	// Get wafer configuration
	CConfiguration getConfig() const;

protected:
	//
	//! Implementation
	//
	void setupUi();
	// Get selected wafers(names)
	QStringList getSelectedWafers() const;
	// Get Wafer analysis mode
	int getWaferType() const;
	// Get Bin type
	EBinType getBinType() const;

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
	QRadioButton*			m_pBtnYield;
	QRadioButton*			m_pBtnMostFrequentBin;
	QRadioButton*			m_pBtnGroupAggregation;
};
///////////////////////////////////////////////////////////////////////////////

#endif //! WAFERCONFIGEDITOR_H
