#ifndef INTERNAL_LOCK_H
#define INTERNAL_LOCK_H

#include <stdbool.h>

typedef bool INT_LOCK;
#define LOCKED true
#define UNLOCKED false

inline long lock_acquire(INT_LOCK lock){
	unsigned long result;

	asm volatile (
		"syscall"
		:"=a"(result)
		:"a"(num)
		:"memory","rcx","r11"
		);

	return result;
}


#endif
