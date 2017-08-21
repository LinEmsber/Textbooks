#include <stdlib.h>
#include <string.h>

#include <unistd.h>

/* Minimum units to request. */
#define NALLOC 1024


/* For alignment to long boundary. */
typedef long Align;

typedef union header Header;

/* Block header */
union header {
	struct {
		// size of this block
		union header *ptr;
		// size of this block
		unsigned size;
	} s;
	// force alignment
	Align x;
};

/* Function declaration. */
void * knr_malloc(unsigned nbytes);
void knr_free(void *ap);

/* The empty list to get started with. */
static Header base;
/* Start of free list. */
static Header * freep = NULL;


/* knr_malloc: general-purpose storage allocator. */
void * knr_malloc(unsigned nbytes)
{
	Header * p, * prevp;
	Header * morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

	/* No free list yet, we initialize the list. */
	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}

	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {

		if (p->s.size >= nunits) {
			/* Exactly. */
			if (p->s.size == nunits){
				prevp->s.ptr = p->s.ptr;
			}
			/* Allocate tail end. */
			else {
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}

		/* Wrapped around free list. */
		if (p == freep){
			/* None left. */
			if ((p = morecore(nunits)) == NULL)
				return NULL;
		}
	}
}


/* morecore: ask system for more memory. */
Header * morecore(unsigned nu)
{
	char * cp;
	Header * up;

	if (nu < NALLOC)
		nu = NALLOC;

	cp = sbrk(nu * sizeof(Header));

	/* No space at all. */
	if (cp == (char *) -1)
		return NULL;

	up = (Header *) cp;
	up->s.size = nu;
	knr_free((void *)(up + 1));

	return freep;
}

/* free: put block ap in free list. */
void knr_free(void * ap)
{
	Header * bp, * p;

	/* Point to block header. */
	bp = (Header *)ap - 1;
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr){
		/* Freed block at start of end of arena. */
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;
	}

	/* Join to upper. */
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}
	else{
		bp->s.ptr = p->s.ptr;
	}

	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}
	else{
		p->s.ptr = bp;
	}

	freep = p;
}


int main()
{
	int i;

	int * p_1 = knr_malloc(sizeof(int) * 16);
	int * p_2 = knr_malloc(sizeof(int) * 8);
	int * p_3 = knr_malloc(sizeof(int) * 24);
	int * p_4 = knr_malloc(sizeof(int) * 4);

	for (i = 0; i < 24; i++){
		*(p_3 + i) = i;
	}

	knr_free(p_3);
	knr_free(p_2);
	knr_free(p_4);
	knr_free(p_1);

	p_1 = knr_malloc(sizeof(int) * 4);
	p_2 = knr_malloc(sizeof(int) * 4);
	p_3 = knr_malloc(sizeof(int) * 4);
	p_4 = knr_malloc(sizeof(int) * 40);

	knr_free(p_1);
	knr_free(p_2);
	knr_free(p_3);
	knr_free(p_4);

	return 0;
}
