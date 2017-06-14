#ifndef STDDEF_H
#define STDDEF_H

#undef NULL
#define NULL ((void *)0)

typedef __SIZE_TYPE__ size_t;
typedef size_t off_t;
typedef signed long ssize_t;
typedef __PTRDIFF_TYPE__  ptrdiff_t;
typedef unsigned long wchar_t;

#endif
