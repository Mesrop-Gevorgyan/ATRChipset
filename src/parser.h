#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <DataStore.h>
#include "vector.h"
#include <QFile>
#include <QTextStream>

class parser
{
private:
    QString m_filePath;
    static int NumberOfFiles;
public:
    parser(const QString&);
    FileInfo scanner();
    CVectorCollection loader(const FileType&);
};

#endif // PARSER_H
