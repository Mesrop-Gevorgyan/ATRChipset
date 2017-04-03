#ifndef __IVECTOR__
#define __IVECTOR__

class QVariant;
class QString;
class QDateTime;
enum class DataType;

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
	virtual  QVariant GetValue(unsigned index) const = 0;
	virtual  int GetCount() const = 0;
	virtual  DataType GetType() const = 0;
};

class IIntVector : public IVector
{
public:
	virtual int GetAt(unsigned index) const = 0;
};

class IStringVector : public IVector
{
public:
	virtual QString GetAt(unsigned index) const = 0;
};

class IDoubleVector : public IVector
{
public:
	virtual double GetAt(unsigned index) const = 0;
};

class IDateTimeVector : public IVector
{
public:
	virtual QDateTime GetAt(unsigned index) const = 0;
};

class IBoolVector : public IVector
{
public:
	virtual bool GetAt(unsigned index) const = 0;
};

#endif //__IVECTOR__
