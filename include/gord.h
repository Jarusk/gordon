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
int g_stack_push(Stack *st, Node_Data data);
Node_Data g_stack_pop(Stack *st);
void g_stack_free(Stack *st);


// Queue implementation
typedef struct Queue {
	SL_Node *front;
	SL_Node *back;
	unsigned long long size;
} Queue;

Queue *g_queue_make(void);
int g_queue_push(Queue *q, Node_Data data);
Node_Data g_queue_pop(Queue *q);
void g_queue_free(Queue *q);


// Deque implementation
typedef struct Deque {
	DL_Node *front;
	DL_Node *back;
	unsigned long long size;
} Deque;

Deque *g_deque_make(void);

int g_deque_push(Deque *q, Node_Data data);
int g_deque_push_front(Deque *q, Node_Data data);

Node_Data g_deque_pop(Deque *q);
Node_Data g_deque_pop_front(Deque *q);
void g_deque_free(Deque *q);


// BinHeap implementation

#define H_LEFT(i) (2*i + 1)
#define H_RIGHT(i) (2*i + 2)
#define H_PARENT(i) ((i - 1) / 2)

typedef struct MaxHeap {
	unsigned long size;
	unsigned long cap;
	long *elems;
} MaxHeap;

MaxHeap *g_maxheap_make(unsigned long cap);
int g_maxheap_push(MaxHeap *h, long data);
long g_maxheap_pop(MaxHeap *h);
void g_maxheap_swap(long a, long b);
void g_maxheap_heapify(MaxHeap *h, unsigned long index);
void g_maxheap_free(MaxHeap *h);


#endif
