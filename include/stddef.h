#ifndef STDDEF_H
#define STDDEF_H

#undef NULL
#define NULL ((void *)0)

typedef long _Addr;
typedef __SIZE_TYPE__ size_t;
typedef signed long ssize_t;
typedef __PTRDIFF_TYPE__  ptrdiff_t;
typedef __WCHAR_TYPE__ wchar_t;

#endif
