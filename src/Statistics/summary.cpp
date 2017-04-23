#include "summary.h"
#include <stdexcept>
#include "IFieldData.h"
#include "IFieldCollection.h"

#include "table.h"
#include "global.h"
#include "statistics_table_model.h"
#include <QTableView>
#include "summary_bin_yield.h"

#include <QVector>

#include <QVariant>

CSummary::CSummary(): m_result_table(Q_NULLPTR)
{}

void CSummary::run()const
{
    QVector<QString> param_val;
    QVector<double> max_val;
    QVector<double> min_val;
    QVector<double> median_val;
    QVector<double> average_val;
    QVector<double> stanadarddeviation_val;
    QVector<double> skewness_val;
    QVector<double> kurtosis_val;



    if (m_config.getType() == "Parameter Summary")
    {
        QMap<EFunction, QVariant> m;

        /*ITable * result_table;
        result_table->append(CColumn(CStringData(), "Parameter"));*/

        auto n_s = m_config.getParameter("Max").LastType;
        if (m_config.getParameter("Max").toInt())
        {
            m[EFunction::Max] = QVariant(0);
            //result_table->.append(CColumn(CDoubleData(), "Max"));
        }
        if (m_config.getParameter("Min").toInt())
        {
            m[EFunction::Min] = QVariant(0);
            //result_table->.append(CColumn(CDoubleData(), "Min"));
        }
        if (m_config.getParameter("Median").toInt())
        {
            m[EFunction::Median] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Median"));
        }
        if (m_config.getParameter("Average").toInt())
        {
            m[EFunction::Average] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Average"));
        }
        if (m_config.getParameter("StandardDeviation").toInt())
        {
            m[EFunction::StandardDeviation] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "StandardDeviation"));
        }
        if (m_config.getParameter("Skewness").toInt())
        {
            m[EFunction::Skewness] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Skewness"));
        }
        if (m_config.getParameter("Kurtosis").toInt())
        {
            m[EFunction::Kurtosis] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Kurtosis"));
        }

        FieldList fieldList1;
        fieldList1.append("Parameter");
        fieldList1.append("TestNumber");
        fieldList1.append("ParameterUnit");
        //ITablePtr table1 = m_data_provider->GetData(fieldList1);
        //ITablePtr table1;

        FieldList fieldList2;
        fieldList2.append("DieX");
        fieldList2.append("DieY");
        fieldList2.append("TestNumber");
        fieldList2.append("Last");
        fieldList2.append("TestPass");
        //ITablePtr table2 = m_data_provider->GetData(fieldList2);
        ITablePtr table2;

/*-------------------------  hard coded table */
        CTable * tb1 = new CTable;
        QVector<QString> vec_param_name;
        vec_param_name.append("Param_1");
        vec_param_name.append("Param_2");
        vec_param_name.append("Param_3");
        vec_param_name.append("Param_4");
        IVectorPtr vec_str_param_name = static_cast<IVectorPtr>(new CStringData(vec_param_name));
        IColumnPtr param_col = static_cast<IColumnPtr>(new CColumn(vec_str_param_name, "Parameter"));
        tb1->addColumn(param_col);
        QVector<int> vec_test_num;
        vec_test_num.append(1);
        vec_test_num.append(2);
        vec_test_num.append(3);
        vec_test_num.append(4);
        IVectorPtr vec__test_num = static_cast<IVectorPtr>(new CIntData(vec_test_num));
        IColumnPtr test_num_col1 = static_cast<IColumnPtr>(new CColumn(vec__test_num, "TestNumber"));
        tb1->addColumn(test_num_col1);
        ITablePtr table1(tb1);
        //table1->GetColumnData("Parameter")->GetStringData()->GetAt(0);
        //m_result_table->GetColumnData("Parameter")->GetStringData()->GetAt(0);

        CTable * tb2 = new CTable;
        QVector<int> vec_test_num2;
        vec_test_num2.append(1);
        vec_test_num2.append(1);
        vec_test_num2.append(1);
        vec_test_num2.append(1);
        vec_test_num2.append(1);
        vec_test_num2.append(2);
        vec_test_num2.append(2);
        vec_test_num2.append(2);
        vec_test_num2.append(2);
        vec_test_num2.append(2);
        IVectorPtr vec__test_num2 = static_cast<IVectorPtr>(new CIntData(vec_test_num2));
        IColumnPtr test_num_col2 = static_cast<IColumnPtr>(new CColumn(vec__test_num2, "TestNumber"));
        tb2->addColumn(test_num_col2);
        QVector<double> vec_val;
        vec_val.append(0.567);
        vec_val.append(0.58);
        vec_val.append(0.367);
        vec_val.append(0.47);
        vec_val.append(0.73);
        vec_val.append(1.567);
        vec_val.append(2.58);
        vec_val.append(3.67);
        vec_val.append(2.67);
        vec_val.append(6.03);
        IVectorPtr vec__val = static_cast<IVectorPtr>(new CDoubleData(vec_val));
        IColumnPtr val_col = static_cast<IColumnPtr>(new CColumn(vec__val, "Last"));
        tb2->addColumn(val_col);
        table2 = static_cast<ITablePtr>(tb2);
        /*m_result_table = ITablePtr(table);
        view_results(m_result_table);*/

/*-------------------------*/



        CStringDataPtr param_name = table1->GetColumnData("Parameter")->GetStringData();
        if (param_name->GetCount())
        {
            CIntDataPtr test_number1 = table1->GetColumnData("TestNumber")->GetIntData();
            CIntDataPtr test_number2 = table2->GetColumnData("TestNumber")->GetIntData();
            CDoubleDataPtr test_value = table2->GetColumnData("Last")->GetDoubleData();

            for (int param_index=0; param_index<param_name->GetCount(); ++param_index)
            {
                int current_test_num = test_number1->GetAt(param_index);//.Int;
                QVector<double> current_vec;
                for (int test_index2=0; test_index2<test_number2->GetCount(); ++test_index2)
                {
                    if (test_number2->GetAt(test_index2) == current_test_num)
                    {
                        current_vec.push_back(test_value->GetAt(test_index2));
                    }
                }



                if (current_vec.size())
                {
                    param_val.append(param_name->GetAt(param_index));
                    CDoubleData dData(current_vec);

                    IVector & ivec = dData;
                    CStatistics sta;
                    QMap<EFunction, double> result = sta.run(ivec, m);

                    for (auto result_iter=result.begin(); result_iter != result.end(); ++result_iter)
                    {
                        switch(result_iter.key())
                        {
                            case EFunction::Max:
                            {
                                max_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::Min:
                            {
                                min_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::Median:
                            {
                                median_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::Average:
                            {
                                average_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::StandardDeviation:
                            {
                                stanadarddeviation_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::Skewness:
                            {
                                skewness_val.append(result_iter.value());
                                break;
                            }
                            case EFunction::Kurtosis:
                            {
                                kurtosis_val.append(result_iter.value());
                                break;
                            }
                        }
                    }
                }
            }
            /*CTable * param_sum_result = new CTable;
            for (int i=0; i < result_table.size(); ++i)
            {
                if (result_table[i].size() > 1)
                {
                    QString col_name = QString(result_table[i][0].String);
                    if (i==0)
                    {
                        QVector<QString> result_col_vec;
                        for (int row_index=1; row_index < result_table[i].size(); ++row_index)
                        {
                              result_col_vec.append(QString(result_table[i][row_index].String));
                        }
                        IVectorPtr result__col_vec = static_cast<IVectorPtr>(new CStringData(result_col_vec));
                        IColumnPtr result_col = static_cast<IColumnPtr>(new CColumn(result__col_vec, col_name));
                        param_sum_result->addColumn(result_col);
                    }
                    else
                    {
                        QVector<double> result_col_vec;
                        for (int row_index=1; row_index < result_table[i].size(); ++row_index)
                        {
                              result_col_vec.append(result_table[i][row_index].Double);
                        }
                        IVectorPtr result__col_vec = static_cast<IVectorPtr>(new CDoubleData(result_col_vec));
                        IColumnPtr result_col = static_cast<IColumnPtr>(new CColumn(result__col_vec, col_name));
                        param_sum_result->addColumn(result_col);

                    }
                }
            }*/

            CTable * param_sum_result = new CTable;
            if (param_val.size())
            {
                IVectorPtr reslut_param_val = static_cast<IVectorPtr>(new CStringData(param_val));
                IColumnPtr result_param_col = static_cast<IColumnPtr>(new CColumn(reslut_param_val, "Parameter"));
                param_sum_result->addColumn(result_param_col);
            }
            if (max_val.size())
            {
                IVectorPtr reslut_max_val = static_cast<IVectorPtr>(new CDoubleData(max_val));
                IColumnPtr result_max_col = static_cast<IColumnPtr>(new CColumn(reslut_max_val, "Max"));
                param_sum_result->addColumn(result_max_col);
            }
            if (min_val.size())
            {
                IVectorPtr reslut_min_val = static_cast<IVectorPtr>(new CDoubleData(min_val));
                IColumnPtr result_min_col = static_cast<IColumnPtr>(new CColumn(reslut_min_val, "Min"));
                param_sum_result->addColumn(result_min_col);
            }
            if (median_val.size())
            {
                IVectorPtr reslut_median_val = static_cast<IVectorPtr>(new CDoubleData(median_val));
                IColumnPtr result_median_col = static_cast<IColumnPtr>(new CColumn(reslut_median_val, "Median"));
                param_sum_result->addColumn(result_median_col);
            }
            if (average_val.size())
            {
                IVectorPtr reslut_average_val = static_cast<IVectorPtr>(new CDoubleData(average_val));
                IColumnPtr result_average_col = static_cast<IColumnPtr>(new CColumn(reslut_average_val, "Avg"));
                param_sum_result->addColumn(result_average_col);
            }
            if (stanadarddeviation_val.size())
            {
                IVectorPtr reslut_st_val = static_cast<IVectorPtr>(new CDoubleData(stanadarddeviation_val));
                IColumnPtr result_st_col = static_cast<IColumnPtr>(new CColumn(reslut_st_val, "StDev"));
                param_sum_result->addColumn(result_st_col);
            }
            if (skewness_val.size())
            {
                IVectorPtr reslut_skewness_val = static_cast<IVectorPtr>(new CDoubleData(skewness_val));
                IColumnPtr result_skewness_col = static_cast<IColumnPtr>(new CColumn(reslut_skewness_val, "Skew"));
                param_sum_result->addColumn(result_skewness_col);
            }
            if (kurtosis_val.size())
            {
                IVectorPtr reslut_kurtosis_val = static_cast<IVectorPtr>(new CDoubleData(kurtosis_val));
                IColumnPtr result_kurtosis_col = static_cast<IColumnPtr>(new CColumn(reslut_kurtosis_val, "Kurt"));
                param_sum_result->addColumn(result_kurtosis_col);
            }

            m_result_table = ITablePtr(param_sum_result);
            //view_results(m_result_table);
        }

    }
    else
        if(m_config.getType() == "Bin/Yield")
        {
            FieldList fieldList;
            fieldList.append("Bin");
            fieldList.append("BinType");
            fieldList.append("BinName");
            fieldList.append("PassFail");
            //ITablePtr table = m_data_provider->GetData(fieldList);
            ITablePtr table;

            /*-------------------------  hard coded table */

            CTable * tb = new CTable;
            QVector<int> vec_1;
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(1);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(2);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            vec_1.append(3);
            IVectorPtr vec_ptr_1 = static_cast<IVectorPtr>(new CIntData(vec_1));
            IColumnPtr col_1 = static_cast<IColumnPtr>(new CColumn(vec_ptr_1, "Wafer"));
            tb->addColumn(col_1);

            QVector<int> vec_2;
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(3);
            vec_2.append(3);
            vec_2.append(3);
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(3);
            vec_2.append(3);
            vec_2.append(3);
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(1);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(2);
            vec_2.append(3);
            vec_2.append(3);
            vec_2.append(3);
            IVectorPtr vec_ptr_2 = static_cast<IVectorPtr>(new CIntData(vec_2));
            IColumnPtr col_2 = static_cast<IColumnPtr>(new CColumn(vec_ptr_2, "Lot"));
            tb->addColumn(col_2);

            QVector<int> vec_3;
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            vec_3.append(1);
            vec_3.append(2);
            vec_3.append(3);
            IVectorPtr vec_ptr_3 = static_cast<IVectorPtr>(new CIntData(vec_3));
            IColumnPtr col_3 = static_cast<IColumnPtr>(new CColumn(vec_ptr_3, "Device"));
            tb->addColumn(col_3);

            QVector<int> vec_4;
            vec_4.append(0);
            vec_4.append(2);
            vec_4.append(3);
            vec_4.append(1);
            vec_4.append(0);
            vec_4.append(0);
            vec_4.append(0);
            vec_4.append(3);
            vec_4.append(2);
            vec_4.append(3);
            vec_4.append(2);
            vec_4.append(1);
            vec_4.append(0);
            vec_4.append(3);
            vec_4.append(1);
            vec_4.append(3);
            vec_4.append(0);
            vec_4.append(3);
            vec_4.append(3);
            vec_4.append(1);
            vec_4.append(1);
            vec_4.append(2);
            vec_4.append(0);
            vec_4.append(2);
            vec_4.append(2);
            vec_4.append(0);
            vec_4.append(1);
            IVectorPtr vec_ptr_4 = static_cast<IVectorPtr>(new CIntData(vec_4));
            IColumnPtr col_4 = static_cast<IColumnPtr>(new CColumn(vec_ptr_4, "Bin"));
            tb->addColumn(col_4);

            QVector<QString> vec_6;
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            vec_6.append("SBIN");
            vec_6.append("HBIN");
            IVectorPtr vec_ptr_6 = static_cast<IVectorPtr>(new CStringData(vec_6));
            IColumnPtr col_6 = static_cast<IColumnPtr>(new CColumn(vec_ptr_6, "BinType"));
            tb->addColumn(col_6);

            QVector<QString> vec_5;
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("false");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("true");
            vec_5.append("false");
            IVectorPtr vec_ptr_5 = static_cast<IVectorPtr>(new CStringData(vec_5));
            IColumnPtr col_5 = static_cast<IColumnPtr>(new CColumn(vec_ptr_5, "PassFail"));
            tb->addColumn(col_5);

            table = static_cast<ITablePtr>(tb);
            //m_result_table = ITablePtr(table);


            /* ------------------------- */

            BinSummary b;
            m_result_table = ITablePtr(b.run(table, m_config));
        }
}


void CSummary::init(DataProvider* d_provider,const CConfiguration & config)
{
    m_config = config;
    m_data_provider = d_provider;
}

CConfiguration CSummary::getConfig()const
{
    return m_config;
}

const IDataProvider* CSummary::getProvider()const
{
    return  m_data_provider;
}


/*void CSummary::view_results(ITablePtr table) const
{
    StatisticsTable * tableModel = new StatisticsTable(table);
    QTableView * tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->show();
}*/

void CSummary::view_results() const
{
    ITablePtr table(m_result_table);
    StatisticsTable * tableModel = new StatisticsTable(table);
    QTableView * tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->show();
}
