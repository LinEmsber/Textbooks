/* Allocating Potentially Noncontiguous Memory */


#include <stdio.h>
#include <stdlib.h>

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

	int rows = 2;
	int cols = 5;

	int **matrix = (int **) malloc (rows * sizeof(int *) );

	int i;
	for (i = 0; i < rows; i++){
		matrix[i] = (int *) malloc (cols * sizeof(int) );
	}


	for (i = 0; i < rows; i++){
		safe_free(matrix[i]);
	}

	free(matrix);

	return 0;
}
