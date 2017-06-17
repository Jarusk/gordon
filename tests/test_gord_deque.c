#include "../include/gord.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"

void null_test(Deque *q){
	if(q->front == NULL){
		printf("Empty Queue\n");
	}else{
		printf("Queue has %llu element(s)\n",q->size);
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
	Deque *q = (Deque *)g_deque_make();

	null_test(q);
	
	Node_Data u;
	u.type = NODE_IVAL;

	u.data.ival = 5;
	g_deque_push(q,u);

	u.data.ival = 6;
	g_deque_push(q,u);

	u.data.ival = 7;
	g_deque_push(q,u);


	null_test(q);

	Node_Data result = g_deque_pop(q);
	print_node(result);

	result = g_deque_pop_front(q);
	print_node(result);

	null_test(q);

	result = g_deque_pop_front(q);
	print_node(result);

	null_test(q);


	u.data.ival = 5;
	g_deque_push_front(q,u);

	u.data.ival = 6;
	g_deque_push_front(q,u);

	u.data.ival = 7;
	g_deque_push(q,u);


	null_test(q);

	result = g_deque_pop(q);
	print_node(result);

	result = g_deque_pop_front(q);
	print_node(result);

	null_test(q);

	result = g_deque_pop_front(q);
	print_node(result);

	null_test(q);


	return 0;
}
