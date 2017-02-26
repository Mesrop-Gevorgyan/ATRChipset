#include "config_pages.h"

ConfigPages::ConfigPages(): QWidget()
{
    QVector<QString> analysis{"Statistics", "Bin Pareto", "Histogram", "Wafer"};

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    gridlayout = new QGridLayout();

    QVBoxLayout * analysisLayout = new QVBoxLayout();
    QLabel * label1 = new QLabel("Analysis");
    label1->setFont(font);
    label1->setStyleSheet("QLabel {color : #00009c; }");
    analysisLayout->addWidget(label1);

    font.setPointSize(14);

    for (int i=0; i < analysis.size(); ++i)
    {
        QPushButton * button = new QPushButton(analysis[i]);
        button->setFont(font);
        button->setStyleSheet("QPushButton {color : #007fff; }");
        analysisLayout->addWidget(button);
    }
    gridlayout->addLayout(analysisLayout,0,0);

    QWidget::setLayout(gridlayout);

    QVector<QString> grouping_items{"Lot", "Wafer", "Device"};

    GroupingType = new QHBoxLayout();
    TypeLayout = new QVBoxLayout();
    QVBoxLayout * groupingLayout = new QVBoxLayout();
    GroupingType->addLayout(TypeLayout);
    QLabel * gr_label = new QLabel("Grouping:");
    gr_label->setFont(font);
    gr_label->setStyleSheet("QLabel {color : #00009c; }");
    groupingLayout->addWidget(gr_label);

    font.setPointSize(14);

    for (int i=0; i < grouping_items.size(); ++i)
    {
        QCheckBox * cb = new QCheckBox(grouping_items[i]);
        cb->setFont(font);
        cb->setStyleSheet("QCheckBox {color : #007fff; }");
        groupingLayout->addWidget(cb);
    }
    GroupingType->addLayout(groupingLayout);
    gridlayout->addLayout(GroupingType,5,15,10,20);

    QPushButton * next = new QPushButton("Next");
    next->setFont(font);
    next->setStyleSheet("QPushButton {color : #007fff; }");
    gridlayout->addWidget(next,30,30);

    QWidget::setLayout(gridlayout);
}
