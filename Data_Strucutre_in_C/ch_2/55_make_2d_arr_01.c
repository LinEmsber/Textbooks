/* make a 2D array */

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)                                    \
        if ( !( (p) = malloc(s) ) ) {                   \
                fprintf(stderr, "Insufficient memory"); \
                exit(EXIT_FAILURE);                     \
        }

// create a two dimensional rows * cols array
int **make_2d_array(int rows, int cols)
{
        int i;
        int **x;

        // get memroy for row pointers
        MALLOC(x, rows * sizeof (*x) );

        // get memroy for each row
        for (i = 0; i < rows; i++){
                MALLOC(x[i], cols * sizeof (**x) );

                // set each of element to zero.
                *x[i] = 0;
        }

        return x;
}

int main()
{
        int i, j;
        int **my_arr;

        my_arr = make_2d_array(4, 6);

        // my_arr[2][3] = 5;


        for (i = 0; i < 4; i++) {
                for (j = 0; j < 6; j++) {
                        printf("%4d", my_arr[i][j]);
                }
                printf("\n");
        }

        return 0;
}
