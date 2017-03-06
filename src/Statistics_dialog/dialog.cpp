#include "dialog.h"
#include "ui_dialog.h"
#include "grouping.h"
#include "statistics_config_page.h"
#include "analysis_widget.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::Dialog)
{
    CGrouping * gr = new CGrouping();
    CStatisticsConfigPage * st_config = new CStatisticsConfigPage();
    CAnalysisWidget * analysis = new CAnalysisWidget();
    st_config->show();
    gr->show();
    analysis->show();

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
