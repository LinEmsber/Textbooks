/* 4.8, pointer arithmetic */

#include <stdio.h>
#include <stdlib.h>

int main (int argc ,char **argv)
{
	int    arr_1[] = {7, 2, 5, 3, 1, 6, -8, 16, 4};
	char   arr_2[] = {'m', 'q', 'k', 'z', '%', '>'};
	double arr_3[] = {3.14, -2.718, 6.626, 0.529};



	int    *iptr = arr_1;
	char   *cptr = arr_2;
	double *dptr = arr_3;

	// int    *iptr = &arr_1[0];
	// char   *cptr = &arr_2[0];
	// double *dptr = &arr_3[0];

	int len_1 = sizeof(arr_1) / sizeof(int);
	int len_2 = sizeof(arr_2) / sizeof(char);
	int len_3 = sizeof(arr_3) / sizeof(double);

	// byte size of types
	printf("len_1: %d, len_2: %d, len_3: %d\n", len_1, len_2, len_3);


	// origin
	printf("*iptr: %d, *cptr: %c, *dptr: %f\n", *iptr, *cptr, *dptr);

	// add 1
	iptr ++;
	cptr ++;
	dptr ++;
	printf("*iptr: %d, *cptr: %c, *dptr: %f\n", *iptr, *cptr, *dptr);

	// add 1
	iptr ++;
	cptr ++;
	dptr ++;
	printf("*iptr: %d, *cptr: %c, *dptr: %f\n", *iptr, *cptr, *dptr);

	// add 1
	iptr ++;
	cptr ++;
	dptr ++;
	printf("*iptr: %d, *cptr: %c, *dptr: %f\n", *iptr, *cptr, *dptr);

	return EXIT_SUCCESS;
}
