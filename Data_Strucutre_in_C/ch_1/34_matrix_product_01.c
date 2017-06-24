/* matrix multiplication function */

#include <stdio.h>

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


int main()
{
	int i, j, k;

	int arr_1[2][5] = {
		{1, 3, 5, 7 ,9},
		{2, 4, 6, 8, 10}
	};

	int arr_2[5][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8},
		{9, 10}
	};

	int arr_3[2][2] = {0};

	printf("arr_1\n");
	print_matrix(&arr_1[0][0], 2, 5);

	printf("arr_2\n");
	print_matrix(&arr_2[0][0], 5, 2);

	for (i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			for( k = 0; k < 5; k++)
				arr_3[i][j] += arr_1[i][k] * arr_2[k][j];

	printf("mult(arr_1, arr_2)\n");
	print_matrix(&arr_3[0][0], 2, 2);
}
