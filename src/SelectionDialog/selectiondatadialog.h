#ifndef SELECTIONDATADIALOG_H
#define SELECTIONDATADIALOG_H

#include <QDialog>
#include <QVector>
#include "DataDirectory.h"
#include "selection.h"
#include <QListWidgetItem>


namespace Ui {
class SelectionDataDialog;
}

class SelectionDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectionDataDialog(QWidget *parent = 0);
    ~SelectionDataDialog();
private:
    DataDirectory* m_dataDirectory;
    CSelection m_selection;

    QVariantList m_selectedDates;
    QVariantList m_selectedWafers;
    QVariantList m_selectedDevices;
    QVariantList m_selectedLots;

    SFieldValueSelection m_dateField;
    SFieldValueSelection m_waferField;
    SFieldValueSelection m_deviceField;
    SFieldValueSelection m_lotField;

private:
    void clear();
    void updateWafersColum();
    void updateDevicesColum();
    void updateDatesColum();
    void updateLotsColum();

private slots:
    void on_pushButton_SelectAll_clicked();
    void on_listWidget_Dates_itemClicked(QListWidgetItem *item);
    void on_listWidget_Wafers_itemClicked(QListWidgetItem *item);
    void on_listWidget_Devices_itemClicked(QListWidgetItem *item);
    void on_listWidget_Lots_itemClicked(QListWidgetItem *item);

    void on_pushButton_Next_clicked();

private:
    void setAllDatesInWidget(QVariantList dates);
    void setAllWafersInWidget(QVariantList wafers);
    void setAllDevicesInWidget(QVariantList devices);
    void setAllLotsInWidget(QVariantList lots);

public:
    void init(DataDirectory* dataDirectory);
    CSelection getSelection() const;

private:
    Ui::SelectionDataDialog *ui;
};

#endif // SELECTIONDATADIALOG_H
