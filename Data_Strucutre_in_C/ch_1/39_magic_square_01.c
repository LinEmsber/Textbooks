/* magic suqre */


#include <stdio.h>
#include <string.h>

#define SIDE_LEN 5

int main() {

        int i, j;
        int row;
        int col;
        int next_row;
        int next_col;

        int magic[99][99];
        int n = SIDE_LEN;
        int start = (n / 2); // The middle column
        int max = n * n; // The final number

        // Initialize
        memset(magic, 0, sizeof(magic));
        // Place the number one in the middle of row 0
	magic[0][start] = 1;

	// Loop to start placing numbers in the magic square
	for (i = 2, row = 0, col = start; i < max + 1; i++) {

		// If going up one will leave the top
		if ((row - 1) < 0) {
                        // Go to the bottom row
			next_row = n - 1;
		} else {
                        // Otherwise go up one
			next_row = row - 1;
		}
		printf("In row: %d\n", row);

                // If column will leave the side
		if ((col + 1) > (n - 1)) {
                        // Wrap to first column
			next_col = 0;
			printf("Column will leave side\n");
		} else {
                        // Otherwise go over one
                        next_col = col + 1;
                }
		printf("In col: %d\n", col);

                // If that position is taken
                if (magic[next_row][next_col] > 0) {
                        // If going to row below leaves bottom
			if (row > (n - 1)) {
                                // Go back to the top
				next_row = 0;
			}else {
                                // Go to the row below
				next_row = row + 1;
                                // But stay in same column
				next_col = col;
			}
		}
		row = next_row;
		col = next_col;
		printf("About to put %d in row %d, col %d\n", i, row, col);
                // Put the current value in that position
		magic[row][col] = i;
	}

	// Now let's print the array
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", magic[i][j]);
		}
		printf("\n");
	}
	return 0;
}
