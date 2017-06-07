#include "syscall.h"

inline long __syscall0(long num){
	unsigned long result;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num)
		:"memory","rcx","r11"
		);

	return result;
}


inline long __syscall1(long num, long arg1){
	unsigned long result;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1)
		:"memory","rcx","r11"
		);
	return result;
}

inline long __syscall2(long num, long arg1, long arg2){
	unsigned long result;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1),"rsi"(arg2)
		:"memory","rcx","r11"
		);
	return result;
}

inline long __syscall3(long num, long arg1, long arg2, long arg3){
	unsigned long result;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1),"rsi"(arg2),"rdx"(arg3)
		:"memory","rcx","r11"
		);
	return result;
}

inline long __syscall4(long num, long arg1, long arg2, long arg3, long arg4){
	unsigned long result;

	register long r10 asm("r10") = arg4;
	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1),"rsi"(arg2),"rdx"(arg3),"r"(r10)
		:"memory","rcx","r11"
		);
	return result;
}

inline long __syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5){
	unsigned long result;
	
	register long r10 asm("r10") = arg4;
	register long r8 asm("r8") = arg5;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1),"rsi"(arg2),"rdx"(arg3),"r"(r10),"r"(r8)
		:"memory","rcx","r11"
		);
	return result;
}


inline long __syscall6(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6){
	unsigned long result;
	
	register long r10 asm("r10") = arg4;
	register long r8 asm("r8") = arg5;
	register long r9 asm("r9") = arg6;

	asm (
		"syscall"
		:"=rax"(result)
		:"rax"(num),"rdi"(arg1),"rsi"(arg2),"rdx"(arg3),"r"(r10),"r"(r8),"r"(r9)
		:"memory","rcx","r11"
		);
	return result;
}
