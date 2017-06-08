#ifndef STDLIB_H
#define STDLIB_H

#include "stddef.h"

#define EXIT_FAILURE -1
#define EXIT_SUCCESS 0

#define RAND_MAX 4294967295

void *malloc(size_t);
void free(void *);
int rand(void);


void exit(int status);


#endif
