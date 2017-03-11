#include "parser.h"
int parser::NumberOfFiles = 0;
parser::parser(const QString& filePath):m_filePath(filePath)
{
}

FileInfo parser::scanner()
{
    FileInfo result;
    result.m_filePath = m_filePath;
    QFile file(m_filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
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
            if (word == "BinDefinition")
            {
                result.m_fileType=BinDefinition;
                in.readLine();
                in.readLine();
                in>>word;
                while(word !=  "@Data")
                {
                    if (word != "@Context" && word != "")
                    {
                        word.remove(':');
                        Field fieldName(word);
                        in>>word;
                        FieldValue val(word,Context);
                        result.m_fileContext.add(fieldName,val);
                    }
                    in>>word;
                }
                break;
            }
            if (word == "BinData")
            {
                result.m_fileType=BinData;
                in.readLine();
                in.readLine();
                in>>word;
                FieldType fieldType;
                while(word != "@Data")
                {
                    if (word == "@Context")
                        fieldType = Context;
                    else
                        if (word == "@TestConditions")
                            fieldType = TestCondition;
                        else
                            if (word != "")
                            {
                                if (word == "Date:")
                                {
                                    in>>word;
                                    result.m_date.setDate(QDate::fromString(word,"dd/MM/yyyy"));
                                    in>>word;
                                    result.m_date.setTime(QTime::fromString(word));
                                }
                                else
                                {
                                    word.remove(':');
                                    Field fieldName(word);
                                    in>>word;
                                    FieldValue val(word,fieldType);
                                    result.m_fileContext.add(fieldName,val);
                                };
                            }
                    in>>word;
                }
                break;
            }
            if (word == "ParameterDefinition")
            {
                result.m_fileType=ParameterDefinition;
                in.readLine();
                in.readLine();
                in>>word;
                while (word !=  "@Data")
                {
                    if (word != "@Context" && word != "")
                    {
                        word.remove(':');
                        Field fieldName(word);
                        in>>word;
                        FieldValue val(word,Context);
                        result.m_fileContext.add(fieldName,val);
                    }
                    in>>word;
                }
                break;
            }
            if (word == "ParameterData")
            {
                result.m_fileType=ParameterData;
                in.readLine();
                in.readLine();
                in>>word;
                FieldType fieldType;
                while (word != "@Data")
                {
                    if (word == "@Context")
                        fieldType = Context;
                    else
                        if (word == "@TestConditions")
                            fieldType = TestCondition;
                        else
                            if (word != "")
                            {
                                if (word == "Date:")
                                {
                                    in>>word;
                                    result.m_date.setDate(QDate::fromString(word,"dd/MM/yyyy"));
                                    in>>word;
                                    result.m_date.setTime(QTime::fromString(word));
                                }
                                else
                                {
                                    word.remove(':');
                                    Field fieldName(word);
                                    in>>word;
                                    FieldValue val(word,fieldType);
                                    result.m_fileContext.add(fieldName,val);
                                };
                            }
                    in>>word;
                }
                break;
            }
            if (word == "ParameterLimits")
            {
                result.m_fileType=ParameterLimits;
                in.readLine();
                in.readLine();
                in>>word;
                FieldType fieldType;
                while (word != "@Data")
                {
                    if (word == "@Context")
                        fieldType = Context;
                    else
                        if (word == "@TestConditions")
                            fieldType = TestCondition;
                        else
                            if (word != "")
                            {
                                if (word == "Date:")
                                {
                                    in>>word;
                                    result.m_date.setDate(QDate::fromString(word,"dd/MM/yyyy"));
                                    in>>word;
                                    result.m_date.setTime(QTime::fromString(word));
                                }
                                else
                                {
                                    word.remove(':');
                                    Field fieldName(word);
                                    in>>word;
                                    FieldValue val(word,fieldType);
                                    result.m_fileContext.add(fieldName,val);
                                };
                            }
                    in>>word;
                }
                break;
            }

        }
        file.close();
    }
    result.ID = NumberOfFiles;
    ++NumberOfFiles;
    return result;
}

CVectorCollection parser::loader(const FileType &fileType)
{
    QVector<IVector*> data;
    QFile file(m_filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        if (fileType == BinDefinition)
        {
            QVector<QString>  Bin,BinType,BinName;
            QVector<bool> PassFail;
            QString word;
            in>>word;
            while (word != "@Data")
            {
                in.readLine();
                in>>word;
            }
            in.readLine();
            in.readLine();
            while (!in.atEnd() )
            {
                in>>word;
                QStringList words = word.split(";");
                Bin.push_back(words[0]);
                BinType.push_back(words[1]);
                BinName.push_back(words[2]);
                if (words[3] == "true")
                    PassFail.push_back(true);
                else
                    PassFail.push_back(false);
            }
            CStringData* bin = new CStringData(Bin);
            CStringData* type = new CStringData(BinType);
            CStringData*  name= new CStringData(BinName);
            CBoolData* pass = new CBoolData(PassFail);
            data.push_back(bin);
            data.push_back(type);
            data.push_back(name);
            data.push_back(pass);
        }
        else
            if (fileType == BinData)
            {
                QVector<QString> Bin,BinType;
                QVector<int> DieX,DieY;
                QString word;
                in>>word;
                while (word != "@Data")
                {
                    in.readLine();
                    in>>word;
                }
                in.readLine();
                in.readLine();
                while (!in.atEnd() )
                {
                    int x;
                    char ch;
                    in>>x>>ch;
                    DieX.push_back(x);
                    in>>x>>ch;
                    DieY.push_back(x);
                    in>>word;
                    QStringList words = word.split(";");
                    Bin.push_back(words[0]);
                    BinType.push_back(words[1]);
                }
                CIntData* diex = new CIntData(DieX);
                CIntData* diey = new CIntData(DieY);
                CStringData* bin= new CStringData(Bin);
                CStringData* bintype = new CStringData(BinType);
                data.push_back(diex);
                data.push_back(diey);
                data.push_back(bin);
                data.push_back(bintype);
            }
        else
                if (fileType == ParameterDefinition)
                {
                    QVector<QString> Parameter,ParameterUnit;
                    QVector<int> TestNumber;
                    QString word;
                    in>>word;
                    while (word != "@Data")
                    {
                        in.readLine();
                        in>>word;
                    }
                    in.readLine();
                    in.readLine();
                    while (!in.atEnd() )
                    {
                       in>>word;
                       QStringList words = word.split(";");
                       Parameter.push_back(words[0]);
                       TestNumber.push_back(words[1].toInt());
                       ParameterUnit.push_back(words[2]);
                    }
                    CStringData* parameter= new CStringData(Parameter);
                    CIntData* testnumber = new CIntData(TestNumber);
                    CStringData* parameterunit = new CStringData(ParameterUnit);
                    data.push_back(parameter);
                    data.push_back(testnumber);
                    data.push_back(parameterunit);
                }
        else
                    if (fileType == ParameterData)
                    {
                        QVector<int> DieX,DieY,TestNumber;
                        QVector<double> Last;
                        QVector<bool> TestPass;
                        QString word;
                        in>>word;
                        while (word != "@Data")
                        {
                            in.readLine();
                            in>>word;
                        }
                        in.readLine();
                        in.readLine();
                        while (!in.atEnd() )
                        {
                            int iv;
                            double dv;
                            char ch;
                            in>>iv>>ch;
                            DieX.push_back(iv);
                            in>>iv>>ch;
                            DieY.push_back(iv);
                            in>>iv>>ch;
                            TestNumber.push_back(iv);
                            in>>dv>>ch;
                            Last.push_back(dv);
                            in>>word;
                            if (word == "true")
                                TestPass.push_back(true);
                            else
                                TestPass.push_back(false);
                        }
                        CIntData* diex = new CIntData(DieX);
                        CIntData* diey = new CIntData(DieY);
                        CIntData* testnumber = new CIntData(TestNumber);
                        CDoubleData* last = new CDoubleData(Last);
                        CBoolData* testpass = new CBoolData(TestPass);
                        data.push_back(diex);
                        data.push_back(diey);
                        data.push_back(testnumber);
                        data.push_back(last);
                        data.push_back(testpass);
                    }
        else
                        if (fileType == ParameterLimits)
                        {
                                QVector<int> TestNumber;
                                QVector<double> LSL,USL,Target;
                                QString word;
                                in>>word;
                                while (word != "@Data")
                                {
                                    in.readLine();
                                    in>>word;
                                }
                                in.readLine();
                                in.readLine();
                                while (!in.atEnd() )
                                {
                                    int iv;
                                    double dv;
                                    char ch;
                                    in>>iv>>ch;
                                    TestNumber.push_back(iv);
                                    in>>dv>>ch;
                                    LSL.push_back(dv);
                                    in>>dv>>ch;
                                    USL.push_back(dv);
                                    in>>dv>>ch;
                                    Target.push_back(dv);
                                }
                                CIntData* testnumber = new CIntData(TestNumber);
                                CDoubleData* lsl = new CDoubleData(LSL);
                                CDoubleData* usl = new CDoubleData(USL);
                                CDoubleData* target = new CDoubleData(Target);
                                data.push_back(testnumber);
                                data.push_back(lsl);
                                data.push_back(usl);
                                data.push_back(target);
                        }
    }
    CVectorCollection result(data);
    return result;
}
