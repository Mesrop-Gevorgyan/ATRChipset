#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include "DataStore.h"
#include "vector.h"
#include <QFile>
#include <QTextStream>

class CParser
{
private:
    QString m_filePath;
    static int NumberOfFiles;
public:
    CParser(const QString&);
    FileInfo scanner();
    FileData loader(const FileType&);
private:
    void scanDefinition(QTextStream&, FileInfo&,QString);
    void scanData(QTextStream&, FileInfo&, QString);
    void scanParameterLimits(QTextStream&, FileInfo&);
    void loadBinDefinition(QTextStream&, QVector<IVectorPtr>&,
              TableInfo&);
    void loadParameterDefinition(QTextStream&, QVector<IVectorPtr>&,
              TableInfo&);
    void loadBinData(QTextStream&, QVector<IVectorPtr>&,
              TableInfo&);
    void loadParameterData(QTextStream&, QVector<IVectorPtr>&,
              TableInfo&);
    void loadParameterLimits(QTextStream&, QVector<IVectorPtr>&,
              TableInfo&);
};

#endif // PARSER_H
