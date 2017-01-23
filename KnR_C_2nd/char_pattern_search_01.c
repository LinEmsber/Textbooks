/* KnR C 2nd, p.69 , search char pattern from a string */

#include <stdio.h>
#define MAX_LINE 100

char pattern[] = "ould";

int get_line(char line[], int max)
{
	int c, i;
	i=0;
	while(--max>0 && (c=getchar()) != EOF && c != '\n')
		line[i++] = c;
	if ( c=='\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

int str_index(char src[], char searchfor[])
{
	int i, j, k;
	for (i=0; src[i] != '\0'; i++){
		for (j=i, k=0; searchfor[k] != '\0'&& src[j]==searchfor[k]; j++, k++){
		;
		}
		if ( k>0 && searchfor[k] == '\0')
			return i;
		}
	return -1;
}


int main()
{
    char line[MAX_LINE];
    int found = 0;

	while( get_line(line, MAX_LINE)>0 ){
		if( str_index(line, pattern) >= 0){
			printf("%s", line);
			found++;
		}
	}
	
    return found;
}
