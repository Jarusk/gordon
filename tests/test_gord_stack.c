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

void print_node(Node_Data d){
	switch(d.type){
		case NODE_IVAL:		printf("Val: %d\n",d.data.ival);
					break;
		case NODE_LVAL:		printf("Val: %ld\n",d.data.lval);
					break;
		case NODE_LLVAL:	printf("Val: %lld\n",d.data.llval);
					break;
		case NODE_UVAL:		printf("Val: %u\n",d.data.uval);
					break;
		case NODE_ULVAL:	printf("Val: %lu\n",d.data.ulval);
					break;
		case NODE_ULLVAL:	printf("Val: %llu\n",d.data.ullval);
					break;
		case NODE_FVAL:		printf("Val: %f\n",d.data.fval);
					break;
		case NODE_DVAL:		printf("Val: %lf\n",d.data.dval);
					break;
		case NODE_SVAL:		printf("Val: %s\n",d.data.sval);
					break;
		default:		printf("Val: NULL or invalid type\n");
					break;
	}
}

int main(int argc, char **argv){
	Stack *st = (Stack *)g_stack_make();

	null_test(st);
	
	Node_Data u;
	u.type = NODE_IVAL;
	u.data.ival = 5;

	g_push(st,u);

	null_test(st);

	Node_Data result = g_pop(st);
	print_node(result);

	null_test(st);

	return 0;
}
