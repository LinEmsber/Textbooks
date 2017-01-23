/* KnR C 2nd, p.62, reverse str */

void (char s[])
{
	int c, i, j;
	for (i=0, j=strlen(s)-1; i<j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}



/* KnR C 2nd, p.31, excise 1-19 , reverse str */

void reverse( char str[] )
{
	int i, j;
	char temp;

	// get the length of s, just like strlen().
	for (j=0; str[j] != '\0'; ++j){
	}

	// swap
	for (i=0; i < j; ++i){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		--j;
	}
}
