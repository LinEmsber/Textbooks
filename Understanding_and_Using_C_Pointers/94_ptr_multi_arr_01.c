/* Pointers and multi-dim arrays */

#include <stdio.h>

int main()
{
	int i, j;			// Iteration

	int matrix[2][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10}
	};

	for (i = 0; i < 2; i++){
		for (j = 0; j < 5; j++){
			printf("matrix[%d][%d] address: %p Value: %d\n",
								i,
								j,
								&matrix[i][j],
								matrix[i][j] );
		}
	}


	printf("address matrix : %p\n", matrix);			// 100
	printf("address matrix+1: %p\n", matrix + 1);			// 120


	printf("address matrix: %d\n", sizeof(matrix[0]));		// 20

	return 0;
}
