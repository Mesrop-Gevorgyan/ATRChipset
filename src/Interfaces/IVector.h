#ifndef __IVECTOR__
#define __IVECTOR__

class QVariant;
class QString;
class QDateTime;

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

class IBoolVector : public IVector
{
public:
	virtual bool GetAt(int index) const = 0;
};

#endif //__IVECTOR__
