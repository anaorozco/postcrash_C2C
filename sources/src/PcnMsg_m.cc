//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/PcnMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PcnMsg_m.h"

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




Register_Class(PcnMsg);

PcnMsg::PcnMsg(const char *name, int kind) : WaveAppMsg(name,kind)
{
    this->pcnTypeMsg_var = "";
    this->applicationType_var = 1;  // Defined for classification of apps.
    								// Values:  1:PCN
}

PcnMsg::PcnMsg(const PcnMsg& other) : WaveAppMsg(other)
{
    copy(other);
}

PcnMsg::~PcnMsg()
{
}

PcnMsg& PcnMsg::operator=(const PcnMsg& other)
{
    if (this==&other) return *this;
    WaveAppMsg::operator=(other);
    copy(other);
    return *this;
}

void PcnMsg::copy(const PcnMsg& other)
{
    this->pcnTypeMsg_var = other.pcnTypeMsg_var;
}

void PcnMsg::parsimPack(cCommBuffer *b)
{
    WaveAppMsg::parsimPack(b);
    doPacking(b,this->pcnTypeMsg_var);
}

void PcnMsg::parsimUnpack(cCommBuffer *b)
{
    WaveAppMsg::parsimUnpack(b);
    doUnpacking(b,this->pcnTypeMsg_var);
}

const char * PcnMsg::getPcnTypeMsg() const
{
    return pcnTypeMsg_var.c_str();
}

void PcnMsg::setPcnTypeMsg(const char * pcnTypeMsg)
{
    this->pcnTypeMsg_var = pcnTypeMsg;
}

class PcnMsgDescriptor : public cClassDescriptor
{
  public:
    PcnMsgDescriptor();
    virtual ~PcnMsgDescriptor();

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

Register_ClassDescriptor(PcnMsgDescriptor);

PcnMsgDescriptor::PcnMsgDescriptor() : cClassDescriptor("PcnMsg", "WaveAppMsg")
{
}

PcnMsgDescriptor::~PcnMsgDescriptor()
{
}

bool PcnMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PcnMsg *>(obj)!=NULL;
}

const char *PcnMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PcnMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PcnMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PcnMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pcnTypeMsg",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int PcnMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pcnTypeMsg")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PcnMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *PcnMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PcnMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PcnMsg *pp = (PcnMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PcnMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PcnMsg *pp = (PcnMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getPcnTypeMsg());
        default: return "";
    }
}

bool PcnMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PcnMsg *pp = (PcnMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setPcnTypeMsg((value)); return true;
        default: return false;
    }
}

const char *PcnMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *PcnMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PcnMsg *pp = (PcnMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


