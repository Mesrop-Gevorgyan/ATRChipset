#ifndef CONFIG_PAGES_H
#define CONFIG_PAGES_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>

class ConfigPages: public QWidget
{
public:
    ConfigPages();
protected:
    QGridLayout * gridlayout;
    QHBoxLayout * GroupingType;
    QVBoxLayout * TypeLayout;
};

#endif // CONFIG_PAGES_H
