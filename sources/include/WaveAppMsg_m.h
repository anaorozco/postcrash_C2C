//
// Generated file, do not edit! Created by opp_msgc 4.2 from sources/WaveAppMsg.msg.
//

#ifndef _WAVEAPPMSG_M_H_
#define _WAVEAPPMSG_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <Coord.h>
// }}



/**
 * Class generated from <tt>sources/WaveAppMsg.msg</tt> by opp_msgc.
 * <pre>
 * packet WaveAppMsg {
 * 
 * 	string wamData = "";
 * 	
 * 	int applicationType = 0; 
 * 	
 * 	simtime_t timestamp = 0;
 * 	
 * 	
 * 	
 * 	
 * 	
 * 	
 * 	
 * }
 * </pre>
 */
class WaveAppMsg : public ::cPacket
{
  protected:
    opp_string wamData_var;
    int applicationType_var;
    simtime_t timestamp_var;

  private:
    void copy(const WaveAppMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WaveAppMsg&);

  public:
    WaveAppMsg(const char *name=NULL, int kind=0);
    WaveAppMsg(const WaveAppMsg& other);
    virtual ~WaveAppMsg();
    WaveAppMsg& operator=(const WaveAppMsg& other);
    virtual WaveAppMsg *dup() const {return new WaveAppMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getWamData() const;
    virtual void setWamData(const char * wamData);
    virtual int getApplicationType() const;
    virtual void setApplicationType(int applicationType);
    virtual simtime_t getTimestamp() const;
    virtual void setTimestamp(simtime_t timestamp);
};

inline void doPacking(cCommBuffer *b, WaveAppMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, WaveAppMsg& obj) {obj.parsimUnpack(b);}


#endif // _WAVEAPPMSG_M_H_
