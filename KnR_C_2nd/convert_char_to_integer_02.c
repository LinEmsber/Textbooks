/* KnR C 2nd, p.61 , convert char to integer version 2*/

int atoi ( char s[] )
{
	int i, n, sign;

	// Check the character is white space or not from left to right.
	// If the character is a white space skip to the next char until
	// the character is not a white space.
	for (i=0; isspace(s[i]); i++){
		;
	}

	// Check the sign of nuumber of string.
	sign = (s[i] == '-') ? -1:1;

	// Skip the sign of this string.
	if ( s[i] == '+' || s[i] == '-')
		i++;

	for ( n=0; isdigit(s[i]); i++){
		n = n * 10 + (s[i]-'0');
	}

	return n;
}
