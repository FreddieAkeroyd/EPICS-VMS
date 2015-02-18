/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

//
// Verify that the local c++ exception mechanism maches the ANSI/ISO standard.
// Author: Jeff Hill
//

#include <new>
#include <iostream>
#if defined(__GNUC__) && (__GNUC__<2 || (__GNUC__==2 && __GNUC_MINOR__<=96))
#include <climits>
#else
#include <limits>
#endif

#include <assert.h>
#include <stdio.h>

#include "epicsThread.h"

using namespace std;

#if defined(__BORLANDC__) && defined(__linux__)
namespace  std  {
const nothrow_t  nothrow ;
}
#endif

#if defined ( _MSC_VER )
    // some interesting bugs found in the MS implementation of new
#   if _MSC_VER > 1310  /* this gets fixed some release after visual studio 7 we hope */
        static const size_t unsuccessfulNewSize = numeric_limits<size_t>::max();
#   else
        static const size_t unsuccessfulNewSize = numeric_limits<size_t>::max()-100;
#   endif
#elif defined(__GNUC__) && (__GNUC__<2 || (__GNUC__==2 && __GNUC_MINOR__<=96))
    // tornado does not supply ansi c++
    static const size_t unsuccessfulNewSize = UINT_MAX;
#else
    static const size_t unsuccessfulNewSize = numeric_limits<size_t>::max();
#endif

class exThread : public epicsThreadRunable {
public:
    exThread ();
    void waitForCompletion ();
private:
    epicsThread thread;
    bool done;
    void run ();
};

static void epicsExceptionTestPrivate ()
{
    int excep = false;
    try {
        new char [unsuccessfulNewSize];
        assert ( 0 );
    }
    catch ( const bad_alloc & ) {
        excep = true;
    }
    catch ( ... ) {
        assert ( 0 );
    }
    try {
        char * p = new ( nothrow ) 
            char [unsuccessfulNewSize];
        assert ( p == 0);
    }
    catch( ... ) {
        assert ( 0 );
    }
}

exThread::exThread () :
    thread ( *this, "testExceptions", epicsThreadGetStackSize(epicsThreadStackSmall) ),
        done ( false )
{
    this->thread.start ();
}

void exThread::run ()
{
    epicsExceptionTestPrivate ();
    this->done = true;
}

void exThread::waitForCompletion ()
{
    while ( ! this->done ) {
        epicsThreadSleep ( 0.1 );
    }
}

extern "C" void epicsExceptionTest ()
{
    exThread athread;

    epicsExceptionTestPrivate ();

    athread.waitForCompletion ();

    printf ( "Test Complete.\n" );
}
