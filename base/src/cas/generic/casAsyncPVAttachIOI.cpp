
/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/*
 *      casAsyncPVAttachIOI.cpp,v 1.4.2.1 2003/09/29 22:58:41 jhill Exp
 *
 *      Author  Jeffrey O. Hill
 *              johill@lanl.gov
 *              505 665 1831
 */

#define epicsExportSharedSymbols
#include "casAsyncPVAttachIOI.h"

casAsyncPVAttachIOI::casAsyncPVAttachIOI (
        casAsyncPVAttachIO & intf, const casCtx & ctx ) :
	casAsyncIOI ( ctx ), msg ( *ctx.getMsg() ),
    asyncPVAttachIO ( intf ), retVal ( S_cas_badParameter )
{
    ctx.getClient()->installAsynchIO ( *this );
}

caStatus casAsyncPVAttachIOI::postIOCompletion ( const pvAttachReturn & retValIn )
{
	this->retVal = retValIn; 
	return this->insertEventQueue ();
}

caStatus casAsyncPVAttachIOI::cbFuncAsyncIO ( 
    epicsGuard < casClientMutex > & guard )
{
	caStatus 	status;

    // uninstall here in case the channel is deleted 
    // further down the call stack
    this->client.uninstallAsynchIO ( *this );

	if ( this->msg.m_cmmd == CA_PROTO_CREATE_CHAN ) {
        casCtx tmpCtx;
        tmpCtx.setMsg ( this->msg, 0 );
        tmpCtx.setServer ( & this->client.getCAS() );
        tmpCtx.setClient ( & this->client );
		status = this->client.createChanResponse ( guard,
                        tmpCtx, this->retVal );
    }
    else {
        errPrintf ( S_cas_invalidAsynchIO, __FILE__, __LINE__,
            " - client request type = %u", this->msg.m_cmmd );
		status = S_cas_invalidAsynchIO;
	}

    if ( status == S_cas_sendBlocked ) {
        this->client.installAsynchIO ( *this );
    }

	return status;
}

