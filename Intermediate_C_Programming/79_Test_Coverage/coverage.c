#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	int vx;
	for ( x = -100; x < 1000; x++ ){
		if ( (x < 0 ) && (x > 400) ){
			vx = -vx;
			printf("Change Direction\n");
		}
	}

	return EXIT_SUCCESS;
}
