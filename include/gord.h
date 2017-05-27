#ifndef GORDON_H
#define GORDON_H

#define GORD_VERSION 0.1

// Node type definitions
//
//
#define NODE_IVAL 0
#define NODE_LVAL 1
#define NODE_LLVAL 2
#define NODE_UVAL 3
#define NODE_ULVAL 4
#define NODE_ULLVAL 5
#define NODE_FVAL 6
#define NODE_DVAL 7
#define NODE_SVAL 8
typedef char Node_Type;

union Node_Data {
	int ival;
	long lval;
	long long llval;
	unsigned uval;
	unsigned long ulval;
	unsigned long long ullval;
	float fval;
	double dval;
	char *sval;
};


typedef struct sl_node SL_Node;

typedef struct sl_node {
	Node_Type type;
	union Node_Data data;
	SL_Node *next;
} SL_Node;


typedef struct dl_node DL_Node;
typedef struct dl_node {
	Node_Type type;
	union Node_Data data;
	DL_Node *next;
	DL_Node *prev;
} DL_Node;


typedef struct bin_node Bin_Node;
typedef struct bin_node {
	Node_Type type;
	union Node_Data data;
	Bin_Node *parent;
	Bin_Node *left;
	Bin_Node *right;
} Bin_Node;


// Stack implementation
typedef struct stack {
	SL_Node *top;
	unsigned long long size;
} Stack;

Stack *g_stack_make(void);

int g_stack_push(Stack *st, Node_Type type, union Node_Data data);

#endif
