#include "../../include/stdio.h"
#include "../../include/gord.h"
#include "../../include/stdlib.h"


MaxHeap *g_maxheap_make(unsigned long cap) {
  MaxHeap *h = (MaxHeap *)malloc(sizeof(MaxHeap));
  h->size = 0;
  h->cap = cap;
  h->elems = (long *)malloc(cap * sizeof(long));
  return h;
}


int g_maxheap_insert(MaxHeap *h, long data) {
  if (h->size >= h->cap) {
    h->cap <<= 1;
    h->elems = (long *)realloc(h->elems, (h->cap) * sizeof(long));
  }

  h->size++;

  unsigned long i = h->size++;
  while(i > 0 && data > h->elems[H_PARENT(i)]) {
    h->elems[i] = h->elems[H_PARENT(i)];
    i = H_PARENT(i);
  }
  h->elems[i] = data;

  return 0;
}


long g_maxheap_fetch(MaxHeap *h, long *result) {
  if (h->size < 1) {
    result = NULL;
    return -1;
  }
  *result = h->elems[0];
  h->elems[0] = h->elems[--(h->size)];
  g_maxheap_heapify(h, 0);
  return 0;
}


void long_swap(long *a, long *b){
  long tmp = *a;
  *a = *b;
  *b = tmp;
}


void g_maxheap_heapify(MaxHeap *h, unsigned long index) {
  long max = (H_LEFT(index) < h->size && h->elems[H_LEFT(index)] > h->elems[index]) ? H_LEFT(index) : index;
  max = (H_RIGHT(index) < h->size && h->elems[H_RIGHT(index)] > h->elems[max]) ? H_RIGHT(index) : max;
  if (max != index) {
    long_swap(&(h->elems[index]), &(h->elems[max]));
    g_maxheap_heapify(h,max);
  }
}

void g_maxheap_free(MaxHeap *h){
  free(h->elems);
  free(h);
}
