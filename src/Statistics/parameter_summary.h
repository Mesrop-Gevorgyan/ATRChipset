#ifndef PARAMETER_SUMMARY_H
#define PARAMETER_SUMMARY_H

#include <QVector>

class CParameterSummary
{
public:
    CParameterSummary();
    void run(const QVector<double> & vec);
    double get_min()const;
    double get_max()const;
    double get_median()const;
    double get_average()const;
    double get_standard_deviation()const;
    double get_skewness()const;
    double get_kurtosis()const;
private:
    double m_min;
    double m_max;
    double m_median;
    double m_average;
    double m_standard_deviation;
    double m_skewness;
    double m_kurtosis;

};

#endif // PARAMETER_SUMMARY_H
