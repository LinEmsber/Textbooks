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

	int len_1 = sizeof(arr_1) / sizeof(int);
	int len_2 = sizeof(arr_2) / sizeof(char);
	int len_3 = sizeof(arr_3) / sizeof(double);

	long int addr10 = (long int) (& arr_1[0]);
        long int addr11 = (long int) (& arr_1[1]);
        long int addr12 = (long int) (& arr_1[2]);

        printf("addr12: %ld, addr11: %ld, addr10: %ld\n", addr12, addr11, addr10);
        printf("addr12-addr11: %ld, addr11-addr10: %ld\n", addr12 - addr11, addr11 - addr10);

        long int addr20 = (long int) (& arr_2[0]);
        long int addr21 = (long int) (& arr_2[1]);
        long int addr22 = (long int) (& arr_2[2]);

        printf("addr22: %ld, addr21: %ld, addr20: %ld\n", addr22, addr21, addr20);
        printf("addr22-addr21: %ld, addr21-addr20: %ld\n", addr22 - addr21, addr21 - addr20);


        long int addr30 = (long int) (& arr_3[0]);
        long int addr31 = (long int) (& arr_3[1]);
        long int addr32 = (long int) (& arr_3[2]);

        printf("addr32: %ld, addr31: %ld, addr30: %ld\n", addr32, addr31, addr30);
        printf("addr32-addr31: %ld, addr31-addr30: %ld\n", addr32 - addr31, addr31 - addr30);

	return EXIT_SUCCESS;
}
