#ifndef STDDEF_H
#define STDDEF_H

#undef NULL
#define NULL ((void *)0)

typedef unsigned long size_t;
typedef size_t off_t;
typedef signed long ssize_t;
typedef void * ptrdiff_t;
typedef unsigned long wchar_t;

#endif
