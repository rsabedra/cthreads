///////////////
// GUARDIANS //
///////////////
#ifndef cthreadcontext
#define cthreadcontext

//////////////
// INCLUDES //
//////////////
#include "ucontext.h"
#include "cdata.h"

ucontext_t CreateNewContext(Function(_func), void *_arg, Function(_endFunc));


#endif
