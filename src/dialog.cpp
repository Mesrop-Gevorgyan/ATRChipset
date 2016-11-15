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
#include <iostream>
void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QVector<QString> choices;
    std::cout<<arg1.toStdString()<<std::endl;
   //for (int i = 0; i< CheckBoxVec.size(); ++i)
    //{
        //CheckBoxVec[i]->hide();
        //delete CheckBoxVec[i];
    //}
    //CheckBoxVec.resize(0);
    //std::cout<<CheckBoxVec.size()<<std::endl;

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
        //QCheckBox * pchb = new QCheckBox();
        //pchb->setText("HBIN");
        //QCheckBox * pchb_1 = new QCheckBox();
        //pchb_1->setText("SBIN");
        //CheckBoxVec.push_back(pchb);
        //CheckBoxVec.push_back(pchb_1);
        //pchb->show();
        //pchb_1->show();

    //}
    //std::cout<<CheckBoxVec.size()<<std::endl;

    /*if (arg1 == "   Yield" || arg1 == "   Bin Summary")
    {
        //HBIN and SBIN
    }
    else
    {
        //MIN MAX MEDIAN ...
    }*/

    //remove layout contant
    QLayoutItem *child;
    while ((child = ui->verticalLayout->takeAt(0)) != 0)  {
        delete child->widget();
    }

    /*QList<QWidget *> widgets = ui->verticalLayout->findChildren<QWidget *>();
    foreach(QWidget * child, widgets)
    {
        ui->verticalLayout->removeWidget(child);
        delete child;
    }*/

    QFont font = ui->label->font();
    font.setPointSize(16);
    font.setBold(false);
    for (int i=0; i<choices.size(); ++i)
    {
        QCheckBox * c_b = new QCheckBox(choices[i],this);
        c_b->setFont(font);
        c_b->setStyleSheet("QCheckBox {color : #007fff; }");
        std::cout<<choices[i].toStdString()<<std::endl;
        ui->verticalLayout->addWidget(c_b);
    }
}
