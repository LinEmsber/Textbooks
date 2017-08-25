/* Storage allocator. */

#include <stdlib.h>
#include <string.h>

#include <unistd.h>

/* Minimum units to request. */
#define NALLOC 1024

/* For alignment to long boundary. */
typedef long Align;
typedef union header Header;

/* Block header
 * If this header is used as structure s, it stores the start pointer and the memory size.
 * If this header is only used as the memory block, the alignment size is data type: long.
 *
 * In the past, the size of pointer is 4 byte, and the size of unsigned int is also 4 byte.
 * Thus, the size of this union header is 8 byte.
 * However, in the Ubuntu 16.04 amd_64, the size of pointer becomes as 8 bytes.
 * The total size of union header consequently becomes 16 bytes.
 */
union header {
	struct{
		union header * ptr;
		unsigned size;
	}s;
	Align x;
};

/* Function declaration. */
Header * morecore(unsigned nu);
void * knr_malloc(unsigned nbytes);
void knr_free(void * ap);

/* The empty list to get started with. */
static Header base;
/* Start of free list. */
static Header * free_p = NULL;


/* knr_malloc: general-purpose storage allocator. */
void * knr_malloc(unsigned nbytes)
{
	Header * p, * prev_p;
	unsigned nunits;

	/* Align the nbytes as multiply of Header, and add 1 as the Header to store ptr and size. */
	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

	/* No free list yet, we search the unused space from the base. */
	prev_p = free_p;
	if (prev_p == NULL) {
		base.s.ptr = free_p = prev_p = &base;
		base.s.size = 0;
	}

	/* Search from the free list or the base. p points to the first unused space. */
	for (p = prev_p->s.ptr; ; prev_p = p, p = p->s.ptr) {

		if (p->s.size >= nunits) {
			/* Exactly. */
			if (p->s.size == nunits){
				prev_p->s.ptr = p->s.ptr;
			}
			/* Allocate tail end. */
			else {
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			free_p = prev_p;

			/* Return p + 1 as the ptr which is the really used space. */
			return (void *) (p + 1);
		}

		/* Wrapped around the free list. None left. */
		if (p == free_p){
			p = morecore(nunits);
			if (p == NULL)
				return NULL;
		}
	}
}


/* morecore: ask system for more memory. */
Header * morecore(unsigned nu)
{
	char * current_p;
	Header * unused_p;

	if (nu < NALLOC)
		nu = NALLOC;

	current_p = sbrk(nu * sizeof(Header));

	/* No space at all. */
	if (current_p == (char *) -1)
		return NULL;

	unused_p = (Header *) current_p;
	unused_p->s.size = nu;

	/* The first block is used as header to record the ptr and the size. */
	knr_free( (void *)(unused_p + 1) );

	return free_p;
}

/* free: put block ap in free list. */
void knr_free(void * ap)
{
	Header * bp, * p;

	/* Fom the ptr point back to block header. */
	bp = (Header *)ap - 1;
	for (p = free_p; !(bp > p && bp < p->s.ptr); p = p->s.ptr){
		/* Freed block at start of end of arena. */
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;
	}

	/* Join to upper nbr. */
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}
	else{
		bp->s.ptr = p->s.ptr;
	}

	/* Join to lower nbr. */
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}
	else{
		p->s.ptr = bp;
	}

	free_p = p;
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
