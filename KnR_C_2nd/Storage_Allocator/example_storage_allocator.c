/* Storage allocator.
 *
 * References:
 * https://stackoverflow.com/questions/13159564/explain-this-implementation-of-malloc-from-the-kr-book
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <unistd.h>

/* Minimum units to request. */
#define NALLOC 1024

/* For alignment to long boundary. */
typedef long Align;
typedef union header header_t;

/* Block header
 * If this header is used as structure s, it stores the start pointer and the memory size.
 * If this header is only used as the memory block, the alignment size is data type: long.
 *
 * In the past, the size of pointer is 4 byte, and the size of size_t is also 4 byte.
 * Thus, the size of this union header is 8 byte.
 * However, in the Ubuntu 16.04 amd_64, the size of pointer becomes as 8 bytes.
 * The total size of union header consequently becomes 16 bytes.
 */
union header {
	struct{
		union header * next;
		size_t size;
	}s;
	Align x;
};

/* Function declaration. */
header_t * morecore(size_t nu);
void * knr_malloc(size_t n_bytes);
void knr_free(void * ap);

/* The empty list to get started with. */
static header_t base = {0};
/* Start of free list. */
static header_t * free_p = NULL;


/* knr_malloc: general-purpose storage allocator. */
void * knr_malloc(size_t n_bytes)
{
	header_t * curr_p, * prev_p;
	size_t n_units;
	void * result;
	bool is_allocating;

	/* Align the n_bytes as multiply of header_t, and add 1 as the header_t to store next and size. */
	n_units = (n_bytes + sizeof(header_t) - 1) / sizeof(header_t) + 1;

	/* We search the unused space from the base. If there is no free list yet exists, we have to initialize it. */
	prev_p = free_p;
	if (prev_p == NULL) {
		base.s.next = &base;
		free_p = &base;
		prev_p = &base;
		base.s.size = 0;
	}

	/* Step through the free list looking for a block of memory large enough to fit nunits units of memory into.
	 * If the whole list is traversed without finding such a block, then morecore is called to request more memory
	 * from the OS.
	 */
	is_allocating = true;
	for (curr_p = prev_p->s.next; is_allocating; prev_p = curr_p, curr_p = curr_p->s.next) {

		/* found a block of memory in free list large enough to fit nunits units of memory into. */
		if (curr_p->s.size >= n_units) {
			/* The block is exactly the right size; remove the block from the free list by pointing the
			 * previous block to the next block.
			 */
			if (curr_p->s.size == n_units){
				prev_p->s.next = curr_p->s.next;
			}
			/* The block is larger than the amount of memory asked for; allocate tail end of the block
			 * to the user.
			 */
			else {
				/* Changes the memory stored at curr_p to reflect the reduced block size. */
				curr_p->s.size -= n_units;
				/* Find location at which to create the block header for the new block. */
				curr_p += curr_p->s.size;
				/* Store the block size in the new header. */
				curr_p->s.size = n_units;
			}
			/* Set global starting position to the previous pointer. Next call to malloc will start
			 * either at the remaining part of the partitioned block, if a partition occurred.
			 */
			free_p = prev_p;

			/* Return curr_p + 1 as the next which is the really used space. */
			result = curr_p + 1;
			is_allocating = false;
		}

		/* Wrapped around the free list. None left. */
		if (curr_p == free_p){

			/* The reason that we have to assign curr_p to it again, is that there is a call to free
			 * inside of morecore that can potentially change the value of free_p.
			 */
			curr_p = morecore(n_units);
			if (curr_p == NULL){
				result = NULL;
				is_allocating = false;
			}
		}
	}

	return (void *) result;
}


/* morecore: ask system for more memory. */
header_t * morecore(size_t nu)
{
	char * current_p;
	header_t * unused_p;

	if (nu < NALLOC)
		nu = NALLOC;

	current_p = sbrk(nu * sizeof(header_t));

	/* No space at all. */
	if (current_p == (char *) -1)
		return NULL;

	unused_p = (header_t *) current_p;
	unused_p->s.size = nu;

	/* Insert block into the free list so that it is available for malloc. Note that we add 1 to the
	 * address, effectively moving to the first position after the header data, since of course we
	 * want the block header to be transparent for the user's interactions with malloc and free.
	 */
	knr_free( (void *)(unused_p + 1) );

	/* Returns the start of the free list. Thus by returning this value the calling function can
	 * immediately find the new memory by following the pointer to the next block.
	 */
	return free_p;
}

/* free: put block ap in free list. */
void knr_free(void * ap)
{
	header_t * bp, * curr_p;

	/* Fom the next point back to block header. */
	bp = (header_t *)ap - 1;

	/* Step through the free list looking for the position in the list to insert block. We have
	 * to check for the cases where either the insertion block is either to the left of every
	 * other block owned by malloc (the case that is missed), or to the right of every block
	 * owned by malloc (the case not checked for).  These last two cases are what is checked for
	 * by the condition inside of the body of the loop.
	 */
	for (curr_p = free_p; !(bp > curr_p && bp < curr_p->s.next); curr_p = curr_p->s.next){

		/* curr_p >= curr_p->s.ptr implies that the current block is the rightmost block in
		 * the free list. Then if the insertion block is to the right of that block, then it
		 * is the new rightmost block; conversely if it is to the left of the block that
		 * curr_p points to (which is the current leftmost block), then the insertion block
		 * is the new leftmost block.
		 */
		if (curr_p >= curr_p->s.next && (bp > curr_p || bp < curr_p->s.next))
			break;
	}

	/* Having found the correct location in the free list to place the insertion block. We have to
	 * (i) link it to the next block, and (ii) link the previous block to it.
	 */

	/* Join to upper nbr. */
	if (bp + bp->s.size == curr_p->s.next) {
		bp->s.size += curr_p->s.next->s.size;
		bp->s.next = curr_p->s.next->s.next;
	}
	else{
		bp->s.next = curr_p->s.next;
	}

	/* Join to lower nbr. */
	if (curr_p + curr_p->s.size == bp) {
		curr_p->s.size += bp->s.size;
		curr_p->s.next = bp->s.next;
	}
	else{
		curr_p->s.next = bp;
	}

	free_p = curr_p;
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
