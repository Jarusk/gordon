#include <__syscall.h>

void exit(int status){
	__syscall1(SYS_exit,(long)status);
}
