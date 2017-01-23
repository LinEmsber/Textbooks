/* martix production */

// A rebrust method to create a matrix, and conduct the matrix production.

#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix MATRIX;
struct _matrix
{
	int **matrix;
	int row;
	int column;
};


MATRIX *create_matrix( int rows, int columns )
{
	int i, j;
	int counter;

	// conter start from 0.
	counter = 0;

	// Dynamically create 2D array and add data to it from input stream
	int **matrix = (int**)calloc( rows, sizeof( int* ) );

	for( i = 0; i < rows; i++ ) {
		matrix[i] = (int*)calloc( columns, sizeof( int ) );

		for( j = 0; j < columns; j++ ) {
			matrix[i][j] = counter;
			counter++;
		}
	}

	// save the martix into MATRIX structure
	MATRIX *m = (MATRIX *) malloc( sizeof( MATRIX ) );
	m -> matrix = matrix;
	m -> row = rows;
	m -> column = columns;

	return m;
}

void print_matrix( MATRIX *m )
{

	int i, j;

	printf("\nThe matrices are:\n");

	for( i = 0; i < m -> row; i++ ) {
		for( j = 0; j < m -> column; j++ ) {
			printf( "%4d", (m -> matrix)[i][j] );
		}
		printf("\n");
	}
}



MATRIX *matrix_product( MATRIX *m1, MATRIX *m2 )
{

	int i, j, k;

	// Allocate memory for MATRIX structure
	MATRIX *result = (MATRIX *) malloc( sizeof( MATRIX ) );

	// Dynamically allocate 2D array and initialize its row and count
	result -> matrix = (int**) calloc( m1 -> row, sizeof( int* ) );

	for( i = 0; i < m2->column; i++ ) {
		(result -> matrix)[i] = (int*) calloc( m2 -> column, sizeof( int ) );
	}
	result -> row = m1 -> row;
	result -> column = m2 -> column;


	// production
	for( i = 0; i < m1 -> row; i++ )
		for( j = 0; j < m2 -> column; j++ )
			for( k = 0; k < m2 -> row; k++ )
				(result->matrix)[i][j] += ( m1 -> matrix )[i][k] * ( m2->matrix )[k][j];

	return result;
}

int main()
{
	MATRIX *m1;
	MATRIX *m2;
	MATRIX *m3;

	m1 = create_matrix(3, 5);
        print_matrix(m1);

	m2 = create_matrix(5, 3);
        print_matrix(m2);

	m3 = matrix_product(m1, m2);
	print_matrix(m3);

	return 0;
}
