/* KnR C 2nd, p.29 , print the longest input line*/

#include<stdio.h>
#define MAXLINE 100

int get_line( char line[], int maxline);
void copy(char dest[], char src[]);

int main(){
	int len, longest_len;
	char line[MAXLINE], longest[MAXLINE];

	longest_len=0;
	while ( (len=get_line(line, MAXLINE) ) > 0 ) {
		if ( len > longest_len ){
			longest_len = len;
			copy(longest, line);
		}
	}
	if ( longest_len > 0)
		printf("the context of thelongest line: %s", longest);
	return 0;
}

int get_line( char line[], int maxline){
	int c, i;
	for (i=0; i<maxline-1 && ( c=getchar() ) != EOF && c!='\n'; ++i)
		line[i] = c;
	if ( c=='\n' ){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
void copy(char dest[], char src[]){
	int i;
	i=0;
	while( (dest[i] = src[i]) != '\0' )
		++i;
}
