#ifndef ATOMIC_PRIMITIVES_H
#define ATOMIC_PRIMITIVES_H

#include <stdbool.h>


static inline long __atomic_cas(volatile long *p, long test, long set){
	asm volatile (
					"lock; cmpxchg %3, %1"
					: "=a"(test), "=m"(*p)
					: "a"(test), "r"(set)
					: "memory"
					);
	return test;
}


static inline long __atomic_swap(volatile long *p, long val){
	asm volatile (
					"xchg %0, %1"
					: "=r"(val), "=m"(*p)
					: "0"(val)
					: "memory"
					);
	return val;
}


static inline long __atomic_fetch_add(volatile long *p, long val){
	asm volatile (
					"lock; xadd %0, %1"
					: "=r"(val), "=m"(*p)
					: "0"(val)
					: "memory"
					);
	return val;
}


static inline void __atomic_inc(volatile long *p){
	asm volatile (
					"lock; incq %0"
					: "=m"(*p)
					: "m"(*p)
					: "memory"
					);
}


static inline void __atomic_dec(volatile long *p){
	asm volatile (
					"lock; decq %0"
					: "=m"(*p)
					: "m"(*p)
					: "memory"
					);
}


static inline void __atomic_spin(){
	asm volatile (
					"pause"
					: 
					: 
					: "memory"
					);
}


#endif
