/* transpose of a sparse matrix */

#define MAX_TERMS 101

typedef struct _term term;

struct _term
{
        int row;
        int col;
        int value;
};

void sparse_matrix_transpose(term a[], term b[])
{
        int i, j;               // iteration
        int n;                  // total number of elements
        int current_b;          // current position of matrix b

        n = a[0].value;

        b[0].row = a[0].col;
        b[0].col = a[0].row;
        b[0].value = n;

        // non zero matrix
        if ( n > 0 ){
                current_b = 1;

                // transpose by the col in a, 6
                for ( i = 0; i < a[0].col; i++ ){

                        // find elements from the current col, 8
                        for ( j = 1; j <= n; j++){

                                // element is in current col, add it to b
                                if ( i == a[j].col ){
                                        b[current_b].row = a[j].col;
                                        b[current_b].col = a[j].row;
                                        b[current_b].value = a[j].value;
                                        current_b++;
                                }
                        }
                }
        }
}
