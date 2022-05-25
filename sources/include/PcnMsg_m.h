//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/PcnMsg.msg.
//

#ifndef _PCNMSG_M_H_
#define _PCNMSG_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "WaveAppMsg_m.h"
// }}



/**
 * Class generated from <tt>sources/PcnMsg.msg</tt> by opp_msgc.
 * <pre>
 * packet PcnMsg extends WaveAppMsg{
 *     string pcnTypeMsg = "";   
 *     						  
 * }
 * </pre>
 */
class PcnMsg : public ::WaveAppMsg
{
  protected:
    opp_string pcnTypeMsg_var;

  private:
    void copy(const PcnMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PcnMsg&);

  public:
    PcnMsg(const char *name=NULL, int kind=0);
    PcnMsg(const PcnMsg& other);
    virtual ~PcnMsg();
    PcnMsg& operator=(const PcnMsg& other);
    virtual PcnMsg *dup() const {return new PcnMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getPcnTypeMsg() const;
    virtual void setPcnTypeMsg(const char * pcnTypeMsg);
};

inline void doPacking(cCommBuffer *b, PcnMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PcnMsg& obj) {obj.parsimUnpack(b);}


#endif // _PCNMSG_M_H_
