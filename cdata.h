/*
 * cdata.h: arquivo de inclusão de uso apenas na geração da libpithread
 *
 * Esse arquivo pode ser modificado. ENTRETANTO, deve ser utilizada a TCB fornecida.
 *
 */
#ifndef __cdata__
#define __cdata__

#include "ucontext.h"

#define	PROCST_CRIACAO	    0
#define	PROCST_APTO	        1
#define	PROCST_EXEC	        2
#define	PROCST_BLOQ	        3
#define	PROCST_TERMINO	    4

#define BOOL    int
#define TRUE    1
#define FALSE   0
#define NULL    0

#define Function(func)  void*(*func)(void*)

/* NÃO ALTERAR ESSA struct */
typedef struct s_TCB {
	int		tid; 		// identificador da thread
	int		state;		// estado em que a thread se encontra
					// 0: Criação; 1: Apto; 2: Execução; 3: Bloqueado e 4: Término
	ucontext_t 	context;	// contexto de execução da thread (SP, PC, GPRs e recursos)
} TCB_t;

typedef struct _Thread
{
    // Os dados internos da thread
    TCB_t threadData;

    // Se fomos "vitma" de um yield
    BOOL yieldVictim;

    // Alguma thread que esta esperando o nosso termino
    struct _Thread* waitingThread;

    // Se estamos esperando o termino de alguma thread
    BOOL waitingForThread;

    // Se estamos esperando por um semaforo
    BOOL waitingForSignal;

    // Se a thread acabou a execução
    BOOL finishedExecution;

} Thread;

#endif
