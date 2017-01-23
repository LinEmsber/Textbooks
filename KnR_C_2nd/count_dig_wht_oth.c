/* KnR C 2nd, p.22, count digits, white space, other */

#include<stdio.h>
int main(){
	int c, i, nwhite, nother;
	int ndigit[10];

	// Initialization variable and array
	nwhite = nother = 0;
	for ( i=0; i<10; ++i ){
		ndigit[i] = 0;
	}

	while ( ( c=getchar() ) != EOF ){
		if ( c >= '0' && c <= '9' ){
			++ndigit[c-'0'];
		}else if ( c == ' ' || c == '\n' || c == '\t' ) {
			++nwhite;
		}else{
			++nother;
		}
	}

	for ( i=0; i<10; ++i){
		printf( "digits, [%d] = %d\n", i, ndigit[i] );
	}
	printf("white space = %d, other = %d\n", nwhite, nother);
}
