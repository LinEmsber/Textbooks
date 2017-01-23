/* transpose of a sparse matrix */

#include <stdio.h>

#define MAX_TERMS 101

// the number of columns in the original matrix never exceeds MAX_COL
#define MAX_COL 100

typedef struct _term term;

struct _term
{
        int row;
        int col;
        int value;
};

void sparse_matrix_fast_transpose(term a[], term b[])
{
        int i;
        int tmp_pos;                                       // iteration
        int row_terms[MAX_COL], starting_pos[MAX_COL];
        int num_cols = a[0].col;
        int num_terms = a[0].value;

        // the state of the b matrix
        b[0].row = num_cols;
        b[0].col = a[0].row;
        b[0].value = num_terms;

        // non zero matrix
        if(num_terms > 0){

                // initialize row_terms array, and compute it
                for ( i = 0; i < num_cols; i++ )
                        row_terms[i] = 0;
                for ( i = 1; i <= num_terms; i++ )
                        row_terms[a[i].col]++;

                // compute starting_pos array
                starting_pos[0] = 1;
                for  ( i = 1; i < num_cols; i++ )
                        starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

                // for printing out the computing result of original starting_pos
                // for( i = 0; i < num_cols; i++)
                //         printf("starting_pos[%d]: %d\n", i, starting_pos[i]);

                for  ( i = 1; i <= num_terms; i++ ){

                        // save the computing position of terms b at variable, tmp_pos.
                        // Because this starting_pos need to move to the next position, so we add 1 to starting_pos[a[i].col]
                        // At the next time, the starting_pos will start from the next postion.
                        // Example:
                        //      If i = 3, then tmp_pos = starting_pos[a[3].col]++;
                        //      tmp_pos = starting_pos[a[3].col];
                        //      but starting_pos[a[3].col] = starting_pos[a[3].col] + 1;

                        // tmp_pos = starting_pos[a[i].col]++;

                        tmp_pos = starting_pos[a[i].col];
                        starting_pos[a[i].col] = starting_pos[a[i].col] + 1;

                        // for printing out the computing result of starting_pos
                        // printf("i: %d, a[i].col: %d, starting_pos[a[i].col]++: %d\n", i, a[i].col, tmp_pos);

                        b[tmp_pos].row = a[i].col;
                        b[tmp_pos].col = a[i].row;
                        b[tmp_pos].value = a[i].value;
                }

        }
}


void print_terms(term t[])
{
        int i;
        printf("\t\trow\tcol\tvalue\n");

        for (i = 0; i <= t[0].value; i++){
                printf("\tt[%d]\t%d\t%d\t%d\n", i, t[i].row, t[i].col, t[i].value);
        }
}

int main()
{
        term a[12], b[12];

        a[0].row = 6;
        a[0].col = 6;
        a[0].value = 11;
        a[1].row = 0;
        a[1].col = 0;
        a[1].value = 15;
        a[2].row = 0;
        a[2].col = 3;
        a[2].value = 22;
        a[3].row = 0;
        a[3].col = 5;
        a[3].value = -15;
        a[4].row = 1;
        a[4].col = 1;
        a[4].value = 11;
        a[5].row = 1;
        a[5].col = 2;
        a[5].value = 3;
        a[6].row = 2;
        a[6].col = 3;
        a[6].value = -6;
        a[7].row = 4;
        a[7].col = 0;
        a[7].value = 91;
        a[8].row = 5;
        a[8].col = 2;
        a[8].value = 28;
        a[9].row = 5;
        a[9].col = 3;
        a[9].value = 53;
        a[10].row = 4;
        a[10].col = 2;
        a[10].value = 42;
        a[11].row = 1;
        a[11].col = 5;
        a[11].value = 15;

        print_terms(a);

        sparse_matrix_fast_transpose(a, b);

        print_terms(b);
}
