/* KnR C 2nd, p.47, squeeze, delete all character c from the string s  */
#include <stdio.h>

void squeeze( char s[], int c ){

	int i, j;
	for (i=j=0; s[i] != '\0'; i++){
		if ( s[i] != c ){

			// s[j++] = s[i];

			// equivalent to follow:
			s[j] = s[i];
			j++;

		}
	}
	s[j] = '\0';
}

int main()
{

	int c;
	char string[12] = "hellolloooo";

	c = getchar();
	printf("c=getchar(): %d\n", c);

	printf("original string: %s\n", string);
	squeeze( string, c);
	printf("modified string: %s\n", string);

	return 0;
}
