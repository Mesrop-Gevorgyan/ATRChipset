#ifndef GLOBAL_H
#define GLOBAL_H

#include <QList>
#include <QSharedPointer>

// Forword declarations
class QString;
class QStringList;
class QDateTime;
class QVariant;
class FileContext;
class CIntData;
class CIntDataGroup;
class CDoubleData;
class CDoubleDataGroup;
class CStringData;
class CBoolData;
class CBoolDataGroup;
class CStringDataGroup;
class CDateTimeData;
class CDateTimeDataGroup;
class CDateTimeData;
class CDateTimeDataGroup;
class IVector;
class ITable;
class IColumn;
class IDataDirectory;
class DataStore;

// Bin type
enum class EBinType
{
    HBin,
    SBin
};

// Types of files,which will be used
enum FileType
{
    BinData,
    BinDefinition,
    ParameterDefinition,
    ParameterData,
    ParameterLimits,
};

// Represent Field type in FileContext
enum FieldType
{
        Context,
        TestCondition,
};

// Represent Data Types for Vectors
enum class DataType
{
    INT,
    DOUBLE,
    STRING,
    BOOL,
    DATETIME
};

// Hardcode Lot,Wafer,Device,Date literals
#define LOT "Lot"
#define WAFER "Wafer"
#define DEVICE "Device"
#define DATE "Date"

const QString Bin = "Bin";
const QString BinType = "BinType";
const QString BinName = "BinName";
const QString PassFail = "PassFail";
const QString DieX = "DieX";
const QString DieY = "DieY";
const QString TestNumber = "TestNumber";
const QString Parameter = "Parameter";
const QString ParameterUnit = "ParameterUnit";
const QString Last = "Last";
const QString TestPass = "TestPass";
const QString LSL = "LSL";
const QString USL = "USL";
const QString Target = "Target";


typedef int ID;
typedef int Index;
typedef QString ColumnType;
typedef QString Field;
typedef QStringList FieldList;
typedef QVariant Value;
typedef QStringList ColumnList;
typedef QPair<Value, FieldType>  FieldValue;
typedef QList<int> IDList;
typedef QSharedPointer<CIntData> CIntDataPtr;
typedef QSharedPointer<CIntDataGroup> CIntDataGroupPtr;
typedef QSharedPointer<CDoubleDataGroup> CDoubleDataGroupPtr;
typedef QSharedPointer<CDoubleData> CDoubleDataPtr;
typedef QSharedPointer<CDoubleDataGroup> CDoubleDataGroupPtr;
typedef QSharedPointer<CStringData> CStringDataPtr;
typedef QSharedPointer<CStringDataGroup> CStringDataGroupPtr;
typedef QSharedPointer<CBoolData> CBoolDataPtr;
typedef QSharedPointer<CBoolDataGroup> CBoolDataGroupPtr;
typedef QSharedPointer<CDateTimeData> CDateTimeDataPtr;
typedef QSharedPointer<CDateTimeDataGroup> CDateTimeDataGroupPtr;
typedef QSharedPointer<IVector> IVectorPtr;
typedef QSharedPointer<ITable> ITablePtr;
typedef QSharedPointer<IColumn> IColumnPtr;

typedef QSharedPointer<ITable> ITablePtr;
typedef QSharedPointer<IDataDirectory> IDataDirectoryPtr;


#endif // !GLOBAL_H
