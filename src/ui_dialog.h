/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(668, 480);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 420, 101, 41));
        pushButton->setMaximumSize(QSize(101, 16777215));
        pushButton->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        line = new QFrame(Dialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(210, 0, 21, 481));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 171, 61));
        label->setStyleSheet(QLatin1String("font: 26pt \"MS Shell Dlg 2\";\n"
""));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 111, 41));
        label_2->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 190, 111, 41));
        label_3->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 260, 111, 41));
        label_4->setStyleSheet(QStringLiteral("font: 16pt \"MS Shell Dlg 2\";"));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 60, 61, 41));
        label_5->setStyleSheet(QStringLiteral("font: 75 14pt \"MS Shell Dlg 2\";"));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(310, 70, 161, 21));
        comboBox->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        comboBox->setEditable(false);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Analysis", 0));
        pushButton->setText(QApplication::translate("Dialog", "NEXT", 0));
        label->setText(QApplication::translate("Dialog", "Analysis", 0));
        label_2->setText(QApplication::translate("Dialog", "Statistics", 0));
        label_3->setText(QApplication::translate("Dialog", "Histogram", 0));
        label_4->setText(QApplication::translate("Dialog", "Bin Pareto", 0));
        label_5->setText(QApplication::translate("Dialog", "Type:", 0));
        comboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
