#!/bin/csh -f
#*************************************************************************
# Copyright (c) 2002 The University of Chicago, as Operator of Argonne
#     National Laboratory.
# Copyright (c) 2002 The Regents of the University of California, as
#     Operator of Los Alamos National Laboratory.
# EPICS BASE Versions 3.13.7
# and higher are distributed subject to a Software License Agreement found
# in file LICENSE that is included with this distribution. 
#*************************************************************************
#  Site-specific EPICS environment settings
#
#  sites should modify these definitions

# Location of epics base
if ( ! $?EPICS_BASE ) then
	set EPICS_BASE=/usr/local/epics/base
endif

# Location of epics extensions
if ( ! $?EPICS_EXTENSIONS ) then
	setenv EPICS_EXTENSIONS /usr/local/epics/extensions
endif

# Postscript printer definition needed by some extensions (eg medm, dp, dm, ...)
if ( ! $?PSPRINTTER ) then
    setenv PSPRINTER lp
endif

# Needed only by medm extension 
#setenv EPICS_DISPLAY_PATH

# Needed only by orbitscreen extension
if ( ! $?ORBITSCREENHOME ) then
	setenv ORBITSCREENHOME $EPICS_EXTENSIONS/src/orbitscreen
endif

# Needed only by adt extension
if ( ! $?ADTHOME ) then
	setenv ADTHOME /usr/local/oag/apps/src/appconfig/adt
	echo $ADTHOME
endif

# Needed only by ar extension (archiver)
setenv EPICS_AR_PORT 7002

# Needed for java extensions
if ( $?CLASSPATH ) then
   setenv CLASSPATH "${CLASSPATH}:${EPICS_EXTENSIONS}/javalib"
else
   setenv CLASSPATH "${EPICS_EXTENSIONS}/javalib"
endif

# Allow private versions of extensions without a bin subdir
if ( $?EPICS_EXTENSIONS_PVT ) then
    set path = ( $path $EPICS_EXTENSIONS_PVT)
endif

##################################################################

# Start of set R3.14 environment variables

setenv EPICS_HOST_ARCH `$EPICS_BASE/startup/EpicsHostArch.pl`

# Allow private versions of base
if ( $?EPICS_BASE_PVT ) then
   if ( -e $EPICS_BASE_PVT/bin/$EPICS_HOST_ARCH ) then
      set path = ( $path $EPICS_BASE_PVT/bin/$EPICS_HOST_ARCH)
   endif
endif

# Allow private versions of extensions
if ( $?EPICS_EXTENSIONS_PVT ) then
   if ( -e $EPICS_EXTENSIONS_PVT/bin/$EPICS_HOST_ARCH ) then
      set path = ( $path $EPICS_EXTENSIONS_PVT/bin/$EPICS_HOST_ARCH)
   endif
endif
set path = ( $path $EPICS_EXTENSIONS/bin/$EPICS_HOST_ARCH )

# End of set R3.14 environment variables
##################################################################


## Start of set pre R3.14 environment variables
#
## Time service:
## EPICS_TS_MIN_WEST the local time difference from GMT.
#setenv EPICS_TS_MIN_WEST 360
#
#if ( -e /usr/local/etc/setup/HostArch.pl ) then
#   setenv HOST_ARCH `/usr/local/etc/setup/HostArch.pl`
#else
#   setenv HOST_ARCH `/usr/local/epics/startup/HostArch.pl`
#endif
#
## Allow private versions of extensions
#if ( $?EPICS_EXTENSIONS_PVT ) then
#   if ( -e $EPICS_EXTENSIONS_PVT/bin/$HOST_ARCH ) then
#      set path = ( $path $EPICS_EXTENSIONS_PVT/bin/$HOST_ARCH)
#   endif
#   # Needed if shared extension libraries are built
#   if ( -e $EPICS_EXTENSIONS_PVT/lib/$HOST_ARCH ) then
#      if ( $?LD_LIBRARY_PATH ) then
#         setenv LD_LIBRARY_PATH "${LD_LIBRARY_PATH}:${EPICS_EXTENSIONS_PVT}/lib/${HOST_ARCH}"
#      else
#         setenv LD_LIBRARY_PATH "${EPICS_EXTENSIONS_PVT}/lib/${HOST_ARCH}"
#      endif
#   endif
#endif
#
#set path = ( $path $EPICS_EXTENSIONS/bin/$HOST_ARCH )
## Needed if shared extension libraries are built
#setenv LD_LIBRARY_PATH "${LD_LIBRARY_PATH}:${EPICS_EXTENSIONS}/lib/${HOST_ARCH}"

# End of set pre R3.14 environment variables
##################################################################
