#include "../include/gord.h"

#define NULL ((void*)0)

int main(int argc, char **argv){
	Stack *st = g_stack_make();

	if(st->top == NULL){
		printf("Empty stack\n");
	}else{
		printf("Stack has %llu elements\n",st->size);
	}

	return 0;
}
