/* KnR C 2nd, p. 24, power function */

/* the negative number bug cannot be fixed by using (unsigned) prefix */

#include<stdio.h>

int power ( unsigned int base , int n)
{
	int i, p;
	p=1;
	for ( i=1; i<=n; ++i){
		p = p * base;
	}
	return (unsigned int ) p;
}


int main()
{
	int i;
	for ( i=0; i<10; ++i ){
		printf("%d %d %u\n", i, power(2, i), power(-3, i) );
	}
	return 0;
}
