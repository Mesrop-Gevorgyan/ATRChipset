#include "statistic_dialog.h"

Statisticsdialog::Statisticsdialog(): ConfigPages()
{
    QVector<QString> statistics_types{"   Yield", "   Parameter Summary", "   Bin Summary"};

    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    //QVBoxLayout * typeLayout = new QVBoxLayout();
    typeLayout = new QVBoxLayout();
    typeFuncLayout = new QVBoxLayout();
    QHBoxLayout * analysisLayout = new QHBoxLayout();
    QLabel * label1 = new QLabel("Type:");
    label1->setFont(font);
    label1->setStyleSheet("QLabel {color : #00009c; }");
    analysisLayout->addWidget(label1);

    QComboBox * type_combo = new QComboBox();
    connect(type_combo, SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboBox_currentIndexChanged(const QString &)));
    for (int i = 0; i < statistics_types.size(); ++i)
        type_combo->addItem(statistics_types[i]);

    analysisLayout->addWidget(type_combo);
    typeLayout->addLayout(analysisLayout);
    typeLayout->addLayout(typeFuncLayout);

     TypeLayout->addLayout(typeLayout);
    //ConfigPages::gridlayout->addLayout(typeLayout,2,2);
    //ConfigPages::gridlayout->addLayout(typeFuncLayout,3,2);
}

void Statisticsdialog::on_comboBox_currentIndexChanged(const QString & arg1)
{
    QVector<QString> choices;
    if (arg1 == "   Yield" || arg1 == "   Bin Summary")
    {
        QVector<QString> current_choices;
        current_choices.push_back("HBIN");
        current_choices.push_back("SBIN");
        choices = current_choices;
    }
    else
    {
        QVector<QString> current_choices;
        current_choices.push_back("Min");
        current_choices.push_back("Max");
        current_choices.push_back("Median");
        current_choices.push_back("Average");
        current_choices.push_back("Standard deviation");
        current_choices.push_back("Skewness");
        current_choices.push_back("Kurtosis");
        choices = current_choices;
    }

    //remove all layout items
    QLayoutItem *child;
    while ((child = typeFuncLayout->takeAt(0)) != 0)  {
        delete child->widget();
    }

    QFont font;
    font.setPointSize(16);
    font.setBold(false);
    for (int i=0; i<choices.size(); ++i)
    {
        QCheckBox * c_b = new QCheckBox(choices[i],this);
        c_b->setFont(font);
        c_b->setStyleSheet("QCheckBox {color : #007fff; }");
        typeFuncLayout->addWidget(c_b);
    }
}
