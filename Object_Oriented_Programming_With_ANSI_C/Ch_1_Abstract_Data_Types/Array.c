/* Using functions which are declared from headers: new.h, Set.h, and Object.h to implement
 * a set of an integer array. This set includes operations: add, find, drop, contains, and
 * count.
 */

#include <stdio.h>
#include <assert.h>

#include "new.h"
#include "Set.h"
#include "Object.h"

#define	HEAP_LENGTH 10

#define IS_SET 64
#define OUT_THE_HEAP 127
#define IN_THE_HEAP 255

const void * Set;
const void * Object;


static int heap [HEAP_LENGTH];


/* new.h */

/* According to the index of element to determine it is a new set or a new object.
 * If it is a new set, set its value as IS_SET, otherwise, set its value as OUT_THE_HEAP.
 */
void * new (const void * type, ...)
{
        /* This pointer used to point the first address of a heap */
	int * p;

        /* We use value of zero to mark each available elements of heap[]. */
	for (p = heap + 1; p < heap + HEAP_LENGTH; ++ p)
		if (! * p)
			break;

	assert(p < heap + HEAP_LENGTH);

        /* check the new object is a set of an heap array, or just a objet which is
         * out of the heap.
         */
	if (p == (heap + 1) ){
		* p = IS_SET;
	}else{
		* p = OUT_THE_HEAP;
	}

        /* return either the address of a set or an object. */
	return p;
}

/* Reset element's value as 0 to represent it is a available element.
 */
void delete (void * _item)
{
	int * item = _item;

	if (item){
		assert(item > heap && item < heap + HEAP_LENGTH);
		* item = 0;
	}
}


/* Set.h */


/* A set is represented in its objects: each element points to the set.
 * If an element's value is OUT_THE_HEAP, it can be added to the set, otherwise,
 * it should already in the set, because we do not permit an object to belong to
 * more than one set.
 */
void * add (void * _set, const void * _element)
{
	int * set = _set;
	const int * element =_element;

	assert(set > heap && set < heap + HEAP_LENGTH);
	assert(* set == IS_SET);
	assert(element > heap && element < heap + OUT_THE_HEAP);

        /* change the element's value to represent it is in the heap.
         * If the element is in the heap, check its status.
         */
	if (* element == OUT_THE_HEAP){
		* (int *) element = IN_THE_HEAP;
	} else{
		assert(* element == IN_THE_HEAP);
	}

	return (void *) element;
}

/* According to the element's status to check it is added in the set or not. */
void * find (const void * _set, const void * _element)
{
	const int * set = _set;
	const int * element = _element;

	assert(set > heap && set < heap + HEAP_LENGTH);
	assert(* set == IS_SET);
	assert(element > heap && element < heap + HEAP_LENGTH);
	assert(* element);

	return * element == IN_THE_HEAP ? (void *) element : 0;
}

int contains (const void * _set, const void * _element)
{
	return find(_set, _element) != 0;
}

/* Check the element is in the set and change its status to represent it
 * is out of the heap.
 */
void * drop (void * _set, const void * _element)
{
	int * element = find(_set, _element);

	if ( element )
		* element = OUT_THE_HEAP;

	return element;
}


/* Object.h */

/* Check two elements are different or not? */
int differ (const void * a, const void * b)
{
	return a != b;
}
