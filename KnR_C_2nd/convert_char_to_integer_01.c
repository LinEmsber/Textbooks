/* KnR C 2nd, p.43 , convert char to integer */

int atoi (char s[]){

	int i, integer;

	integer = 0;

	for ( i=0; s[i] => '0' && s[i] <= '9', ++i){
		integer = integer*10 + (s[i]-'0');
	}

	return integer;
}
