/* string length */
int string_length(char *string)
{
	int len = 0;
	while ( *(string++) ){
		len++;
	}
	return len;
}
