#ifndef ATOMIC_PRIMITIVES_H
#define ATOMIC_PRIMITIVES_H

#include <stdbool.h>


static inline long __atomic_cas(volatile long *p, long test, long set){
	asm volatile ();
	return test;
}


static inline long __atomic_swap(volatile long *p, long val){
	asm volatile (
					);
	return val;
}


static inline long __atomic_fetch_add(volatile long *p, long val){
	asm volatile (
					);
	return val;
}


static inline void __atomic_inc(volatile long *p){
	asm volatile (
					);
}


static inline void __atomic_dec(volatile long *p){
	asm volatile (
					);
}


static inline void __atomic_spin(){
	asm volatile (
					);
}


#endif
