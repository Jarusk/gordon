#include "../../include/stdio.h"
#include "../../include/gord.h"
#include "../../include/stdlib.h"

Queue *g_queue_make(void){
	Queue *result = (Queue *)malloc(sizeof(Queue));
	result->front = NULL;
	result->back = NULL;
	result->size = 0;
	return result;
}

int g_queue_push(Queue *q, Node_Data data){
	SL_Node *new = (SL_Node *)malloc(sizeof(SL_Node));
	new->data = data;
	new->next = NULL;
	
	if(q->size == 0){
		q->front = new;
		q->back = new;
	}else{
		q->back->next = new;
		q->back = new;
	}
	q->size++;
	return 0;
}

Node_Data g_queue_pop(Queue *q){
	if(q->size <= 0){
		Node_Data d;
		d.type = NODE_NULL;
		return d;
	}

	Node_Data d = q->front->data;
	SL_Node *tmp = q->front;
	q->front = q->front->next;
	free(tmp);
	q->size--;
	return d;
}
