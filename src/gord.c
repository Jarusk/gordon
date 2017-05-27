#include <stdio.h>
#include "../include/gord.h"

Stack *g_stack_make(void){
	Stack *result = (Stack *)malloc(sizeof(Stack));
	result->top = NULL;
	result->size = 0;
	return result;
}

int g_stack_push(Stack *st, char *type, union Node_Data data){
	return 0;
}
