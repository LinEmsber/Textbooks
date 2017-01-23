/* binary search */


#include <stdio.h>

#define COMPARE(x, y)	( ( (x) < (y) ) ? -1 : ( (x) == (y) ) ? 0 : 1 )

int compare( int x, int y)
{
	if (x < y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}

// iterative method
int binary_search(int list[], int search_num, int left, int right)
{
	int mid;

	while(left <= right){
		mid = (left + right ) / 2;

		switch( COMPARE(list[mid], search_num) ){

			case -1:
				left = mid + 1;
				break;
			case 0:
				return mid;
			case 1:
				right = mid - 1;
		}
	}

	return -1;
}


int main()
{
	int i;
	int len;
	int int_arr[] = { 1, 14, 34, 66, 73, 89, 91, 100};

	// calculate integer array length
	len = sizeof(int_arr) / sizeof(int);

	// print origin array
	for( i = 0; i < len; i++){
		printf("%d  ", int_arr[i]);
	}
	printf("\n");

	printf("search_num: %d\n", binary_search(int_arr, 91, 0, len-1) );

	return 0;

}
