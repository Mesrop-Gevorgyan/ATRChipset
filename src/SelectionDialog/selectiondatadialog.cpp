#include "selectiondatadialog.h"
#include "ui_selectiondatadialog.h"

SelectionDataDialog::SelectionDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectionDataDialog)
{
    ui->setupUi(this);
}

SelectionDataDialog::~SelectionDataDialog()
{
    delete ui;
}

void SelectionDataDialog::setAllDatesInWidget()
{
    m_dates = m_dataDirectory->getFieldValues("Date");
    for (const auto date : m_dates)
    {
        ui->listWidget_Dates->addItem(date.toString("yyyy.MM.dd"));
    }
}

void SelectionDataDialog::setAllWafersInWidget()
{
    m_wafers = m_dataDirectory->getFieldValues("Wafer");
    for (const auto wafer : m_wafers)
    {
        ui->listWidget_Wafers->addItem(wafer);
    }
}

void SelectionDataDialog::setAllDevicesInWidget()
{
    m_devices = m_dataDirectory->getFieldValues("Device");
    for (const auto device : m_devices)
    {
        ui->listWidget_Devices->addItem(device);
    }
}

void SelectionDataDialog::setAllLotsInWidget()
{
    m_lots = m_dataDirectory->getFieldValues("Lot");
    for (const auto lot : m_lots)
    {
        ui->listWidget_Lots->addItem(lot);
    }
}

void SelectionDataDialog::on_pushButton_SelectAll_clicked()
{
    ui->listWidget_Dates->selectAll();
    ui->listWidget_Wafers->selectAll();
    ui->listWidget_Devices->selectAll();
    ui->listWidget_Lots->selectAll();
}


void SelectionDataDialog::on_listWidget_Dates_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);
    m_selectedDates.push_back(item->text());
    updateWafersColum();
    updateDevicesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Wafers_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);
    m_selectedWafers.push_back(item->text());
    updateDatesColum();
    updateDevicesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Devices_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);
    m_selectedDevices.push_back(item->text());
    updateWafersColum();
    updateDatesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Lots_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);
    m_selectedLots.push_back(item->text());
    updateWafersColum();
    updateDevicesColum();
    updateDatesColum();
}

void SelectionDataDialog::updateLotsColum()
{

}

void SelectionDataDialog::updateWafersColum()
{

}

void SelectionDataDialog::updateDevicesColum()
{

}

void SelectionDataDialog::updateDatesColum()
{

}



void SelectionDataDialog::clear()
{
    m_selectedDates.clear();
    m_selectedWafers.clear();
    m_selectedDevices.clear();
    m_selectedLots.clear();
}
