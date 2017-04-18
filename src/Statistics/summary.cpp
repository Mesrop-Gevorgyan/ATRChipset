#include "summary.h"
#include <stdexcept>
#include "IFieldData.h"
#include "IFieldCollection.h"

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


}


void CSummary::init(const IDataProvider* d_provider,const CConfiguration & config)
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



