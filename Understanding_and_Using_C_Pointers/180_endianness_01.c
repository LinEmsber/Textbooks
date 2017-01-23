/* Determining the endianness of a Machine */


#include <stdio.h>

int main()
{
	int i;
	int num = 0x12345678;

	char *pc = (char *) &num;

	for (i = 0; i < 4; i++){
		printf("%p: %02x \n", pc, (unsigned char) *pc++);
	}

	return 0;
}
