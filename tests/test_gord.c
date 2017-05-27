#include "../include/gord.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"

void null_test(Stack *st){
	if(st->top == NULL){
		printf("Empty stack\n");
	}else{
		printf("Stack has %llu element(s)\n",st->size);
	}
}

int main(int argc, char **argv){
	Stack *st = (Stack *)g_stack_make();

	null_test(st);
	
	Node_Data u;
	u.type = NODE_IVAL;
	u.data.ival = 5;

	g_stack_push(st,u);

	null_test(st);

	return 0;
}
