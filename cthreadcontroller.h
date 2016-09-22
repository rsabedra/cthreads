///////////////
// GUARDIANS //
///////////////
#ifndef cthreadcontroller
#define cthreadcontroller

//////////////
// INCLUDES //
//////////////
#include "cthread.h"

int GetNewThreadTid()
{
    static int globalThreadTid = 0;

    return ++globalThreadTid;
}

Thread* CreateNewThread()
{
    Thread* newThread = (Thread*)malloc(sizeof(Thread));
    newThread->threadData.state = PROCST_CRIACAO; // PROCST_BLOQ
    newThread->threadData.tid = GetNewThreadTid();
    newThread->yieldVictim = FALSE;
    newThread->waitingThread = NULL;
    newThread->waitingForThread = FALSE;
    newThread->finishedExecution = FALSE;
    newThread->waitingForSignal = FALSE;

    return newThread;
}


#endif
