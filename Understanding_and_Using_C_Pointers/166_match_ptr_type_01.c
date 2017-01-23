/* Always match pointer types */

#include <stdio.h>

int main()
{

	int num = 2165496;

	int *pi = &num;

	short *ps = (short *)pi;

	printf("pi: %p, value(16): %x, value(10): %d\n", pi, *pi, *pi);
	printf("pi: %p, value(16): %x, value(10): %d\n", ps, *ps, *ps);
	printf("pi: %p, value(16): %x, value(10): %d\n", ps, (unsigned short)*ps, (unsigned short)*ps);

}
