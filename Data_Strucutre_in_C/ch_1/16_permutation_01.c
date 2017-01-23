/* recursive permutation generator */

// generate all the permutations of list[start] to list[end]

#include <stdio.h>

// Doesn't work when a and b are the same object - assigns zero (0) to the object in that case
#define SWAP(a, b)	( (a) ^= (b), (b) ^= (a), (a) ^= (b) )

// checks that the addresses of a and b are different before XOR-ing
#define XORSWAP(a, b)   ( &(a) == &(b) ) ? (a) : ( (a) ^= (b), (b) ^= (a), (a) ^= (b) )

void swap_int(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap_char(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}


void perm_int( int *list, int start, int end)
{
	int i;

	if (start == end){
		for (i = 0; i <= end; i++)
			printf("%d", list[i]);
		printf(" \t");

	}else{
		for (i = start; i <= end; i++){

			// When we use SWAP(a, b) without check a and b whether are the same object, the error happen.

			// SWAP( list[start], list[i] );
			XORSWAP( list[start], list[i] );

			perm_int( list, start + 1, end );

			// SWAP( list[start], list[i] );
			XORSWAP( list[start], list[i] );
		}
	}
}

void perm_char( char *list, int start, int end)
{
	int i;

	if (start == end){
		printf("%s  ", list );

	}else{
		for (i = start; i <= end; i++){
			swap_char( (list + start), (list + i) );
			perm_char( list, start + 1, end );
			swap_char( (list + start), (list + i) );
		}
	}
}


int main()
{
	int int_arr[] = { 1, 2, 3 };
	char char_arr[] = "abcd";

	perm_int(int_arr, 0, 2);
	printf("\n");

	perm_char(char_arr, 0, 2);
	printf("\n");


	return 0;
}
