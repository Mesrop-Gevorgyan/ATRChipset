#include "dialog.h"
#include "ui_dialog.h"


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

    QCheckBox * pchb = new QCheckBox();
    pchb->setText("Lot");

    ui->comboBox_2->addItem("   Lot");
    ui->comboBox_2->addItem("   Wafer");
    ui->comboBox_2->addItem("   Device");


    font.setPointSize(14);
    font.setBold(false);
    ui->checkBox->setFont(font);
    ui->checkBox->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_2->setFont(font);
    ui->checkBox_2->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_3->setFont(font);
    ui->checkBox_3->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_4->setFont(font);
    ui->checkBox_4->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_5->setFont(font);
    ui->checkBox_5->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_6->setFont(font);
    ui->checkBox_6->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_7->setFont(font);
    ui->checkBox_7->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_8->setFont(font);
    ui->checkBox_8->setStyleSheet("QCheckBox {color : #007fff; }");
    ui->checkBox_9->setFont(font);
    ui->checkBox_9->setStyleSheet("QCheckBox {color : #007fff; }");

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
   //for (int i = 0; i< CheckBoxVec.size(); ++i)
    //{
        //CheckBoxVec[i]->hide();
        //delete CheckBoxVec[i];
    //}
    //CheckBoxVec.resize(0);
    //std::cout<<CheckBoxVec.size()<<std::endl;

    //if (arg1 == "   Yield")
    //{
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

    if (arg1 == "   Yield" || arg1 == "   Bin Summary")
    {
        //HBIN and SBIN
    }
    else
    {
        //MIN MAX MEDIAN ...
    }

}
