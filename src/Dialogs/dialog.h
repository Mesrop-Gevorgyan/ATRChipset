#ifndef DIALOG_H
#define DIALOG_H

class QPushButton;
class QStackedLayout;

#include <QDialog>

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
    explicit AppDialog(QWidget *parent = 0);
    ~AppDialog();

private:
    Ui::Dialog *ui;
    int m_page_id;
    QPushButton * next;
    QPushButton * previous;
    QPushButton * cancel;
    QPushButton * finish;
    QStackedLayout * content;
};

#endif // DIALOG_H
