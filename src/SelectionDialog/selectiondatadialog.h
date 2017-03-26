#ifndef SELECTIONDATADIALOG_H
#define SELECTIONDATADIALOG_H

#include <QDialog>
#include <QVector>
#include "DataDirectory.h"
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
    QVariantList m_dates;
    QVariantList m_wafers;
    QVariantList m_devices;
    QVariantList m_lots;

    QVector<QString> m_selectedDates;
    QVector<QString> m_selectedWafers;
    QVector<QString> m_selectedDevices;
    QVector<QString> m_selectedLots;

private:
    void setAllDatesInWidget();
    void setAllWafersInWidget();
    void setAllDevicesInWidget();
    void setAllLotsInWidget();
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

private:
    Ui::SelectionDataDialog *ui;
};

#endif // SELECTIONDATADIALOG_H
