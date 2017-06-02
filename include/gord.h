#ifndef GORDON_H
#define GORDON_H

#define GORD_VERSION 0.1

// Node type definitions
//
//
typedef enum node_type {
	NODE_IVAL,
	NODE_LVAL,
	NODE_LLVAL,
	NODE_UVAL,
	NODE_ULVAL,
	NODE_ULLVAL,
	NODE_FVAL,
	NODE_DVAL,
	NODE_SVAL,
	NODE_NULL
} Node_Type;

typedef struct node_data {
	union {
		int ival;
		long lval;
		long long llval;
		unsigned uval;
		unsigned long ulval;
		unsigned long long ullval;
		float fval;
		double dval;
		char *sval;
	} data;
	Node_Type type;
} Node_Data;


typedef struct sl_node SL_Node;

typedef struct sl_node {
	Node_Data data;
	SL_Node *next;
} SL_Node;


typedef struct dl_node DL_Node;
typedef struct dl_node {
	Node_Data data;
	DL_Node *next;
	DL_Node *prev;
} DL_Node;


typedef struct bin_node Bin_Node;
typedef struct bin_node {
	Node_Data data;
	Bin_Node *parent;
	Bin_Node *left;
	Bin_Node *right;
} Bin_Node;


// Stack implementation
typedef struct Stack {
	SL_Node *top;
	unsigned long long size;
} Stack;

Stack *g_stack_make(void);

int g_push(Stack *st, Node_Data data);

Node_Data g_pop(Stack *st);


// Queue implementation
typedef struct Queue {
	SL_Node *front;
	SL_Node *back;
	unsigned long long size;
} Queue;

Queue *g_queue_make(void);

int g_enqueue(Queue *q, Node_Data data);

Node_Data g_dequeue(Queue *q);

#endif
