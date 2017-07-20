#include "../include/gord.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"


int main(int argc, char **argv){
		MaxHeap *h = g_maxheap_make(16);
		g_maxheap_insert(h,3);
		g_maxheap_insert(h,5);
		g_maxheap_insert(h,2);
		g_maxheap_insert(h,1);
		long *result;
		g_maxheap_fetch(h,result);
		printf("%ld\n",result);
		g_maxheap_fetch(h,result);
		printf("%ld\n",result);
		return 0;
}
