#include <stdio.h>
#include "../include/gord.h"

Stack *g_make_stack(void){
	Stack *result = (Stack *)malloc(sizeof(Stack));
	result->top = NULL;
	result->size = 0;
	return result;
}

