#include "../include/unistd.h"
#include "internals/syscall.h"

void exit(int status){
	__syscall1(60,status);
}
