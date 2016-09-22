#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <string.h>

#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/cthreadAux.h"

// --- Variáveis Globais --- //

PFILA2 *filaAble;
PFILA2 *filaExec;
PFILA2 *filaBlocked;

// --- Funções --- //

int ccreate (void* (*start)(void*), void *arg)
{
	//Inicializa as estruturas (pela primeira vez apenas)
	static BOOLEAN initStruct = FALSE;
	
	if (initStruct == FALSE)
	{	
		
		//Inicializa as três filas:

		//1. Aptos
		filaAble = malloc(sizeof(PFILA2));
		CreateFila2(*filaAble);

		//2. Executando
		filaExec = malloc(sizeof(PFILA2));
		CreateFila2(*filaExec);
		
		//3. Bloqueados
		filaBlocked = malloc(sizeof(PFILA2));
		CreateFila2(*filaBlocked);
		
		//Cria a thread main (e salva seu contexto)
		//Inicialização do TCB da thread main tid = 0
		Thread_t* newThread = CreateNewThread(initStruct);

		//Seta a nova thread para a thread atual
		        // Cria um novo contexto
       		//newThread->data.context = CreateNewContext(&ThreadFinished, NULL, &ThreadFinished);


		//Marca a inicialização como pronta
		initStruct = TRUE;
	}
	
	Thread_t* newThread = CreateNewThread(initStruct);
	
	//Cria contexto 
	
	//Adiciona a nova thread na fila de aptos
	AppendFila2(*filaAble, newThread);

	return newThread->data.tid;
}

int cyield(void)
{

	return 0;
}

int cjoin(int tid)
{
	
	return 0;
}

int csem_init(csem_t *sem, int count)
{
	
	return 0;
}

int cwait(csem_t *sem)
{
	
	return 0;
}

int csignal(csem_t *sem)
{
	
	return 0;
}

int cidentify (char *name, int size)
{
	int i = 0;
	char grupo[] = "Ana Mativi\nAthos Lagemann\nRicardo Sabedra";

	if (size > sizeof(grupo))
		return -1;

	for (i = 0; i < size; i++)
		aux[i] = grupo[i];

	return 0;
}
