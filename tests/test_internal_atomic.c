#include "../include/stdio.h"
#include "../include/stdlib.h"
#include "../include/stdbool.h"
#include "../arch/x86_64/atomic_primitives.h"

int main(int argc, char **argv){
	long lock = 0;
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_dec(&lock);
	printf("lock: %ld\n",lock);
	__atomic_dec(&lock);
	printf("lock: %ld\n",lock);
	__atomic_dec(&lock);
	printf("lock: %ld\n",lock);
	__atomic_dec(&lock);
	printf("lock: %ld\n",lock);
	__atomic_dec(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_inc(&lock);
	printf("Lock: %ld\n",lock);
	__atomic_fetch_add(&lock, 5);
	printf("Lock: %ld\n",lock);
	__atomic_fetch_add(&lock, -9);
	printf("Lock: %ld\n",lock);
	return 0;
}
