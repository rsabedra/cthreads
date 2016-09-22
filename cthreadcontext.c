//////////////
// INCLUDES //
//////////////
#include "cthreadcontext.h"
#include "cdata.h"
#include "cthread.h"
#include <string.h>

ucontext_t CreateNewContext(Function(_func), void *_arg, Function(_endFunc))
{
	ucontext_t newContext;

	// Warning supress
	typedef void(*PiFunc)();

	// Get the current context
	getcontext(&newContext);

	// Set the new context data
	if(_func == _endFunc)
    {
        newContext.uc_link = NULL;
    }
    else
    {
        ucontext_t tempContext = CreateNewContext(_endFunc, NULL, NULL);
        ucontext_t* temp = (ucontext_t*)malloc(sizeof(ucontext_t));
        memcpy(temp, &tempContext, sizeof(ucontext_t));
        newContext.uc_link = temp;
    }
	newContext.uc_stack.ss_size = SIGSTKSZ;
	if ((newContext.uc_stack.ss_sp = malloc(newContext.uc_stack.ss_size)) == NULL)
	{
		perror("malloc"), exit(1);
	}
	newContext.uc_stack.ss_flags = 0;

	// Create the new context
	makecontext(&newContext, (PiFunc)_func, 1, _arg);

	return newContext;
}

// Salva uma ponto de continuação para o contexto selecionado
void SetContinuePoint(ucontext_t* _context)
{
	// Get the current context
	getcontext(_context);
}
