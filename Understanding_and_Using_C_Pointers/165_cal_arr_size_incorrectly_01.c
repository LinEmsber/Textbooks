/* Calculating the array size incorrectly */

// When passing an array to a function, always pass the size of the array at the same time.
// This info will help the function avoid exceeding the bounds of the array.

#include <stdio.h>
#include <string.h>


void replace(char *buffer, char replacement, int size)
{
	int count = 0;

	while( *buffer != NULL && count < size){

		*(buffer) = replacement;
		buffer++;
		count++;
	}
}


int main()
{
	char name[8];

	strcpy(name, "Alexander");

	replace(name, '+', sizeof(name));

	printf("sizeof(name): %lu\n", sizeof(name));
	printf("%s\n", name);

	return 0;
}
