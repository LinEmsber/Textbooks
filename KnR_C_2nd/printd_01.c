/* KnR C 2nd, p. 87, print n in decimal */

#include <stdio.h>
#include <stdlib.h>


void printd(int n )
{

	// determine the minus or not
	if (n<0){
		putchar('-');
		n=-n;
	}

	if (n/10)
		printd(n/10);

	putchar(n%10+'0');
	printf("\n");
}

int main()
{

	int a=123;

	printd(a);

	return 0;
}
