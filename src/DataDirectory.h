#include "IDataDirectory.h"
#include "parser.h"
#include <QDir>
#include <QSet>

class DataDirectory: public IDataDirectory
{
public:
    DataDirectory(QString);
    FieldList getFields()const;
    QVariantList getFieldValues(Field const& oID)const;
    QList<FileInfo> getFiles(const QList<FileType>& fileTypes, const QList<FileContext> &contextList)const;
private:
    QMultiMap<FileType,FileInfo> m_type_file;
    QSet<QString> m_wafers,m_lots,m_devices;
    QSet<QDateTime> m_dates;
};
