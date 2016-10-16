#ifndef __IFIELDCOLLECTION__
#define __IFIELDCOLLECTION__

class QVariant;
class QString;
class QDateTime;
class CIntData;
class CDoubleData;
class CDateTimeData;
class CStringData;
class QStringList;

typedef QString Field;
typedef QStringList FieldList;
// *
//  Declaration of interfaces `
//  IVector
//  IIntVector    (inherited from IVector)
//  IDoubleVector(inherited from IVector)
//  IDateTimeVector(inherited from IVector)
//  IStringVector (inherited From IVector)
// *

class IVector
{
public:
    virtual  QVariant GetValue(int index) const = 0;
    virtual  int GetCount() const = 0;
};

class IIntVector : public IVector
{
public:
    virtual int GetAt(int index) const = 0;
};

class IStringVector : public IVector
{
public:
    virtual QString GetAt(int index) const = 0;
};

class IDoubleVector : public IVector
{
public:
	virtual double GetAt(int index) const = 0;
};

class IDateTimeVector : public IVector
{
public:
	virtual QDateTime GetAt(int index) const = 0;
};

//*
// Declaration of interfaces `
// IFieldData
// IFieldCollection
// *
 
class IFieldData
{
public:
    //Returns count of rows in field
    virtual int GetCount() const = 0;
    //Returns field name
    virtual Field GetField() const = 0;
    //Returns whole field in vector<int>
    virtual CIntData GetIntData() const = 0;
    //Returns whole field in vector<double>
    virtual CDoubleData GetDoubleData() const = 0;
    //Returns whole field in vector<string>
    virtual CStringData GetStringData() const = 0;
    //Returns whole field in vector<QDateTime>
    virtual CDateTimeData GetDateTimeData() const = 0;
};

class IFieldCollection
{
public:
    //Returns field from collection by name
    virtual IFieldData* GetFieldData(Field field) const = 0; 
    //Returns count of fields in collection
    virtual int GetCount () const = 0;
    //Returns field by index in collection
    virtual Field GetField(int index) const = 0;
    //Returns index of field in collection
    virtual int GetFieldIndex(Field field) const = 0;
};
#endif // __IFIELDCOLLECTION__
