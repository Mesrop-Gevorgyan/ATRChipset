#include "parser.h"

parser::parser(const QString& name)
{
    m_file.m_fileName = name;
}

FileInfo parser::scanner()
{
    QFile f(m_file.m_fileName);
    QMap<Field, Value> context;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&f);
        while (!in.atEnd())
        {
            QString word;
            in>>word;
            if (word != "Type:")
            {
                in.readLine();
                continue;
            }
            in>>word;
            if(word == "BinDefinition")
            {
                m_file.m_fileType=BinDefinition;
                in.readLine();
                in.readLine();
                in>>word;
                while(word !=  "@Data")
                {
                    if (word != "@Context" && word != "")
                    {
                        QString key = word;
                        in>>word;
                        key.remove(':');
                        context[key] = word;
                    }
                    in>>word;
                }
                break;
            }
            if(word == "BinData")
            {
                m_file.m_fileType=BinData;
                in.readLine();
                in.readLine();
                in>>word;
                while(word != "@Data")
                {
                    if (word != "@Context" && word != "@TestConditions" && word != "")
                    {
                        QString key = word;
                        word = in.readLine();
                        key.remove(':');
                        context[key] = word.remove(' ');
                    }
                    in>>word;
                }
                break;
            }
            if(word == "ParameterDefinition")
            {
                m_file.m_fileType=ParameterDefinition;
                in.readLine();
                in.readLine();
                in>>word;
                while(word !=  "@Data")
                {
                    if (word != "@Context" && word != "")
                    {
                        QString key = word;
                        in>>word;
                        key.remove(':');
                        context[key] = word;
                    }
                    in>>word;
                }
                break;
            }
            if(word == "ParameterData")
            {
                m_file.m_fileType=ParameterData;
                in.readLine();
                in.readLine();
                in>>word;
                while(word != "@Data")
                {
                    if (word != "@Context" && word != "@TestConditions" && word != "")
                    {
                        QString key = word;
                        word = in.readLine();
                        key.remove(':');
                        context[key] = word.remove(' ');
                    }
                    in>>word;
                }
                break;
            }
            if(word == "ParameterLimits")
            {
                m_file.m_fileType=ParameterLimits;
                in.readLine();
                in.readLine();
                in>>word;
                while(word != "@Data")
                {
                    if (word != "@Context" && word != "@TestConditions" && word != "")
                    {
                        QString key = word;
                        word = in.readLine();
                        key.remove(':');
                        context[key] = word.remove(' ');
                    }
                    in>>word;
                }
                break;
            }

        }
        f.close();
    }
    m_file.m_context.SetContext(context);
    return m_file;
}
