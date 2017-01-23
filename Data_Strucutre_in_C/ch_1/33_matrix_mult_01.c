/* matrix multiplication function */

#include <stdio.h>

#define MAX_SIZE 5

void print_matrix(int *matrix, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){

			printf("%d\t", *(matrix + (i * cols) + j) );

		}
		printf("\n");
	}
}


void mult(int *a, int *b, int *c, int rows, int cols)
{
	int i, j, k;

	for (i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){

			// c[i][j] = 0;
			*(c + (i * cols) + j) = 0;

			for( k = 0; k < MAX_SIZE; k++){

				// *c[i][j] = a[i][k] * b[k][j];
				*(c + (i * cols) + j) = *(a + (i * cols) + j) * *(b + (i * cols) + j);
			}
		}
	}
}


int main()
{
	int arr_1[2][5] = {
		{1, 3, 5, 7 ,9},
		{2, 4, 6, 8, 10}
	};

	int arr_2[2][5] = {
		{10, 30, 50, 70 ,90},
		{20, 40, 60, 80, 100}
	};

	int arr_3[2][5];

	printf("arr_1, and arr_2\n");
	print_matrix(&arr_1[0][0], 2, 5);
	print_matrix(&arr_2[0][0], 2, 5);

	mult(&arr_1[0][0], &arr_2[0][0], &arr_3[0][0], 2, 5);

	printf("mult(arr_1, arr_2)\n");
	print_matrix(&arr_3[0][0], 2, 5);
}
