#ifndef GORDON_H
#define GORDON_H

#define GORD_VERSION 0.1

#define NULL ((void*)0)

// Node type definitions
//
//

union Node_Data {
	int ival;
	float fval;
	long lval;
	char *sval;
	double *dval;
	long long llval;
};


typedef struct sl_node SL_Node;

typedef struct sl_node {
	int type;
	union Node_Data data;
	SL_Node *next;
} SL_Node;


typedef struct dl_node DL_Node;
typedef struct dl_node {
	int type;
	union Node_Data data;
	DL_Node *next;
	DL_Node *prev;
} DL_Node;


typedef struct bin_node Bin_Node;
typedef struct bin_node {
	int type;
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

Stack *g__stack_make(void);

int g_stack_push(Stack *st, char *type, union Node_Data data);

#endif
