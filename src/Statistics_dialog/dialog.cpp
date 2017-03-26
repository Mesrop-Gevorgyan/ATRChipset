#include "dialog.h"
#include "ui_dialog.h"
#include "config_widget.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::Dialog)
{
    CConfigWidget * config_widget = new CConfigWidget();
    config_widget->show();

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
