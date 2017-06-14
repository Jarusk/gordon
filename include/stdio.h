#ifndef STDIO_H
#define STDIO_H

#include <stddef.h>

typedef struct FILE FILE;

extern FILE *const stdin, stdout, stderr;

#undef EOF
#define EOF (-1)



#endif
