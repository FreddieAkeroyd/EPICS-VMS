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
# Makefile,v 1.47.2.3 2004/03/05 15:38:48 jba Exp
#

TOP = .
include $(TOP)/configure/CONFIG

ifeq ($(findstring YES,$(COMPAT_313) $(COMPAT_TOOLS_313)),YES)
DIRS += config config/tools
endif
DIRS += configure src

include $(TOP)/configure/RULES_TOP

