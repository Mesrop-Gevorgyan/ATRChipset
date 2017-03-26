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
class CDoubleData;
class CStringData;
class CDateTimeData;
class CBoolData;
class IVector;
class ITable;

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
enum DataType
{
	INT,
	DOUBLE,
	STRING,
	BOOL,
	DATETIME,
};

// Hardcode Lot,Wafer,Device,Date literals
#define LOT "Lot"
#define WAFER "Wafer"
#define DEVICE "Device"
#define DATE "Date"

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
typedef QSharedPointer<CDoubleData> CDoubleDataPtr;
typedef QSharedPointer<CStringData> CStringDataPtr;
typedef QSharedPointer<CBoolData> CBoolDataPtr;
typedef QSharedPointer<CDateTimeData> CDateTimeDataPtr;
typedef QSharedPointer<IVector> IVectorPtr;
typedef QSharedPointer<ITable> ITablePtr;

#endif // !GLOBAL_H

