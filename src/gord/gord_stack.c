#include "../../include/stdio.h"
#include "../../include/gord.h"
#include "../../include/stdlib.h"

Stack *g_stack_make(void){
	Stack *result = (Stack *)malloc(sizeof(Stack));
	result->top = NULL;
	result->size = 0;
	return result;
}

int g_stack_push(Stack *st, Node_Data data){
	SL_Node *new = (SL_Node *)malloc(sizeof(SL_Node));
	new->data = data;
	new->next = st->top;
	st->top = new;
	st->size++;
	return 0;
}

Node_Data g_stack_pop(Stack *st){
	if(st->size <= 0){
		Node_Data d;
		d.type = NODE_NULL;
		return d;
	}

	Node_Data d = st->top->data;
	SL_Node *tmp = st->top;
	st->top = st->top->next;
	free(tmp);
	st->size--;
	return d;
}
