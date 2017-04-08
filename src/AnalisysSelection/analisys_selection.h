#ifndef ANALISYS_SELECTION_H
#define ANALISYS_SELECTION_H

#include <QVBoxLayout>
#include <QWidget>

class AnalisysSelection : public QWidget
{
    Q_OBJECT

public:
   explicit AnalisysSelection(/*QWidget *parent = 0*/);
    ~AnalisysSelection();

private:
    QVBoxLayout* BinTypes;
};

#endif // ANALISYS_SELECTION_H
