#include "../internals/syscall.h"
#include "../../include/unistd.h"

ssize_t write(int fd, const void *buf, size_t n){
	return (ssize_t)__syscall3(1,(long)fd,(long)buf,(long)n);
}
