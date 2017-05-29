#include "../include/stdio.h"
#include "../include/stdlib.h"

#include <sys/mman.h>

#define NELEM 1000000000

int main(int argc, char ** argv){
	int x = 0;

	int *elems = (int *)malloc(NELEM*sizeof(int));

	for(int i=0; i<NELEM; i++){
		elems[i] = i;
	}

	free(elems);
}

