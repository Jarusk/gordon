#include "../internals/syscall.h"
#include "../../include/unistd.h"

int brk(void *addr){
	long old = __syscall1(12,0);
	long new = __syscall1(12,(long)addr);
	return old==new ? -1 : 0;
}

