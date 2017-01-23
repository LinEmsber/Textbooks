/* Passing 3d array */

void display_3d_array(int (*arr)[2][4], int rows)
{
	int i, j, k;
	for(i = 0; i < rows; i++){
		for(j = 0; j < 2; j++){
			for(k = 0; k < 4; k++){
				printf("%d\n", arr[i][j][k]);

			}
		}
	}
}
