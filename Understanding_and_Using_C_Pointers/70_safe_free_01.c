/* A safe free function */

#include <stdio.h>
#include <stdlib.h>

// Using this function will get a warning, if you do not explicitly cast
// the pointer type to void.
void _safe_free(void **pp)
{
	if (pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}

#define safe_free(p) _safe_free( (void**) &p )

int main()
{
	int *pi;

	pi = (int*) malloc( sizeof(int) );
	*pi = 5;

	printf("before: %p\n", pi);
	safe_free(pi);

	printf("after: %p\n", pi);
	safe_free(pi);

	return 0;
}
