#include "grouping.h"
#include <QVector>
#include <QString>
#include <QListWidgetItem>
#include <QBoxLayout>

CGrouping::CGrouping(): QWidget()
{
    QListWidget * GrListWidg = new QListWidget();
    GrListWidg->addItem("Grouping:");
    QVector<QString> grItems{"Lot", "Wafer", "Device"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }

    QLayout * l = new QVBoxLayout();
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}
