#ifndef ATOMIC_PRIMITIVES_H
#define ATOMIC_PRIMITIVES_H

#include <stdbool.h>


static inline long __atomic_cas(volatile long *p, long test, long set){
		
		// Helpful article: http://infocenter.arm.com/help/topic/com.arm.doc.dht0008a/DHT0008A_arm_synchronization_primitives.pdf
		
		register long r0 asm("r0") = test;
		register long r1 asm("r1") = set;
		register volatile long *r2 asm("r2") = p;
		long prev_val, result;

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
