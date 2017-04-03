#include "Parser.h"
int CParser::NumberOfFiles = 0;
CParser::CParser(const QString& filePath):m_filePath(filePath)
{
}

FileInfo CParser::scanner()
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
            if ((word == "BinDefinition") || (word == "ParameterDefinition"))
                scanDefinition(in,result,word);
            if ((word == "BinData") || word == "ParameterData" )
                scanData(in,result,word);
            if (word == "ParameterLimits")
                scanParameterLimits(in,result);
        }
        file.close();
    }
    result.ID = NumberOfFiles;
    ++NumberOfFiles;
    return result;
}

void CParser::scanDefinition(QTextStream& in, FileInfo& result,QString word)
{
    if (word == "BinDefinition")
        result.m_fileType=BinDefinition;
    else
        result.m_fileType=ParameterDefinition;
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
}

void CParser::scanData(QTextStream& in,FileInfo& result,QString word)
{
    if (word == "BinData")
        result.m_fileType=BinData;
    else
        result.m_fileType=ParameterData;
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
}


void CParser::scanParameterLimits(QTextStream& in, FileInfo& result)
{
    result.m_fileType=ParameterLimits;
    in.readLine();
    in.readLine();
    QString word;
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
                        word.remove(':');
                        Field fieldName(word);
                        in>>word;
                        FieldValue val(word,fieldType);
                        result.m_fileContext.add(fieldName,val);
                }
        in>>word;
    }
}

FileData CParser::loader(const FileType &fileType)
{
    QVector<IVectorPtr> data;
    QFile file(m_filePath);
    TableInfo tableInfo;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        if (fileType == BinDefinition)
            loadBinDefinition(in,data,tableInfo);
        if (fileType == BinData)
            loadBinData(in,data,tableInfo);
        if (fileType == ParameterDefinition)
            loadParameterDefinition(in,data,tableInfo);
        if (fileType == ParameterData)
            loadParameterData(in,data,tableInfo);
        if (fileType == ParameterLimits)
            loadParameterLimits(in,data,tableInfo);
    }
    CVectorCollection result(data);
    return FileData(result,tableInfo);
}

void CParser::loadBinDefinition(QTextStream& in, QVector<IVectorPtr>& data,
                                TableInfo& tableInfo)
{
    QVector<QString>  v_Bin,v_BinType,v_BinName;
    QVector<bool> v_PassFail;
    QString word;
    in>>word;
    while (word != "@Data")
    {
        in.readLine();
        in>>word;
    }

    in.readLine();
    for (int i = 0; i < 3; ++ i)
    {
        in>>word;
        tableInfo.add(word.split(":")[0],i);
    };
    in.readLine();
    while (!in.atEnd() )
    {
        in>>word;
        QStringList words = word.split(";");
        v_Bin.push_back(words[0]);
        v_BinType.push_back(words[1]);
        v_BinName.push_back(words[2]);
        if (words[3] == "true")
            v_PassFail.push_back(true);
        else
            v_PassFail.push_back(false);
    }
    CStringDataPtr bin = CStringDataPtr(new CStringData(v_Bin));
    CStringDataPtr type = CStringDataPtr(new CStringData(v_BinType));
    CStringDataPtr  name= CStringDataPtr(new CStringData(v_BinName));
    CBoolDataPtr pass = CBoolDataPtr(new CBoolData(v_PassFail));
    data.push_back(bin);
    data.push_back(type);
    data.push_back(name);
    data.push_back(pass);
}

void CParser::loadBinData(QTextStream& in, QVector<IVectorPtr>& data,
                          TableInfo& tableInfo)
{
    QVector<QString> v_Bin,v_BinType;
    QVector<int> v_DieX,v_DieY;
    QString word;
    in>>word;
    while (word != "@Data")
    {
        in.readLine();
        in>>word;
    }
    in.readLine();
    for (int i = 0; i < 3; ++ i)
    {
        in>>word;
        tableInfo.add(word.split(":")[0],i);
    };
    in.readLine();
    while (!in.atEnd() )
    {
        int x;
        char ch;
        in>>x>>ch;
        v_DieX.push_back(x);
        in>>x>>ch;
        v_DieY.push_back(x);
        in>>word;
        QStringList words = word.split(";");
        v_Bin.push_back(words[0]);
        v_BinType.push_back(words[1]);
    }
    CIntDataPtr diex = CIntDataPtr(new CIntData(v_DieX));
    CIntDataPtr diey = CIntDataPtr(new CIntData(v_DieY));
    CStringDataPtr bin= CStringDataPtr(new CStringData(v_Bin));
    CStringDataPtr bintype = CStringDataPtr(new CStringData(v_BinType));
    data.push_back(diex);
    data.push_back(diey);
    data.push_back(bin);
    data.push_back(bintype);
}

void CParser::loadParameterDefinition(QTextStream& in, QVector<IVectorPtr>& data,
                                      TableInfo& tableInfo)
{
    QVector<QString> v_Parameter,v_ParameterUnit;
    QVector<int> v_TestNumber;
    QString word;
    in>>word;
    while (word != "@Data")
    {
        in.readLine();
        in>>word;
    }
    in.readLine();
    for (int i = 0; i < 2; ++ i)
    {
        in>>word;
        tableInfo.add(word.split(":")[0],i);
    };
    in.readLine();
    while (!in.atEnd() )
    {
       in>>word;
       QStringList words = word.split(";");
       v_Parameter.push_back(words[0]);
       v_TestNumber.push_back(words[1].toInt());
       v_ParameterUnit.push_back(words[2]);
    }
    CStringDataPtr parameter= CStringDataPtr(new CStringData(v_Parameter));
    CIntDataPtr testnumber = CIntDataPtr(new CIntData(v_TestNumber));
    CStringDataPtr parameterunit = CStringDataPtr(new CStringData(v_ParameterUnit));
    data.push_back(parameter);
    data.push_back(testnumber);
    data.push_back(parameterunit);
}

void CParser::loadParameterData(QTextStream& in, QVector<IVectorPtr>& data,
                                TableInfo& tableInfo)
{
    QVector<int> v_DieX,v_DieY,v_TestNumber;
    QVector<double> v_Last;
    QVector<bool> v_TestPass;
    QString word;
    in>>word;
    while (word != "@Data")
    {
        in.readLine();
        in>>word;
    }
    in.readLine();
    for (int i = 0; i < 4; ++ i)
    {
        in>>word;
        tableInfo.add(word.split(":")[0],i);
    };
    in.readLine();
    while (!in.atEnd() )
    {
        int iv;
        double dv;
        char ch;
        in>>iv>>ch;
        v_DieX.push_back(iv);
        in>>iv>>ch;
        v_DieY.push_back(iv);
        in>>iv>>ch;
        v_TestNumber.push_back(iv);
        in>>dv>>ch;
        v_Last.push_back(dv);
        in>>word;
        if (word == "true")
            v_TestPass.push_back(true);
        else
            v_TestPass.push_back(false);
    }
    CIntDataPtr diex = CIntDataPtr(new CIntData(v_DieX));
    CIntDataPtr diey = CIntDataPtr(new CIntData(v_DieY));
    CIntDataPtr testnumber = CIntDataPtr(new CIntData(v_TestNumber));
    CDoubleDataPtr last = CDoubleDataPtr(new CDoubleData(v_Last));
    CBoolDataPtr testpass = CBoolDataPtr(new CBoolData(v_TestPass));
    data.push_back(diex);
    data.push_back(diey);
    data.push_back(testnumber);
    data.push_back(last);
    data.push_back(testpass);
}

void CParser::loadParameterLimits(QTextStream& in, QVector<IVectorPtr>& data,
                                  TableInfo& tableInfo)
{
    QVector<int> v_TestNumber;
    QVector<double> v_lsl,v_usl,v_target;
    QString word;
    in>>word;
    while (word != "@Data")
    {
        in.readLine();
        in>>word;
    }
    in.readLine();
    for (int i = 0; i < 3; ++ i)
    {
        in>>word;
        tableInfo.add(word.split(":")[0],i);
    };
    in.readLine();
    while (!in.atEnd() )
    {
        int iv;
        double dv;
        char ch;
        in>>iv>>ch;
        v_TestNumber.push_back(iv);
        in>>dv>>ch;
        v_lsl.push_back(dv);
        in>>dv>>ch;
        v_usl.push_back(dv);
        in>>dv>>ch;
        v_target.push_back(dv);
    }
    CIntDataPtr testnumber = CIntDataPtr(new CIntData(v_TestNumber));
    CDoubleDataPtr lsl = CDoubleDataPtr(new CDoubleData(v_lsl));
    CDoubleDataPtr usl = CDoubleDataPtr(new CDoubleData(v_usl));
    CDoubleDataPtr target = CDoubleDataPtr(new CDoubleData(v_target));
    data.push_back(testnumber);
    data.push_back(lsl);
    data.push_back(usl);
    data.push_back(target);
}
