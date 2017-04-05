#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QLabel>
#include "config_widget.h"

class CSelection: public QWidget
{
public:
    CSelection():QWidget()
    {
        QVBoxLayout * l = new QVBoxLayout();
        QLabel * label = new QLabel("Selection");
        l->addWidget(label);
        this->setLayout(l);
    }

};

class CConfig: public QWidget
{
public:
    CConfig():QWidget()
    {
        QVBoxLayout * l = new QVBoxLayout();
        QLabel * label = new QLabel("Config");
        l->addWidget(label);
        this->setLayout(l);
    }

};

AppDialog::AppDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), m_page_id(0),next(new QPushButton("NEXT")),
    previous(new QPushButton("PREVIOUS")),
    finish(new QPushButton("FINISH")),
    content(new QStackedLayout())
{
    QVBoxLayout * dialog_body = new QVBoxLayout();
    QHBoxLayout * buttons = new QHBoxLayout();
    //next = new QPushButton("NEXT");
    connect(next, SIGNAL(clicked(bool)), this, SLOT(next_button_pressed()));
    connect(previous, SIGNAL(clicked(bool)), this, SLOT(previous_button_pressed()));
    //previous = new QPushButton("PREVIOUS");
    previous->setEnabled(false);
    cancel = new QPushButton("CANCEL");
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    //finish = new QPushButton("FINISH");
    finish->setEnabled(false);
    buttons->addWidget(previous);
    buttons->addWidget(next);
    buttons->addWidget(cancel);
    buttons->addWidget(finish);

    content->addWidget(new CSelection);
    content->addWidget(new CConfig);
    content->addWidget(new CConfigWidget);

    content->setCurrentIndex(m_page_id);

    dialog_body->addLayout(content);
    dialog_body->addLayout(buttons);
    this->setLayout(dialog_body);
    ui->setupUi(this);
}

AppDialog::~AppDialog()
{
    delete ui;
}

void AppDialog::next_button_pressed()
{
    switch(m_page_id)
    {
    case 0:
        previous->setEnabled(true);
        break;
    case 1:
        finish->setEnabled(true);
        next->setEnabled(false);
        break;
    }

    ++m_page_id;
    content->setCurrentIndex(m_page_id);

}

void AppDialog::previous_button_pressed()
{
    switch(m_page_id)
    {

    case 1:
        previous->setEnabled(false);
        break;
    case 2:
        finish->setEnabled(false);
        next->setEnabled(true);
        break;
    }

    --m_page_id;
    content->setCurrentIndex(m_page_id);

}
