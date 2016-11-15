#include "dialog.h"
#include "ui_dialog.h"
#include <QCheckBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel {color : #007fff; }");
    QFont font = ui->label->font();
    font.setPointSize(24);
    font.setBold(true);
    ui->label->setFont(font);

     font.setPointSize(16);
     font.setBold(true);

     ui->label_2->setFont(font);
     ui->label_2->setStyleSheet("QLabel {color : #00009c; }");

     font.setBold(false);
     ui->label_3->setFont(font);
     ui->label_3->setStyleSheet("QLabel {color : #007fff; }");

     ui->label_4->setFont(font);
     ui->label_4->setStyleSheet("QLabel {color : #007fff; }");

     ui->label_5->setFont(font);
     ui->label_5->setStyleSheet("QLabel {color : #007fff; }");

     ui->label_6->setFont(font);
     ui->label_6->setStyleSheet("QLabel {color : #007fff; }");

     ui->comboBox->addItem("   Yield");
     ui->comboBox->addItem("   Parameter Summary");
     ui->comboBox->addItem("   Bin Summary");

     ui->checkBox->setFont(font);
     ui->checkBox->setStyleSheet("QCheckBox {color : #007fff; }");
     ui->checkBox_2->setFont(font);
     ui->checkBox_2->setStyleSheet("QCheckBox {color : #007fff; }");
     ui->checkBox_3->setFont(font);
     ui->checkBox_3->setStyleSheet("QCheckBox {color : #007fff; }");

     QCheckBox * pchb = new QCheckBox();
     pchb->setText("Lot");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
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
    while ((child = ui->verticalLayout->takeAt(0)) != 0)  {
        delete child->widget();
    }

    QFont font = ui->label->font();
    font.setPointSize(16);
    font.setBold(false);
    for (int i=0; i<choices.size(); ++i)
    {
        QCheckBox * c_b = new QCheckBox(choices[i],this);
        c_b->setFont(font);
        c_b->setStyleSheet("QCheckBox {color : #007fff; }");
        ui->verticalLayout->addWidget(c_b);
    }
}
