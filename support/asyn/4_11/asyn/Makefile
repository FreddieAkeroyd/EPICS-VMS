#*************************************************************************
# Copyright (c) 2002 The University of Chicago, as Operator of Argonne
#     National Laboratory.
# Copyright (c) 2002 The Regents of the University of California, as
#     Operator of Los Alamos National Laboratory.
# EPICS BASE Versions 3.13.7
# and higher are distributed subject to a Software License Agreement found
# in file LICENSE that is included with this distribution. 
#*************************************************************************
TOP = ..
include $(TOP)/configure/CONFIG

ASYN = $(TOP)/asyn
#USR_CFLAGS += -DDEBUG

# The following gets rid of the -fno-implicit-templates flag on vxWorks, 
# so we get automatic template instantiation.
# This is what we want for miscellaneous/asynPortDriver.cpp
ifeq (vxWorks,$(findstring vxWorks, $(T_A)))
CODE_CXXFLAGS=
endif

LIBRARY_IOC += asyn
asyn_LIBS += $(EPICS_BASE_IOC_LIBS)
asyn_SYS_LIBS_WIN32 = ws2_32
asyn_SYS_LIBS_cygwin32 = rpc

SRC_DIRS += $(ASYN)/asynDriver
INC += asynDriver.h
INC += epicsInterruptibleSyscall.h
asyn_SRCS += asynManager.c
asyn_SRCS += epicsInterruptibleSyscall.c

SRC_DIRS += $(ASYN)/asynGpib
INC += asynGpibDriver.h
asyn_SRCS += asynGpib.c

SRC_DIRS += $(ASYN)/drvAsynSerial
INC += drvAsynSerialPort.h
ifeq ($(OS_CLASS), WIN32)
asyn_SRCS += drvAsynSerialPortWin32.c
else
ifeq ($(OS_CLASS), VMS)
asyn_SRCS += drvAsynSerialPortWin32.c
else
asyn_SRCS += drvAsynSerialPort.c
endif
endif
DBD += drvAsynSerialPort.dbd
INC += drvAsynIPPort.h
asyn_SRCS += drvAsynIPPort.c
asyn_SRCS += drvAsynIPServerPort.c
DBD += drvAsynIPPort.dbd
INC += drvAsynIPServerPort.h

SRC_DIRS += $(ASYN)/interfaces
INC += asynInt32.h         asynInt32SyncIO.h
INC += asynUInt32Digital.h asynUInt32DigitalSyncIO.h
INC += asynFloat64.h       asynFloat64SyncIO.h
INC += asynInt8Array.h     asynInt8ArraySyncIO.h
INC += asynInt16Array.h    asynInt16ArraySyncIO.h
INC += asynInt32Array.h    asynInt32ArraySyncIO.h
INC += asynFloat32Array.h  asynFloat32ArraySyncIO.h
INC += asynFloat64Array.h  asynFloat64ArraySyncIO.h
INC += asynOctet.h         asynOctetSyncIO.h
INC += asynGenericPointer.h asynGenericPointerSyncIO.h
INC += asynCommonSyncIO.h
INC += asynOption.h
INC += asynDrvUser.h
INC += asynStandardInterfaces.h
asyn_SRCS += asynInt32Base.c         asynInt32SyncIO.c
asyn_SRCS += asynInt8ArrayBase.c     asynInt8ArraySyncIO.c
asyn_SRCS += asynInt16ArrayBase.c    asynInt16ArraySyncIO.c
asyn_SRCS += asynInt32ArrayBase.c    asynInt32ArraySyncIO.c
asyn_SRCS += asynUInt32DigitalBase.c asynUInt32DigitalSyncIO.c
asyn_SRCS += asynFloat64Base.c       asynFloat64SyncIO.c
asyn_SRCS += asynFloat32ArrayBase.c  asynFloat32ArraySyncIO.c
asyn_SRCS += asynFloat64ArrayBase.c  asynFloat64ArraySyncIO.c
asyn_SRCS += asynOctetBase.c         asynOctetSyncIO.c
asyn_SRCS += asynGenericPointerBase.c  asynGenericPointerSyncIO.c
asyn_SRCS += asynCommonSyncIO.c
asyn_SRCS += asynStandardInterfacesBase.c

SRC_DIRS += $(ASYN)/miscellaneous
DBD += asyn.dbd
INC += asynShellCommands.h
INC += asynInterposeEos.h
INC += asynInterposeFlush.h
INC += asynPortDriver.h
asyn_SRCS += asynShellCommands.c
asyn_SRCS += asynInterposeEos.c
asyn_SRCS += asynInterposeFlush.c
asyn_SRCS += asynPortDriver.cpp

SRC_DIRS += $(ASYN)/devEpics
DBD += devAsynOctet.dbd
DBD += devAsynInt32.dbd
DBD += devAsynInt8Array.dbd
DBD += devAsynInt16Array.dbd
DBD += devAsynInt32Array.dbd
DBD += devAsynUInt32Digital.dbd
DBD += devAsynFloat64.dbd
DBD += devAsynFloat32Array.dbd
DBD += devAsynFloat64Array.dbd
DBD += devEpics.dbd
INC += asynEpicsUtils.h
asyn_SRCS += devAsynOctet.c
asyn_SRCS += asynEpicsUtils.c
asyn_SRCS += devAsynInt32.c
asyn_SRCS += devAsynInt8Array.c
asyn_SRCS += devAsynInt16Array.c
asyn_SRCS += devAsynInt32Array.c
asyn_SRCS += devAsynUInt32Digital.c
asyn_SRCS += devAsynFloat64.c
asyn_SRCS += devAsynFloat32Array.c
asyn_SRCS += devAsynFloat64Array.c

SRC_DIRS += $(ASYN)/asynRecord
DBDINC += asynRecord
DBD += devAsynRecord.dbd
asyn_SRCS += asynRecord.c
asyn_SRCS += drvAsyn.c
DB += asynRecord.db

SRC_DIRS += $(ASYN)/vxi11
ifeq ($(OS_CLASS), WIN32)
asyn_SRCS += drvVxi11Win32.c
else
ifeq ($(OS_CLASS), VMS)
asyn_SRCS += drvVxi11Win32.c
else
#asyn_SRCS += vxi11core_xdr.c
#asyn_SRCS += drvVxi11.c
asyn_SRCS += drvVxi11Win32.c
endif
endif
asyn_SRCS += E5810Reboot.c
asyn_SRCS += E2050Reboot.c
asyn_SRCS += TDS3000Reboot.c
DBD += drvVxi11.dbd

ifdef IPAC
SRC_DIRS += $(ASYN)/gsIP488
asyn_SRCS_vxWorks += drvGsIP488.c
asyn_SRCS_RTEMS += drvGsIP488.c
DBD += drvGsIP488.dbd
asyn_LIBS_vxWorks += Ipac
asyn_LIBS_RTEMS += Ipac
endif

SRC_DIRS += $(ASYN)/ni1014
asyn_SRCS_vxWorks += drvNi1014.c
asyn_SRCS_RTEMS += drvNi1014.c
DBD += drvNi1014.dbd

ifeq ($(LINUX_GPIB),YES)
SRC_DIRS += $(ASYN)/linuxGpib
asyn_SRCS_Linux += drvLinuxGpib.c
DBD += drvLinuxGpib.dbd
asyn_LIBS += gpib
endif

SRC_DIRS += $(ASYN)/devGpib
INC += devGpib.h
INC += devSupportGpib.h
INC += devCommonGpib.h
DBD += devGpib.dbd
asyn_SRCS += devCommonGpib.c
asyn_SRCS += devSupportGpib.c
asyn_SRCS += boSRQonOff.c

include $(TOP)/configure/RULES

ifdef T_A
ifeq ($(OS_CLASS),vxWorks)
vxi11core_xdr.c: ../vxi11/rpc/vxi11core_xdr.c
	cp ../vxi11/rpc/*.[ch] .
else
ifeq ($(OS_CLASS),RTEMS)
vxi11core_xdr.c: ../vxi11/rpc/vxi11core_xdr.c
	cp ../vxi11/rpc/*.[ch] .
else
RPCGEN_FLAGS_solaris = -M
vxi11core_xdr.c: ../vxi11/vxi11core.rpcl ../vxi11/vxi11intr.rpcl
	cp ../vxi11/vxi11core.rpcl .
	cp ../vxi11/vxi11intr.rpcl .
	rpcgen $(RPCGEN_FLAGS_$(OS_CLASS)) vxi11core.rpcl
	rpcgen $(RPCGEN_FLAGS_$(OS_CLASS)) vxi11intr.rpcl
endif
endif
endif
