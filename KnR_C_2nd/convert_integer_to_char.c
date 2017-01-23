/* KnR C 2nd, p.64 , convert integer to character in str */

void itoa( int n, char str[] )
{

	int i, sign;

	// record the sign
	if ( (sign = n) < 0 )
		n = -n;

	// start the convert loop
	i=0
	do{
		str[i++] = n % 10 + '0';
	} while ( (n = n/10) > 0 );

	// the sign of character str
	if (sign < 0){
		str[i++] = '-';
	}

	// add null byte of the str
	str[i] = '\0';

	// reverse str, this reverse has avoided the last byte of char, null byte.
	reverse(str);
}
