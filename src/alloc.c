#include "../include/stdlib.h"

/*
 * FOR NOW: this will implement the alloc functions as seen in the K&R C 2nd
 * edition book
 */


#define NALLOC 1024 //min request size for sbrk()



// Build our headers
typedef long Align;

typedef union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
} Header;


// STATIC Content
static Header base;
static Header *freep = NULL;



// morecore requests more memory from the kernel
static Header *morecore(unsigned nu){
	char *cp, *sbrk(int);
	Header *up;

	if(nu < NALLOC){
		nu = NALLOC;
	}

	cp = sbrk(nu*sizeof(Header));

	if(cp == (char *)-1){
		return NULL;
	}

	up = (Header *)cp;
	up->s.size = nu;
	free((void *)(up+1));
	return freep;
}


// Malloc stuff
void *malloc(size_t nbytes){
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;

	if ((prevp = freep) == NULL){
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}

	for(p = prevp->s.ptr;; prevp = p, p = p->s.ptr){
		if(p->s.size >= nunits){
			if(p->s.size == nunits){
				prevp->s.ptr = p->s.ptr;
			}else{
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}

		if(p == freep){
			if((p = morecore(nunits)) == NULL){
				return NULL;
			}
		}
	}
}

// Free implementation
void free(void *ap){
	Header *bp, *p;

	bp = (Header *)ap - 1;

	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr){
		if(p >= p->s.ptr && (bp > p || bp < p->s.ptr)){
			break;
		}
	}

	if (bp + bp->s.size == p->s.ptr){
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}else{
		bp->s.ptr = p->s.ptr;
	}

	if (p + p->s.size == bp){
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}else{
		p->s.ptr = bp;
	}

	freep = p;
}
