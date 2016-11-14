#ifndef __IFIELDCOLLECTION__
#define __IFIELDCOLLECTION__

class QString;

typedef QString Field;
class IFieldData;

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
