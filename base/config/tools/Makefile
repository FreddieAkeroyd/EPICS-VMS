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
# Makefile,v 1.2.2.3 2004/01/23 18:09:16 jba Exp
#

TOP=../..

include $(TOP)/configure/CONFIG

ifeq ($(findstring YES,$(COMPAT_313) $(COMPAT_TOOLS_313)),YES)
SCRIPTS_HOST += $(subst ../,,$(wildcard ../*.pl)) 
SCRIPTS_HOST += installEpics
endif

include $(TOP)/configure/RULES

