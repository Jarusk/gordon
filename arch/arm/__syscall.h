#ifndef __SYSCALL_H
#define __SYSCALL_H

#include <syscall.h>

static inline long __syscall0(long num){
	register long r7 asm("r7") = num;
	register long r0 asm("r0");

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7)
		:"memory"
		);

	return r0;
}

static inline long __syscall1(long num, long arg1){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0)
		:"memory"
		);

	return r0;
}

static inline long __syscall2(long num, long arg1, long arg2){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;
	register long r1 asm("r1") = arg2;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0), "r"(r1)
		:"memory"
		);

	return r0;
}

static inline long __syscall3(long num, long arg1, long arg2, long arg3){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;
	register long r1 asm("r1") = arg2;
	register long r2 asm("r2") = arg3;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0), "r"(r1), "r"(r2)
		:"memory"
		);

	return r0;
}

static inline long __syscall4(long num, long arg1, long arg2, long arg3, long arg4){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;
	register long r1 asm("r1") = arg2;
	register long r2 asm("r2") = arg3;
	register long r3 asm("r3") = arg4;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0), "r"(r1), "r"(r2), "r"(r3)
		:"memory"
		);

	return r0;
}

static inline long __syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;
	register long r1 asm("r1") = arg2;
	register long r2 asm("r2") = arg3;
	register long r3 asm("r3") = arg4;
	register long r4 asm("r4") = arg5;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0), "r"(r1), "r"(r2), "r"(r3), "r"(r4)
		:"memory"
		);

	return r0;
}

static inline long __syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6){
	register long r7 asm("r7") = num;
	register long r0 asm("r0") = arg1;
	register long r1 asm("r1") = arg2;
	register long r2 asm("r2") = arg3;
	register long r3 asm("r3") = arg4;
	register long r4 asm("r4") = arg5;
	register long r5 asm("r5") = arg6;

	asm volatile (
		"svc 0"
		:"=r"(r0)
		:"r"(r7), "0"(r0), "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5)
		:"memory"
		);

	return r0;
}


#endif
