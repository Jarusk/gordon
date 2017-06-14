#include <__syscall.h>
#include "../../include/unistd.h"

ssize_t write(int fd, const void *buf, size_t n){
	return (ssize_t)__syscall3(SYS_write,(long)fd,(long)buf,(long)n);
}
