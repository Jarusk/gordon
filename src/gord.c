#include <stdio.h>
#include "../include/gord.h"
#include "../include/stdlib.h"

Stack *g_stack_make(void){
	Stack *result = (Stack *)malloc(sizeof(Stack));
	result->top = NULL;
	result->size = 0;
	return result;
}

int g_stack_push(Stack *st, Node_Type type, union Node_Data data){
	SL_Node *new = (SL_Node *)malloc(sizeof(SL_Node));
	new->type = type;
	new->data = data;
	new->next = st->top;	
	st->top = new;
	st->size++;
	return 0;
}
