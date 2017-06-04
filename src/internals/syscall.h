#ifndef __SYSCALL_H
#define __SYSCALL_H

inline long __syscall0(long num);
inline long __syscall1(long num, long arg1);
inline long __syscall2(long num, long arg1, long arg2);
inline long __syscall3(long num, long arg1, long arg2, long arg3);
inline long __syscall4(long num, long arg1, long arg2, long arg3, long arg4);
inline long __syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5);
inline long __syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#endif
