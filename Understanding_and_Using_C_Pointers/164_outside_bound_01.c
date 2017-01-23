/* Accessing memory outside the bounds of an array */

#include <stdio.h>

int main()
{
	char name_1[8] = "1234567";
	char name_2[8] = "1234567";
	char name_3[8] = "1234567";

	name_1[-2] = 'x';
	name_2[0] = 'x';
	name_3[10] = 'x';

	printf("%p\t%s\n", name_1, name_1);
	printf("%p\t%s\n", name_2, name_2);
	printf("%p\t%s\n", name_3, name_3);

	return 0;
}
