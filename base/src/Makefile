#*************************************************************************
# Copyright (c) 2002 The University of Chicago, as Operator of Argonne
#     National Laboratory.
# Copyright (c) 2002 The Regents of the University of California, as
#     Operator of Los Alamos National Laboratory.
# EPICS BASE Versions 3.13.7
# and higher are distributed subject to a Software License Agreement found
# in file LICENSE that is included with this distribution. 
#*************************************************************************
#
# Makefile,v 1.41.2.4 2004/01/26 01:30:01 jba Exp
#

TOP = ..
include $(TOP)/configure/CONFIG

#
# for c++ build add the dirs gdd and cas after ca
# (and uncomment the c++ files in src/lbCom/Makefile.Unix)
#
DIRS += makeBaseApp
DIRS += makeBaseExt
DIRS += libCom
DIRS += toolsComm
DIRS += ca
DIRS += dbStatic
DIRS += registry
DIRS += bpt
DIRS += db
DIRS += db/test
DIRS += as
DIRS += util
DIRS += dbtools
DIRS += catools
DIRS += rsrv
DIRS += rec
DIRS += dev
DIRS += misc
DIRS += iocsh
DIRS += vxWorks
DIRS += RTEMS
DIRS += softIoc
DIRS += libCom/test
DIRS += gdd
DIRS += cas
DIRS += excas

include $(TOP)/configure/RULES_DIRS

