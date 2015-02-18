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
 *      epicsTimerTestMain.cpp,v 1.3.2.1 2004/09/16 14:03:04 norume Exp
 *
 *      Author  Jeffrey O. Hill
 *              johill@lanl.gov
 *              505 665 1831
 *
 */

extern "C" void epicsTimerTest ( void );

int main ( int /* argc */, char /* *argv[] */ )
{
    epicsTimerTest ();
    return 0;
}
