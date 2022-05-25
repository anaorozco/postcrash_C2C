#
# OMNeT++/OMNEST Makefile for calitest
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -IC:/Users/jdmillan/src/veins-2.0-rc2/src -IC:/Users/jdmillan/src/veins-2.0-rc2/src/base/messages -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/phy -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/utility -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/obstacle -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/analogueModel -IC:/Users/jdmillan/src/veins-2.0-rc2/src/base/connectionManager -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/messages -IC:/Users/jdmillan/src/veins-2.0-rc2/src/base/phyLayer -IC:/Users/jdmillan/src/veins-2.0-rc2/src/base/modules -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/mac/ieee80211p -IC:/Users/jdmillan/src/veins-2.0-rc2/src/modules/application/ieee80211p -IC:/Users/jdmillan/src/veins-2.0-rc2/src/base/utils -LC:/Users/jdmillan/src/veins-2.0-rc2/out/$(CONFIGNAME)/tests/testUtils -LC:/Users/jdmillan/src/veins-2.0-rc2/out/$(CONFIGNAME)/src/base -LC:/Users/jdmillan/src/veins-2.0-rc2/out/$(CONFIGNAME)/src/modules -lmiximtestUtils -lmiximbase -lmiximmodules -KMIXIM_PROJ=C:/Users/jdmillan/src/veins-2.0-rc2
#

# Name of target to be created (-o option)
TARGET = calitest$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(MIXIM_PROJ)/src \
    -I$(MIXIM_PROJ)/src/base/messages \
    -I$(MIXIM_PROJ)/src/modules/phy \
    -I$(MIXIM_PROJ)/src/modules/utility \
    -I$(MIXIM_PROJ)/src/modules \
    -I$(MIXIM_PROJ)/src/modules/obstacle \
    -I$(MIXIM_PROJ)/src/modules/analogueModel \
    -I$(MIXIM_PROJ)/src/base/connectionManager \
    -I$(MIXIM_PROJ)/src/modules/messages \
    -I$(MIXIM_PROJ)/src/base/phyLayer \
    -I$(MIXIM_PROJ)/src/base/modules \
    -I$(MIXIM_PROJ)/src/modules/mac/ieee80211p \
    -I$(MIXIM_PROJ)/src/modules/application/ieee80211p \
    -I$(MIXIM_PROJ)/src/base/utils \
    -I. \
    -Iresults \
    -Isources

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(MIXIM_PROJ)/out/$(CONFIGNAME)/tests/testUtils -L$(MIXIM_PROJ)/out/$(CONFIGNAME)/src/base -L$(MIXIM_PROJ)/out/$(CONFIGNAME)/src/modules  -lmiximtestUtils -lmiximbase -lmiximmodules
LIBS += -Wl,-rpath,`abspath $(MIXIM_PROJ)/out/$(CONFIGNAME)/tests/testUtils` -Wl,-rpath,`abspath $(MIXIM_PROJ)/out/$(CONFIGNAME)/src/base` -Wl,-rpath,`abspath $(MIXIM_PROJ)/out/$(CONFIGNAME)/src/modules`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/sources/Accident.o \
    $O/sources/App_PCN.o \
    $O/sources/DrgLayer.o \
    $O/sources/PcnAccidentMsg_m.o \
    $O/sources/PcnInitialMsg_m.o \
    $O/sources/PcnMsg_m.o \
    $O/sources/PcnNotificationMsg_m.o \
    $O/sources/WaveAppMsg_m.o

# Message files
MSGFILES = \
    sources/PcnAccidentMsg.msg \
    sources/PcnInitialMsg.msg \
    sources/PcnMsg.msg \
    sources/PcnNotificationMsg.msg \
    sources/WaveAppMsg.msg

# Other makefile variables (-K)
MIXIM_PROJ=C:/Users/jdmillan/src/veins-2.0-rc2

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f calitest calitest.exe libcalitest.so libcalitest.a libcalitest.dll libcalitest.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f results/*_m.cc results/*_m.h
	-rm -f sources/*_m.cc sources/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc results/*.cc sources/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/sources/Accident.o: sources/Accident.cc \
	sources/Accident.h \
	$(MIXIM_PROJ)/src/base/connectionManager/BaseConnectionManager.h \
	$(MIXIM_PROJ)/src/base/connectionManager/ChannelAccess.h \
	$(MIXIM_PROJ)/src/base/connectionManager/NicEntry.h \
	$(MIXIM_PROJ)/src/base/messages/MacPkt_m.h \
	$(MIXIM_PROJ)/src/base/modules/BaseApplLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseBattery.h \
	$(MIXIM_PROJ)/src/base/modules/BaseLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseMobility.h \
	$(MIXIM_PROJ)/src/base/modules/BaseModule.h \
	$(MIXIM_PROJ)/src/base/modules/BaseWorldUtility.h \
	$(MIXIM_PROJ)/src/base/modules/BatteryAccess.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/FindModule.h \
	$(MIXIM_PROJ)/src/base/utils/HostState.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/Move.h \
	$(MIXIM_PROJ)/src/base/utils/NetwToMacControlInfo.h \
	$(MIXIM_PROJ)/src/base/utils/PassedMessage.h \
	$(MIXIM_PROJ)/src/base/utils/SimpleAddress.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h \
	$(MIXIM_PROJ)/src/modules/application/ieee80211p/BaseWaveApplLayer.h \
	$(MIXIM_PROJ)/src/modules/application/traci/TraCIDemo11p.h \
	$(MIXIM_PROJ)/src/modules/mac/ieee80211p/WaveAppToMac1609_4Interface.h \
	$(MIXIM_PROJ)/src/modules/messages/Mac80211Pkt_m.h \
	$(MIXIM_PROJ)/src/modules/messages/WaveShortMessage_m.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIMobility.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIScenarioManager.h \
	$(MIXIM_PROJ)/src/modules/utility/Consts80211p.h
$O/sources/App_PCN.o: sources/App_PCN.cc \
	sources/Accident.h \
	sources/App_PCN.h \
	sources/PcnAccidentMsg_m.h \
	sources/PcnInitialMsg_m.h \
	sources/PcnMsg_m.h \
	sources/PcnNotificationMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/connectionManager/BaseConnectionManager.h \
	$(MIXIM_PROJ)/src/base/connectionManager/ChannelAccess.h \
	$(MIXIM_PROJ)/src/base/connectionManager/NicEntry.h \
	$(MIXIM_PROJ)/src/base/messages/MacPkt_m.h \
	$(MIXIM_PROJ)/src/base/modules/BaseApplLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseBattery.h \
	$(MIXIM_PROJ)/src/base/modules/BaseLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseMobility.h \
	$(MIXIM_PROJ)/src/base/modules/BaseModule.h \
	$(MIXIM_PROJ)/src/base/modules/BaseWorldUtility.h \
	$(MIXIM_PROJ)/src/base/modules/BatteryAccess.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/FindModule.h \
	$(MIXIM_PROJ)/src/base/utils/HostState.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/Move.h \
	$(MIXIM_PROJ)/src/base/utils/NetwToMacControlInfo.h \
	$(MIXIM_PROJ)/src/base/utils/PassedMessage.h \
	$(MIXIM_PROJ)/src/base/utils/SimpleAddress.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h \
	$(MIXIM_PROJ)/src/modules/application/ieee80211p/BaseWaveApplLayer.h \
	$(MIXIM_PROJ)/src/modules/application/traci/TraCIDemo11p.h \
	$(MIXIM_PROJ)/src/modules/mac/ieee80211p/WaveAppToMac1609_4Interface.h \
	$(MIXIM_PROJ)/src/modules/messages/Mac80211Pkt_m.h \
	$(MIXIM_PROJ)/src/modules/messages/WaveShortMessage_m.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIMobility.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIScenarioManager.h \
	$(MIXIM_PROJ)/src/modules/utility/Consts80211p.h
$O/sources/DrgLayer.o: sources/DrgLayer.cc \
	sources/Accident.h \
	sources/DrgLayer.h \
	sources/PcnAccidentMsg_m.h \
	sources/PcnInitialMsg_m.h \
	sources/PcnMsg_m.h \
	sources/PcnNotificationMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/connectionManager/BaseConnectionManager.h \
	$(MIXIM_PROJ)/src/base/connectionManager/ChannelAccess.h \
	$(MIXIM_PROJ)/src/base/connectionManager/NicEntry.h \
	$(MIXIM_PROJ)/src/base/messages/MacPkt_m.h \
	$(MIXIM_PROJ)/src/base/modules/BaseApplLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseBattery.h \
	$(MIXIM_PROJ)/src/base/modules/BaseLayer.h \
	$(MIXIM_PROJ)/src/base/modules/BaseMobility.h \
	$(MIXIM_PROJ)/src/base/modules/BaseModule.h \
	$(MIXIM_PROJ)/src/base/modules/BaseWorldUtility.h \
	$(MIXIM_PROJ)/src/base/modules/BatteryAccess.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/FindModule.h \
	$(MIXIM_PROJ)/src/base/utils/HostState.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/Move.h \
	$(MIXIM_PROJ)/src/base/utils/NetwToMacControlInfo.h \
	$(MIXIM_PROJ)/src/base/utils/PassedMessage.h \
	$(MIXIM_PROJ)/src/base/utils/SimpleAddress.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h \
	$(MIXIM_PROJ)/src/modules/application/ieee80211p/BaseWaveApplLayer.h \
	$(MIXIM_PROJ)/src/modules/application/traci/TraCIDemo11p.h \
	$(MIXIM_PROJ)/src/modules/mac/ieee80211p/WaveAppToMac1609_4Interface.h \
	$(MIXIM_PROJ)/src/modules/messages/Mac80211Pkt_m.h \
	$(MIXIM_PROJ)/src/modules/messages/WaveShortMessage_m.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIMobility.h \
	$(MIXIM_PROJ)/src/modules/mobility/traci/TraCIScenarioManager.h \
	$(MIXIM_PROJ)/src/modules/utility/Consts80211p.h
$O/sources/PcnAccidentMsg_m.o: sources/PcnAccidentMsg_m.cc \
	sources/PcnAccidentMsg_m.h \
	sources/PcnMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h
$O/sources/PcnInitialMsg_m.o: sources/PcnInitialMsg_m.cc \
	sources/PcnInitialMsg_m.h \
	sources/PcnMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h
$O/sources/PcnMsg_m.o: sources/PcnMsg_m.cc \
	sources/PcnMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h
$O/sources/PcnNotificationMsg_m.o: sources/PcnNotificationMsg_m.cc \
	sources/PcnMsg_m.h \
	sources/PcnNotificationMsg_m.h \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h
$O/sources/WaveAppMsg_m.o: sources/WaveAppMsg_m.cc \
	sources/WaveAppMsg_m.h \
	$(MIXIM_PROJ)/src/base/utils/Coord.h \
	$(MIXIM_PROJ)/src/base/utils/FWMath.h \
	$(MIXIM_PROJ)/src/base/utils/MiXiMDefs.h \
	$(MIXIM_PROJ)/src/base/utils/miximkerneldefs.h

