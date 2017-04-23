#include "summary_bin_yield.h"
#include <QMap>
#include <QVector>

BinSummary::BinSummary()
{}

ITablePtr BinSummary::run(ITablePtr table, const CConfiguration & config)
{
    bool bLot = config.getParameter("Lot").toInt();
    bool bWafer = config.getParameter("Wafer").toInt();
    bool bDevice = config.getParameter("Device").toInt();
    bool bHbin = config.getParameter("HBin").toInt();
    bool bSbin = config.getParameter("SBin").toInt();


    CIntDataPtr bin = table->GetColumnData("Bin")->GetIntData();
    CStringDataPtr binType = table->GetColumnData("BinType")->GetStringData();
    CStringDataPtr passFail = table->GetColumnData("PassFail")->GetStringData();
    CIntDataPtr wafers = table->GetColumnData("Wafer")->GetIntData();
    CIntDataPtr lots = table->GetColumnData("Lot")->GetIntData();
    CIntDataPtr devices = table->GetColumnData("Device")->GetIntData();

    //bin_count is map where key is lot wafer device number with vector and value is bins count
    //value[0] is HBin count and value[1] is SBin count
    QMap<QVector<int>, QVector<int>> bin_count;

    for (int row_index = 0; row_index < bin->GetCount(); ++row_index)
    {
        QVector<int> current_key;
        if (bWafer)
            current_key.append(wafers->GetAt(row_index));
        if (bLot)
            current_key.append(lots->GetAt(row_index));
        if (bDevice)
            current_key.append(devices->GetAt(row_index));

        current_key.append(bin->GetAt(row_index));
        int hbin = binType->GetAt(row_index) == "HBIN";
        int sbin = binType->GetAt(row_index) == "SBIN";
        int type = passFail->GetAt(row_index) == "true";

        if (bin_count.find(current_key) == bin_count.end())
            bin_count.insert(current_key, QVector<int>{hbin, sbin, type});
        else
        {
            bin_count[current_key][0] += hbin;
            bin_count[current_key][1] += sbin;
        }
    }

    QVector<int> result_wafers;
    QVector<int> result_lots;
    QVector<int> result_devices;
    QVector<int> result_bins;
    QVector<int> result_hbin;
    QVector<int> result_sbin;
    QVector<QString> result_pass_fail;

    for (auto iter = bin_count.begin(); iter != bin_count.end(); ++iter)
    {
        QVector<int> current_key = iter.key();
        if (bWafer)
        {
            result_wafers.append(current_key[0])  ;
            current_key.pop_front();
        }
        if (bLot)
        {
            result_lots.append(current_key[0])  ;
            current_key.pop_front();
        }
        if (bDevice)
        {
            result_devices.append(current_key[0])  ;
            current_key.pop_front();
        }

        result_bins.append(current_key[0]);

        QVector<int> current_value = iter.value();
        if (bHbin)
            result_hbin.append(current_value[0]);
        if (bSbin)
            result_sbin.append(current_value[1]);

        if (current_value[2])
            result_pass_fail.append("True");
        else
            result_pass_fail.append("False");
    }

    CTable * result_table = new CTable;
    if (result_wafers.size())
    {
        IVectorPtr vec_ptr_wafer = static_cast<IVectorPtr>(new CIntData(result_wafers));
        IColumnPtr col_wafer = static_cast<IColumnPtr>(new CColumn(vec_ptr_wafer, "Wafer"));
        result_table->addColumn(col_wafer);

    }
    if (result_lots.size())
    {
        IVectorPtr vec_ptr_lot = static_cast<IVectorPtr>(new CIntData(result_lots));
        IColumnPtr col_lot = static_cast<IColumnPtr>(new CColumn(vec_ptr_lot, "Lot"));
        result_table->addColumn(col_lot);

    }
    if (result_devices.size())
    {
        IVectorPtr vec_ptr_device = static_cast<IVectorPtr>(new CIntData(result_devices));
        IColumnPtr col_device = static_cast<IColumnPtr>(new CColumn(vec_ptr_device, "Device"));
        result_table->addColumn(col_device);

    }
    if (result_bins.size())
    {
        IVectorPtr vec_ptr_bin = static_cast<IVectorPtr>(new CIntData(result_bins));
        IColumnPtr col_bin = static_cast<IColumnPtr>(new CColumn(vec_ptr_bin, "Bin"));
        result_table->addColumn(col_bin);

    }
    if (result_hbin.size())
    {
        IVectorPtr vec_ptr_hbin = static_cast<IVectorPtr>(new CIntData(result_hbin));
        IColumnPtr col_hbin = static_cast<IColumnPtr>(new CColumn(vec_ptr_hbin, "HBIN"));
        result_table->addColumn(col_hbin);

    }
    if (result_sbin.size())
    {
        IVectorPtr vec_ptr_sbin = static_cast<IVectorPtr>(new CIntData(result_sbin));
        IColumnPtr col_sbin = static_cast<IColumnPtr>(new CColumn(vec_ptr_sbin, "SBIN"));
        result_table->addColumn(col_sbin);

    }
    if (result_pass_fail.size())
    {
        IVectorPtr vec_ptr_pass_fail = static_cast<IVectorPtr>(new CStringData(result_pass_fail));
        IColumnPtr col_pass_fail = static_cast<IColumnPtr>(new CColumn(vec_ptr_pass_fail, "PassFail"));
        result_table->addColumn(col_pass_fail);
    }

    return ITablePtr(result_table);

}
