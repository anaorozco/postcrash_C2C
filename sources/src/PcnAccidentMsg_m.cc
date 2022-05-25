//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/PcnAccidentMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PcnAccidentMsg_m.h"

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




Register_Class(PcnAccidentMsg);

PcnAccidentMsg::PcnAccidentMsg(const char *name, int kind) : PcnMsg(name,kind)
{
    this->accidentStatus_var = 0;
    this->pcnMsgID_var = 0;
    this->pcnTypeMsg_var = "a";
}

PcnAccidentMsg::PcnAccidentMsg(const PcnAccidentMsg& other) : PcnMsg(other)
{
    copy(other);
}

PcnAccidentMsg::~PcnAccidentMsg()
{
}

PcnAccidentMsg& PcnAccidentMsg::operator=(const PcnAccidentMsg& other)
{
    if (this==&other) return *this;
    PcnMsg::operator=(other);
    copy(other);
    return *this;
}

void PcnAccidentMsg::copy(const PcnAccidentMsg& other)
{
    this->accidentStatus_var = other.accidentStatus_var;
    this->pcnMsgID_var = other.pcnMsgID_var;
}

void PcnAccidentMsg::parsimPack(cCommBuffer *b)
{
    PcnMsg::parsimPack(b);
    doPacking(b,this->accidentStatus_var);
    doPacking(b,this->pcnMsgID_var);
}

void PcnAccidentMsg::parsimUnpack(cCommBuffer *b)
{
    PcnMsg::parsimUnpack(b);
    doUnpacking(b,this->accidentStatus_var);
    doUnpacking(b,this->pcnMsgID_var);
}

const char * PcnAccidentMsg::getAccidentStatus() const
{
    return accidentStatus_var.c_str();
}

void PcnAccidentMsg::setAccidentStatus(const char * accidentStatus)
{
    this->accidentStatus_var = accidentStatus;
}

int PcnAccidentMsg::getPcnMsgID() const
{
    return pcnMsgID_var;
}

void PcnAccidentMsg::setPcnMsgID(int pcnMsgID)
{
    this->pcnMsgID_var = pcnMsgID;
}

class PcnAccidentMsgDescriptor : public cClassDescriptor
{
  public:
    PcnAccidentMsgDescriptor();
    virtual ~PcnAccidentMsgDescriptor();

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

Register_ClassDescriptor(PcnAccidentMsgDescriptor);

PcnAccidentMsgDescriptor::PcnAccidentMsgDescriptor() : cClassDescriptor("PcnAccidentMsg", "PcnMsg")
{
}

PcnAccidentMsgDescriptor::~PcnAccidentMsgDescriptor()
{
}

bool PcnAccidentMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PcnAccidentMsg *>(obj)!=NULL;
}

const char *PcnAccidentMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PcnAccidentMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PcnAccidentMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PcnAccidentMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "accidentStatus",
        "pcnMsgID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PcnAccidentMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "accidentStatus")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pcnMsgID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PcnAccidentMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PcnAccidentMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PcnAccidentMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PcnAccidentMsg *pp = (PcnAccidentMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PcnAccidentMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PcnAccidentMsg *pp = (PcnAccidentMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getAccidentStatus());
        case 1: return long2string(pp->getPcnMsgID());
        default: return "";
    }
}

bool PcnAccidentMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PcnAccidentMsg *pp = (PcnAccidentMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setAccidentStatus((value)); return true;
        case 1: pp->setPcnMsgID(string2long(value)); return true;
        default: return false;
    }
}

const char *PcnAccidentMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *PcnAccidentMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PcnAccidentMsg *pp = (PcnAccidentMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


