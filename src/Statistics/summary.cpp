#include "summary.h"
#include <stdexcept>
#include "IFieldData.h"
#include "IFieldCollection.h"

#include "table.h"
#include "global.h"

#include <QVector>

CSummary::CSummary()
{}

void CSummary::run()const
{
    //FieldList fileds;
    /*if (!m_config.isContained("summary"))
        throw std::logic_error("No any parameter for summary");

    QString parameter = m_config.getParameter("summary").toString();
    QStringList ParamList = QStringList(parameter);
    IFieldCollectionPtr oFieldCollectionPtr = m_data_provider.GetData(ParamList);*/
    /*IFieldCollectionPtr oFieldCollectionPtr;
    IFieldCollection * oFieldCollection = oFieldCollectionPtr.data();

    int iFieldCount = oFieldCollection->GetCount();
    for (int i=0; i<iFieldCount; ++i)
    {
        IFieldData * summaryData = oFieldCollection->GetFieldData(oFieldCollection->GetField(i));
        CDoubleData summaryDoubleData = summaryData->GetDoubleData();
        CStatistics my_sum;
        QMap<EFunction, QVariant> m;
//will be changed
        m[EFunction::Max] = QVariant(0);
        m[EFunction::Min] = QVariant(0);
        m[EFunction::Median] = QVariant(0);
        m[EFunction::Average] = QVariant(0);
        m[EFunction::StandardDeviation] = QVariant(0);
        m[EFunction::Skewness] = QVariant(0);
        m[EFunction::Kurtosis] = QVariant(0);

        QMap<EFunction, double> result = my_sum.run(summaryDoubleData, m);
    }*/

    //ITablePtr* table = m_data_provider->GetData("Parameter");
    QVector<QVector<QVariant>> result_table;
    result_table.append(QVector<QVariant>(1,"Parameter"));
    result_table.append(QVector<QVariant>(1,"Max"));
    result_table.append(QVector<QVariant>(1,"Min"));
    result_table.append(QVector<QVariant>(1,"Median"));
    result_table.append(QVector<QVariant>(1,"Average"));
    result_table.append(QVector<QVariant>(1,"StandardDeviation"));
    result_table.append(QVector<QVariant>(1,"Skewness"));
    result_table.append(QVector<QVariant>(1,"Kurtosis"));

    if (m_config.getType() == "Parameter Summary")
    {
        QMap<EFunction, QVariant> m;

        /*ITable * result_table;
        result_table->append(CColumn(CStringData(), "Parameter"));*/

        if (m_config.getParameter("Max").Bool)
        {
            m[EFunction::Max] = QVariant(0);
            //result_table->.append(CColumn(CDoubleData(), "Max"));
        }
        if (m_config.getParameter("Min").Bool)
        {
            m[EFunction::Min] = QVariant(0);
            //result_table->.append(CColumn(CDoubleData(), "Min"));
        }
        if (m_config.getParameter("Median").Bool)
        {
            m[EFunction::Median] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Median"));
        }
        if (m_config.getParameter("Average").Bool)
        {
            m[EFunction::Average] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Average"));
        }
        if (m_config.getParameter("StandardDeviation").Bool)
        {
            m[EFunction::StandardDeviation] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "StandardDeviation"));
        }
        if (m_config.getParameter("Skewness").Bool)
        {
            m[EFunction::Skewness] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Skewness"));
        }
        if (m_config.getParameter("Kurtosis").Bool)
        {
            m[EFunction::Kurtosis] = QVariant(0);
            //result_table->append(CColumn(CDoubleData(), "Kurtosis"));
        }

        FieldList fieldList1;
        fieldList1.append("Parameter");
        fieldList1.append("TestNumber");
        fieldList1.append("ParameterUnit");
        //ITablePtr table1 = m_data_provider->GetData(fieldList1);
        ITablePtr table1;


        FieldList fieldList2;
        fieldList2.append("DieX");
        fieldList2.append("DieY");
        fieldList2.append("TestNumber");
        fieldList2.append("Last");
        fieldList2.append("TestPass");
        //ITablePtr table2 = m_data_provider->GetData(fieldList2);
        ITablePtr table2;


        CStringDataPtr param_name = table1->GetColumnData("Parameter")->GetStringData();
        if (param_name->GetCount())
        {
            CIntDataPtr test_number1 = table1->GetColumnData("TestNumber")->GetIntData();
            CIntDataPtr test_number2 = table1->GetColumnData("TestNumber")->GetIntData();
            CDoubleDataPtr test_value = table2->GetColumnData("Last")->GetDoubleData();

            for (int param_index=0; param_index<param_name->GetCount(); ++param_index)
            {
                int current_test_num = test_number1->GetValue(param_index).Int;
                QVector<double> vec;
                for (int test_index2=0; test_index2<test_number2->GetCount(); ++test_index2)
                {
                    if (test_number2->GetValue(test_index2) == current_test_num)
                    {
                        vec.push_back(test_value->GetValue(test_index2).Double);
                    }
                }

                result_table[0].append(param_name->GetValue(param_index).String);

                CDoubleData dData(vec);
                IVector & ivec = dData;
                CStatistics sta;
                QMap<EFunction, double> result = sta.run(ivec, m);

                for (auto result_iter=result.begin(); result_iter != result.end(); ++result_iter)
                {
                    switch(result_iter.key())
                    {
                        case EFunction::Max:
                        {
                            result_table[1].append(result_iter.value());
                            break;
                        }
                        case EFunction::Min:
                        {
                            result_table[2].append(result_iter.value());
                            break;
                        }
                        case EFunction::Median:
                        {
                            result_table[3].append(result_iter.value());
                            break;
                        }
                        case EFunction::Average:
                        {
                            result_table[4].append(result_iter.value());
                            break;
                        }
                        case EFunction::StandardDeviation:
                        {
                            result_table[5].append(result_iter.value());
                            break;
                        }
                        case EFunction::Skewness:
                        {
                            result_table[6].append(result_iter.value());
                            break;
                        }
                        case EFunction::Kurtosis:
                        {
                            result_table[7].append(result_iter.value());
                            break;
                        }
                    }
                }
            }

        }

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



