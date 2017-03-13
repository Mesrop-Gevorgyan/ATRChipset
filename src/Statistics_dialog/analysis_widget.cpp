#include "analysis_widget.h"
#include <QVector>
#include <QString>
#include <QListWidgetItem>
#include <QBoxLayout>

CAnalysisWidget::CAnalysisWidget() :QWidget()
{
    QListWidget * GrListWidg = new QListWidget();
    QVector<QString> grItems{"Statistics", "Bin Pareto", "Histogram", "Wafer"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        GrListWidg->addItem(listItem);
    }

    QLayout * l = new QVBoxLayout();
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}
