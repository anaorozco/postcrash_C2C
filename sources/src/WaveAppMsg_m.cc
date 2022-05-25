//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/WaveAppMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "WaveAppMsg_m.h"

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




Register_Class(WaveAppMsg);

WaveAppMsg::WaveAppMsg(const char *name, int kind) : cPacket(name,kind)
{
    this->wamData_var = "";
    this->applicationType_var = 0;
    this->timestamp_var = 0;
}

WaveAppMsg::WaveAppMsg(const WaveAppMsg& other) : cPacket(other)
{
    copy(other);
}

WaveAppMsg::~WaveAppMsg()
{
}

WaveAppMsg& WaveAppMsg::operator=(const WaveAppMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void WaveAppMsg::copy(const WaveAppMsg& other)
{
    this->wamData_var = other.wamData_var;
    this->applicationType_var = other.applicationType_var;
    this->timestamp_var = other.timestamp_var;
}

void WaveAppMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->wamData_var);
    doPacking(b,this->applicationType_var);
    doPacking(b,this->timestamp_var);
}

void WaveAppMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->wamData_var);
    doUnpacking(b,this->applicationType_var);
    doUnpacking(b,this->timestamp_var);
}

const char * WaveAppMsg::getWamData() const
{
    return wamData_var.c_str();
}

void WaveAppMsg::setWamData(const char * wamData)
{
    this->wamData_var = wamData;
}

int WaveAppMsg::getApplicationType() const
{
    return applicationType_var;
}

void WaveAppMsg::setApplicationType(int applicationType)
{
    this->applicationType_var = applicationType;
}

simtime_t WaveAppMsg::getTimestamp() const
{
    return timestamp_var;
}

void WaveAppMsg::setTimestamp(simtime_t timestamp)
{
    this->timestamp_var = timestamp;
}

class WaveAppMsgDescriptor : public cClassDescriptor
{
  public:
    WaveAppMsgDescriptor();
    virtual ~WaveAppMsgDescriptor();

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

Register_ClassDescriptor(WaveAppMsgDescriptor);

WaveAppMsgDescriptor::WaveAppMsgDescriptor() : cClassDescriptor("WaveAppMsg", "cPacket")
{
}

WaveAppMsgDescriptor::~WaveAppMsgDescriptor()
{
}

bool WaveAppMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WaveAppMsg *>(obj)!=NULL;
}

const char *WaveAppMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WaveAppMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int WaveAppMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *WaveAppMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "wamData",
        "applicationType",
        "timestamp",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int WaveAppMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "wamData")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "applicationType")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WaveAppMsgDescriptor::getFieldTypeString(void *object, int field) const
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
        "simtime_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *WaveAppMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WaveAppMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WaveAppMsg *pp = (WaveAppMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WaveAppMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WaveAppMsg *pp = (WaveAppMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getWamData());
        case 1: return long2string(pp->getApplicationType());
        case 2: return double2string(pp->getTimestamp());
        default: return "";
    }
}

bool WaveAppMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WaveAppMsg *pp = (WaveAppMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setWamData((value)); return true;
        case 1: pp->setApplicationType(string2long(value)); return true;
        case 2: pp->setTimestamp(string2double(value)); return true;
        default: return false;
    }
}

const char *WaveAppMsgDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *WaveAppMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WaveAppMsg *pp = (WaveAppMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


