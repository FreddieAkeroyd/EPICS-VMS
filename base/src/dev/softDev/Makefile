#*************************************************************************
# Copyright (c) 2002 The University of Chicago, as Operator of Argonne
#     National Laboratory.
# Copyright (c) 2002 The Regents of the University of California, as
#     Operator of Los Alamos National Laboratory.
# EPICS BASE Versions 3.13.7
# and higher are distributed subject to a Software License Agreement found
# in file LICENSE that is included with this distribution. 
#*************************************************************************
TOP=../../..

include $(TOP)/configure/CONFIG

DBD += devSoft.dbd

LIBSRCS += devAiSoft.c
LIBSRCS += devAiSoftRaw.c
LIBSRCS += devAoSoft.c
LIBSRCS += devAoSoftRaw.c
LIBSRCS += devBiSoft.c
LIBSRCS += devBiSoftRaw.c
LIBSRCS += devBoSoft.c
LIBSRCS += devBoSoftRaw.c
LIBSRCS += devCalcoutSoft.c
LIBSRCS += devEventSoft.c
LIBSRCS += devHistogramSoft.c
LIBSRCS += devLiSoft.c
LIBSRCS += devLoSoft.c
LIBSRCS += devMbbiDirectSoft.c
LIBSRCS += devMbbiDirectSoftRaw.c
LIBSRCS += devMbbiSoft.c
LIBSRCS += devMbbiSoftRaw.c
LIBSRCS += devMbboDirectSoft.c
LIBSRCS += devMbboDirectSoftRaw.c
LIBSRCS += devMbboSoft.c
LIBSRCS += devMbboSoftRaw.c
LIBSRCS += devSASoft.c
LIBSRCS += devSiSoft.c
LIBSRCS += devSoSoft.c
LIBSRCS += devWfSoft.c

LIBSRCS += devAoSoftCallback.c
LIBSRCS += devBoSoftCallback.c
LIBSRCS += devCalcoutSoftCallback.c
LIBSRCS += devLoSoftCallback.c
LIBSRCS += devMbboSoftCallback.c
LIBSRCS += devMbboDirectSoftCallback.c
LIBSRCS += devSoSoftCallback.c

LIBSRCS += devTimestampSI.c

LIBRARY_IOC += softDevIoc
softDevIoc_LIBS += recIoc asIoc dbIoc registryIoc dbStaticIoc ca Com
softDevIoc_RCS_WIN32 = softDevIoc.rc

# For R3.13 compatability
ifeq ($(strip $(COMPAT_313)),YES)
OBJS_vxWorks = $(LIBSRCS:%.c=%)
endif

include $(TOP)/configure/RULES


