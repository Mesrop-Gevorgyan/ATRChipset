#include "selectiondatadialog.h"
#include "ui_selectiondatadialog.h"

SelectionDataDialog::SelectionDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectionDataDialog)
{
    ui->setupUi(this);

    initPointersToLineEdit();
}

void SelectionDataDialog::initPointersToLineEdit()
{
    ui->lineEdit_Date->insert("*");
    ui->lineEdit_Wafer->insert("*");
    ui->lineEdit_Device->insert("*");
    ui->lineEdit_Lot->insert("*");
}

void SelectionDataDialog::clearLineEdits()
{
    ui->lineEdit_Date->clear();
    ui->lineEdit_Wafer->clear();
    ui->lineEdit_Device->clear();
    ui->lineEdit_Lot->clear();

    initPointersToLineEdit();
}

void SelectionDataDialog::init(DataDirectory* dataDirectory)
{
    m_dataDirectory = dataDirectory;
 /* for testing setAllDATAInWidget functions
  *
    QVariantList testDate{"Date1","Date2","Date3","Date4","Date5","Date6","Date7" };
    QVariantList testWafer{"Wafer1","Wafer2","Wafer3","Wafer4","Wafer5","Wafer6","Wafer7" };
    QVariantList testlot{"lot1","lot2","lot3","lot4","lot5","lot6","lot7" };
    QVariantList testDevice{"Device1","Device2","Device3","Device4","Device5","Device6","Device7" };
  *
 */
    setAllDatesInWidget(/*testDate);//*/ m_dataDirectory->GetFieldValues("Date"));
    setAllWafersInWidget(/*testWafer);//*/ m_dataDirectory->GetFieldValues("Wafer"));

    setAllDevicesInWidget(/*testDevice);//*/ m_dataDirectory->GetFieldValues("Device"));
    setAllLotsInWidget(/*testlot);//*/ m_dataDirectory->GetFieldValues("Lot"));
}

SelectionDataDialog::~SelectionDataDialog()
{
    delete ui;
}

void SelectionDataDialog::setAllDatesInWidget(QVariantList dates)
{
    m_getedDates = dates;

    for (const auto date : dates)
    {
        ui->listWidget_Dates->addItem(date.toString());
    }
}

void SelectionDataDialog::setAllWafersInWidget(QVariantList wafers)
{
    m_getedWafers = wafers;

    for (const auto wafer : wafers)
    {
        ui->listWidget_Wafers->addItem(wafer.toString());
    }
}

void SelectionDataDialog::setAllDevicesInWidget(QVariantList devices)
{
   m_getedDevices = devices;

    for (const auto device : devices)
    {
        ui->listWidget_Devices->addItem(device.toString());
    }
}

void SelectionDataDialog::setAllLotsInWidget(QVariantList lots)
{
    m_getedLots = lots;

    for (const auto lot : lots)
    {
        ui->listWidget_Lots->addItem(lot.toString());
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

    m_selectedDates << item->text();

    SFieldValueSelection dateField;
    dateField.oFieldID = "Date";
    dateField.eType = ESelectionPattern::Value;
    dateField.aValues = m_selectedDates;
    m_selection.addFieldValueSelection(dateField);

    updateWafersColum();
    updateDevicesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Wafers_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);

    m_selectedWafers << item->text();

    SFieldValueSelection waferField;
    waferField.oFieldID = "Wafer";
    waferField.eType = ESelectionPattern::Value;
    waferField.aValues = m_selectedWafers;
    m_selection.addFieldValueSelection(waferField);

    updateDatesColum();
    updateDevicesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Devices_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);

    m_selectedDevices << item->text();

    SFieldValueSelection deviceField;
    deviceField.oFieldID = "Device";
    deviceField.eType = ESelectionPattern::Value;
    deviceField.aValues = m_selectedDevices;
    m_selection.addFieldValueSelection(deviceField);

    updateWafersColum();
    updateDatesColum();
    updateLotsColum();
}

void SelectionDataDialog::on_listWidget_Lots_itemClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::lightGray);

    m_selectedLots << item->text();

    SFieldValueSelection lotField;
    lotField.oFieldID = "Lot";
    lotField.eType = ESelectionPattern::Value;
    lotField.aValues = m_selectedLots;
    m_selection.addFieldValueSelection(lotField);

    updateWafersColum();
    updateDevicesColum();
    updateDatesColum();
}

void SelectionDataDialog::updateLotsColum()
{
    ui->listWidget_Lots->clear();
    setAllLotsInWidget(m_dataDirectory->GetFieldList(m_selection, "Lot"));
}

void SelectionDataDialog::updateWafersColum()
{
    ui->listWidget_Wafers->clear();
    setAllWafersInWidget(m_dataDirectory->GetFieldList(m_selection, "Wafer"));
}

void SelectionDataDialog::updateDevicesColum()
{
    ui->listWidget_Devices->clear();
    setAllDevicesInWidget(m_dataDirectory->GetFieldList(m_selection, "Device"));
}

void SelectionDataDialog::updateDatesColum()
{
    ui->listWidget_Dates->clear();
    setAllDatesInWidget(m_dataDirectory->GetFieldList(m_selection, "Date"));
}

void SelectionDataDialog::clearWidgets()
{
    ui->listWidget_Dates->clear();
    ui->listWidget_Devices->clear();
    ui->listWidget_Wafers->clear();
    ui->listWidget_Lots->clear();
}

void SelectionDataDialog::clearSelectedLists()
{
    m_selectedDates.clear();
    m_selectedWafers.clear();
    m_selectedDevices.clear();
    m_selectedLots.clear();
}

CSelection SelectionDataDialog::getSelection() const
{
    return m_selection;
}

void SelectionDataDialog::on_pushButton_Next_clicked()
{
    clearWidgets();
    setAllDatesInWidget(m_selectedDates);
    setAllWafersInWidget(m_selectedWafers);
    setAllDevicesInWidget(m_selectedDevices);
    setAllLotsInWidget(m_selectedLots);

    clearSelectedLists();
}

void SelectionDataDialog::on_pushButton_Cancel_clicked()
{
    clearWidgets();
    clearSelectedLists();
    clearLineEdits();

    init(m_dataDirectory);
}

void SelectionDataDialog::on_lineEdit_Wafer_textChanged(const QString &waferPattern)
{
    m_waferPattern = waferPattern;
}

void SelectionDataDialog::on_lineEdit_Device_textChanged(const QString &devicePattern)
{
    m_devicePattern = devicePattern;
}

void SelectionDataDialog::on_lineEdit_Lot_textChanged(const QString &lotPattern)
{
    m_lotPattern = lotPattern;
}

void SelectionDataDialog::on_lineEdit_Date_returnPressed()
{

    m_datePattern = ui->lineEdit_Date->text();
    ui->listWidget_Dates->clear();

    for (const auto date : m_getedDates)
    {
        bool b = date.toString().contains(m_datePattern);
        ui->listWidget_Dates->clear();

        if (m_datePattern == "*")
        {
            ui->listWidget_Dates->addItem(date.toString());
        }
        else if (b && date.toString().indexOf(m_datePattern) == 0)
        {
            ui->listWidget_Dates->addItem(date.toString());
        }
    }
}

void SelectionDataDialog::on_lineEdit_Wafer_returnPressed()
{
    m_waferPattern = ui->lineEdit_Wafer->text();

    for (const auto wafer : m_getedWafers)
    {
        bool b = wafer.toString().contains(m_waferPattern);
        ui->listWidget_Wafers->clear();

        if (m_waferPattern == "*")
        {
            ui->listWidget_Wafers->addItem(wafer.toString());
        }
        else if (b && wafer.toString().indexOf(m_waferPattern) == 0)
        {
            ui->listWidget_Wafers->addItem(wafer.toString());
        }
    }
}

void SelectionDataDialog::on_lineEdit_Device_returnPressed()
{
    m_devicePattern = ui->lineEdit_Device->text();

    for (const auto device : m_getedDevices)
    {
        bool b = device.toString().contains(m_devicePattern);
        ui->listWidget_Devices->clear();

        if (m_devicePattern == "*")
        {
            ui->listWidget_Devices->addItem(device.toString());
        }
        else if (b && device.toString().indexOf(m_devicePattern) == 0)
        {
            ui->listWidget_Devices->addItem(device.toString());
        }
    }
}

void SelectionDataDialog::on_lineEdit_Lot_returnPressed()
{
    m_lotPattern = ui->lineEdit_Lot->text();
    QVariantList lotPatternsList;

    for (const auto lot : m_getedLots)
    {
        bool b = lot.toString().contains(m_lotPattern);
        ui->listWidget_Lots->clear();

        if (m_lotPattern == "*")
        {
            ui->listWidget_Lots->addItem(lot.toString());
        }
        else if (b && lot.toString().indexOf(m_lotPattern) == 0)
        {
            ui->listWidget_Lots->addItem(lot.toString());
        }
    }
}
