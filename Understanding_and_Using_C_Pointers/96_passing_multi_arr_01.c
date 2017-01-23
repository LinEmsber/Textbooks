/* Passing a multi-dim array */


#include <stdio.h>

// To pass the matrix array, use either:
//
// void display_2d_arr(int (*arr)[5], int rows)
void display_2d_arr(int arr[][5], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++){
		for (j = 0; j < 5; j++){
			printf("matrix[%d][%d] address: %p Value: %d\n",
								i,
								j,
								&arr[i][j],
								arr[i][j] );
		}
	}

}

void display_2d_arr_unknown_size( int *arr, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			printf("matrix[%d][%d] address: %p Value: %d\n",
								i,
								j,
								(arr + (i * cols) + j),
								*(arr + (i * cols) + j) );
		}
	}
}


int main()
{
	int matrix[2][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10}
	};

	display_2d_arr_unknown_size( &matrix[0][0], 2, 5);

	return 0;
}
