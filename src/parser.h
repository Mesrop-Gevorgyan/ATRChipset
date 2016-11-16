#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <MainData.h>
#include <QFile>
#include <QTextStream>

class parser
{
private:
    FileInfo m_file;
public:
    parser(const QString&);
    FileInfo scanner();
    //FileData loader();
};

#endif // PARSER_H
