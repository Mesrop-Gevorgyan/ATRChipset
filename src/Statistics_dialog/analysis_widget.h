#ifndef ANALYSIS_WIDGET_H
#define ANALYSIS_WIDGET_H

#include <QWidget>
#include <QListWidget>

class CAnalysisWidget: public QWidget
{
public:
    CAnalysisWidget();
    QListWidget * GrListWidg;
};

#endif // ANALYSIS_WIDGET_H
