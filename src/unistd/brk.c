#include "../internals/syscall.h"
#include "../../include/unistd.h"

int brk(void *addr){
	long old = __syscall1(SYS_brk,0);
	long new = __syscall1(SYS_brk,(long)addr);
	return old==new ? -1 : 0;
}

