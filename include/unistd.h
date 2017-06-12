#ifndef UNISTD_H
#define UNISTD_H

#include "stddef.h"

int brk(void *addr);
void exit(int status);
ssize_t write(int fd, const void *buf, size_t n);

#endif
