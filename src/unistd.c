#include "internals/syscall.h"
#include "../include/unistd.h"

int brk(void *addr){
	long old = __syscall1(12,0);
	long new = __syscall1(12,(long)addr);
	return old==new ? -1 : 0;
}

ssize_t write(int fd, const void *buf, size_t n){
	return (ssize_t)__syscall3(1,(long)fd,(long)buf,(long)n);
}
