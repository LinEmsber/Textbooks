/* selection sort */

#include <stdio.h>


// checks that the addresses of a and b are different before XOR-ing
#define XORSWAP(a, b)   ( &(a) == &(b) ) ? (a) : ( (a) ^= (b), (b) ^= (a), (a) ^= (b) )

void selection_sort(int list[], int n)
{
	int i, j;
	int min;

	for (i = 0; i < n-1; i++){

		min = i;

		for (j = i+1; j < n; j++){
			if (list[j] < list[min])
				min = j;
		}
		XORSWAP(list[i], list[min]);
	}
}

int main()
{
	int i;
	int len;
	int int_arr[] = { 30, 14, 1, 66, 25, 100};

	// calculate integer array length
	len = sizeof(int_arr) / sizeof(int);

	// print origin array
	for( i = 0; i < len; i++){
		printf("%d  ", int_arr[i]);
	}
	printf("\n");

	selection_sort(int_arr, len);

	// print array be sorted
	for( i = 0; i < len; i++){
		printf("%d  ", int_arr[i]);
	}
	printf("\n");

	return 0;
}
