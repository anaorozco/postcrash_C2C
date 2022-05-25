//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/PcnInitialMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PcnInitialMsg_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(PcnInitialMsg);

PcnInitialMsg::PcnInitialMsg(const char *name, int kind) : PcnMsg(name,kind)
{
    this->appZone_var = 0;
    this->pcnTypeMsg_var = "i";
}



PcnInitialMsg::PcnInitialMsg(const PcnInitialMsg& other) : PcnMsg(other)
{
    copy(other);
}

PcnInitialMsg::~PcnInitialMsg()
{
}

PcnInitialMsg& PcnInitialMsg::operator=(const PcnInitialMsg& other)
{
    if (this==&other) return *this;
    PcnMsg::operator=(other);
    copy(other);
    return *this;
}

void PcnInitialMsg::copy(const PcnInitialMsg& other)
{
    this->appZone_var = other.appZone_var;
}

void PcnInitialMsg::parsimPack(cCommBuffer *b)
{
    PcnMsg::parsimPack(b);
    doPacking(b,this->appZone_var);
}

void PcnInitialMsg::parsimUnpack(cCommBuffer *b)
{
    PcnMsg::parsimUnpack(b);
    doUnpacking(b,this->appZone_var);
}

double PcnInitialMsg::getAppZone() const
{
    return appZone_var;
}

void PcnInitialMsg::setAppZone(double appZone)
{
    this->appZone_var = appZone;
}

class PcnInitialMsgDescriptor : public cClassDescriptor
{
  public:
    PcnInitialMsgDescriptor();
    virtual ~PcnInitialMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PcnInitialMsgDescriptor);

PcnInitialMsgDescriptor::PcnInitialMsgDescriptor() : cClassDescriptor("PcnInitialMsg", "PcnMsg")
{
}

PcnInitialMsgDescriptor::~PcnInitialMsgDescriptor()
{
}

bool PcnInitialMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PcnInitialMsg *>(obj)!=NULL;
}

const char *PcnInitialMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PcnInitialMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PcnInitialMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *PcnInitialMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "appZone",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int PcnInitialMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "appZone")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PcnInitialMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *PcnInitialMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PcnInitialMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PcnInitialMsg *pp = (PcnInitialMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PcnInitialMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PcnInitialMsg *pp = (PcnInitialMsg *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getAppZone());
        default: return "";
    }
}

bool PcnInitialMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PcnInitialMsg *pp = (PcnInitialMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setAppZone(string2double(value)); return true;
        default: return false;
    }
}

const char *PcnInitialMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *PcnInitialMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PcnInitialMsg *pp = (PcnInitialMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


