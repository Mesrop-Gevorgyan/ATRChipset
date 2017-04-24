#include "grouping.h"
#include <QVector>
#include <QString>
#include <QListWidgetItem>
#include <QBoxLayout>

CGrouping::CGrouping(): QWidget(), m_items(QMap<QString,QListWidgetItem *>())
{
    QListWidget * GrListWidg = new QListWidget();
    GrListWidg->addItem("Grouping:");
    QVector<QString> grItems{"Lot", "Wafer", "Device"};

    for (int i=0; i<grItems.size(); ++i)
    {
        QListWidgetItem *listItem = new QListWidgetItem(grItems[i]);
        m_items[grItems[i]] = listItem;
        listItem->setCheckState(Qt::Unchecked);
        GrListWidg->addItem(listItem);
    }

    QLayout * l = new QVBoxLayout();
    l->addWidget(GrListWidg);
    QWidget::setLayout(l);
}


QMap<QString,QListWidgetItem *> CGrouping::getItems()const
{
    return m_items;
}
