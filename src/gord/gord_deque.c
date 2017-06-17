#include "../../include/stdio.h"
#include "../../include/gord.h"
#include "../../include/stdlib.h"

Deque *g_deque_make(void){
	Deque *result = (Deque *)malloc(sizeof(Deque));
	result->front = NULL;
	result->back = NULL;
	result->size = 0;
	return result;
}

int g_deque_push(Deque *q, Node_Data data){
	DL_Node *new = (DL_Node *)malloc(sizeof(DL_Node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	
	if(q->size == 0){
		q->front = new;
		q->back = new;
	}else{
		q->back->next = new;
		new->prev = q->back;
		q->back = new;
	}
	q->size++;
	return 0;
}

int g_deque_push_front(Deque *q, Node_Data data){
	DL_Node *new = (DL_Node *)malloc(sizeof(DL_Node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	
	if(q->size == 0){
		q->front = new;
		q->back = new;
	}else{
		q->front->prev = new;
		new->next = q->front;
		q->front = new;
	}
	q->size++;
	return 0;
}

Node_Data g_deque_pop(Deque *q){
	if(q->size <= 0){
		Node_Data d;
		d.type = NODE_NULL;
		return d;
	}

	Node_Data d = q->back->data;
	DL_Node *tmp = q->back;
	q->back->prev->next = NULL;
	q->back = q->back->prev;
	free(tmp);
	q->size--;
	return d;
}

Node_Data g_deque_pop_front(Deque *q){
	if(q->size <= 0){
		Node_Data d;
		d.type = NODE_NULL;
		return d;
	}

	Node_Data d = q->front->data;
	DL_Node *tmp = q->front;
	q->front->prev = NULL;
	q->front = q->front->next;
	free(tmp);
	q->size--;
	return d;
}
