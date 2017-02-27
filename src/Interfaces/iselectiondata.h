#ifndef ISELECTIONDATA_H
#define ISELECTIONDATA_H

#include <QDialog>

#include "idatadirectory.h"
#include "selection.h"

class ISelectionData : public QDialog
{
public:
    virtual void SetDataDirectory(const IDataDirectory*) = 0;
    virtual Selection* getSelection() const = 0;
};

#endif // ISELECTIONDATA_H
