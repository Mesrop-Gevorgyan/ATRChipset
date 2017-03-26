#include "config_widget.h"
#include "statistics_config_page.h"
#include "analysis_widget.h"
#include <QHBoxLayout>
#include <QStackedLayout>

CConfigWidget::CConfigWidget(): QWidget()
{

    CStatisticsConfigPage * st_config = new CStatisticsConfigPage();
    QWidget * bin_pareto_config = new QWidget();
    QWidget * histogram_config  = new QWidget();
    QWidget * wafer_config  = new QWidget();

    QHBoxLayout * configLayout = new QHBoxLayout();
    CAnalysisWidget * analysis = new CAnalysisWidget();

    QStackedLayout * stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(st_config);
    stackedLayout->addWidget(bin_pareto_config);
    stackedLayout->addWidget(histogram_config);
    stackedLayout->addWidget(wafer_config);

    connect(analysis->GrListWidg, SIGNAL(currentRowChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));

    //connect(analysis, SIGNAL(itemClicked(QListWidgetItem *)), stackedLayout, SLOT(setCurrentIndex(int)));

    configLayout->addWidget(analysis);
    configLayout->addLayout(stackedLayout);
    QWidget::setLayout(configLayout);

}
