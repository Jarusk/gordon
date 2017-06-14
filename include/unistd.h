#ifndef UNISTD_H
#define UNISTD_H

#include "stddef.h"

#define STDIN_FILNO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

int brk(void *addr);
void exit(int status);
ssize_t write(int fd, const void *buf, size_t n);

#endif
