#ifndef DIALOG_H
#define DIALOG_H

class QPushButton;
class QStackedLayout;

#include <QDialog>
#include "DataDirectory.h"
#include "selection.h"
#include "selectiondatadialog.h"

enum class PageIds {selection=1, configuration=2, analysis=3};

namespace Ui {
class Dialog;
}

class AppDialog : public QDialog
{
    Q_OBJECT

public slots:
    void next_button_pressed();
    void previous_button_pressed();
public:
    AppDialog(DataDirectory * dataDirectory, QWidget *parent = 0);
    CSelection getSelection()const;
    ~AppDialog();

private:
    Ui::Dialog *ui;
    int m_page_id;
    QPushButton * next;
    QPushButton * previous;
    QPushButton * cancel;
    QPushButton * finish;
    QStackedLayout * content;
    CSelection m_selection;
    SelectionDataDialog * m_selection_widget;
};

#endif // DIALOG_H
