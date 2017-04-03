/* The declarations in the headers: Set.h, new.h, and Object.h.
 * However, the really implementations are done on the Set.c or Bag.c
 */

#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main ()
{
	void * set_entry = new(Set);
	void * object_a = add(s, new(Object));
	void * object_b = add(s, new(Object));
//	void * x = add(s, new(Object));
	void * object_c = new(Object);
//	void * z = new(Object);

	if (contains(set_entry, object_a) && contains(set_entry, object_b))
		puts("ok");

//	if (contains(s, c))
//		puts("contains?");

	if (differ(object_a, add(set_entry, object_a)))
		puts("differ?");

	if (contains(set_entry, drop(set_entry, object_a)))
		puts("drop?");

//	if (contains(s, drop(s, x)))
//		puts("drop?");

//	c = add(s, c);

//	delete(drop(s, z));
	delete(drop(set_entry, object_b));
	delete(drop(set_entry, object_c));

	return 0;
}
