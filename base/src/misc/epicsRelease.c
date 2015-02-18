/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* epicsRelease.c,v 1.16.2.1 2004/08/27 16:20:07 mrk Exp
 **/

#include    <stdlib.h>
#include    <stdio.h>
#include    "epicsVersion.h"
#include    "epicsStdioRedirect.h"

#define epicsExportSharedSymbols
#include    "epicsRelease.h"

static const char *id = "@(#) " EPICS_VERSION_STRING ", Misc. Utilities Library" __DATE__;

epicsShareFunc int epicsShareAPI coreRelease(void)
{
    printf ( "############################################################################\n" );
    printf ( "###  %s\n", "EPICS IOC CORE built on " __DATE__ );
    printf ( "###  %s\n", epicsReleaseVersion );
    printf ( "############################################################################\n" );
    return 0;
}
