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
    FileInfo m_file;
    static int NumberOfFiles;
public:
    parser(const QString&);
    FileInfo scanner();
    QPair<FileInfo,CVectorCollection> loader();
};

#endif // PARSER_H
