#ifndef GROUPING_H
#define GROUPING_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMap>
#include <QString>

class CGrouping: public QWidget
{
    Q_OBJECT
public:
    CGrouping();
    QMap<QString,QListWidgetItem *> getItems()const;
private:
    QMap<QString,QListWidgetItem *> m_items;
};

#endif // GROUPING_H
