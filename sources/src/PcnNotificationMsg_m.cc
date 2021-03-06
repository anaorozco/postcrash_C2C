//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/PcnNotificationMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PcnNotificationMsg_m.h"

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




Register_Class(PcnNotificationMsg);

PcnNotificationMsg::PcnNotificationMsg(const char *name, int kind) : PcnMsg(name,kind)
{
    this->accidentStatus_var = 0;
    this->pcnTypeMsg_var = "pcnNotificationMsg";
}

PcnNotificationMsg::PcnNotificationMsg(const PcnNotificationMsg& other) : PcnMsg(other)
{
    copy(other);
}

PcnNotificationMsg::~PcnNotificationMsg()
{
}

PcnNotificationMsg& PcnNotificationMsg::operator=(const PcnNotificationMsg& other)
{
    if (this==&other) return *this;
    PcnMsg::operator=(other);
    copy(other);
    return *this;
}

void PcnNotificationMsg::copy(const PcnNotificationMsg& other)
{
    this->coordinates_var = other.coordinates_var;
    this->accidentStatus_var = other.accidentStatus_var;
}

void PcnNotificationMsg::parsimPack(cCommBuffer *b)
{
    PcnMsg::parsimPack(b);
    doPacking(b,this->coordinates_var);
    doPacking(b,this->accidentStatus_var);
}

void PcnNotificationMsg::parsimUnpack(cCommBuffer *b)
{
    PcnMsg::parsimUnpack(b);
    doUnpacking(b,this->coordinates_var);
    doUnpacking(b,this->accidentStatus_var);
}

Coord& PcnNotificationMsg::getCoordinates()
{
    return coordinates_var;
}

void PcnNotificationMsg::setCoordinates(const Coord& coordinates)
{
    this->coordinates_var = coordinates;
}

const char * PcnNotificationMsg::getAccidentStatus() const
{
    return accidentStatus_var.c_str();
}

void PcnNotificationMsg::setAccidentStatus(const char * accidentStatus)
{
    this->accidentStatus_var = accidentStatus;
}

class PcnNotificationMsgDescriptor : public cClassDescriptor
{
  public:
    PcnNotificationMsgDescriptor();
    virtual ~PcnNotificationMsgDescriptor();

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

Register_ClassDescriptor(PcnNotificationMsgDescriptor);

PcnNotificationMsgDescriptor::PcnNotificationMsgDescriptor() : cClassDescriptor("PcnNotificationMsg", "PcnMsg")
{
}

PcnNotificationMsgDescriptor::~PcnNotificationMsgDescriptor()
{
}

bool PcnNotificationMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PcnNotificationMsg *>(obj)!=NULL;
}

const char *PcnNotificationMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PcnNotificationMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PcnNotificationMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PcnNotificationMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "coordinates",
        "accidentStatus",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PcnNotificationMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "coordinates")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "accidentStatus")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PcnNotificationMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "Coord",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PcnNotificationMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PcnNotificationMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PcnNotificationMsg *pp = (PcnNotificationMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PcnNotificationMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PcnNotificationMsg *pp = (PcnNotificationMsg *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getCoordinates(); return out.str();}
        case 1: return oppstring2string(pp->getAccidentStatus());
        default: return "";
    }
}

bool PcnNotificationMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PcnNotificationMsg *pp = (PcnNotificationMsg *)object; (void)pp;
    switch (field) {
        case 1: pp->setAccidentStatus((value)); return true;
        default: return false;
    }
}

const char *PcnNotificationMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "Coord",
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *PcnNotificationMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PcnNotificationMsg *pp = (PcnNotificationMsg *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getCoordinates()); break;
        default: return NULL;
    }
}


