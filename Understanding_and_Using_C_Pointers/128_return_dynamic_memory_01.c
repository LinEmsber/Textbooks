/* Returning the address of Dynamically Allocated Memory */

char *blanks(int number)
{
	int i;
	char *spaces = (char *) malloc(number + 1);

	for(i = 0; i < number; i++){
		spaces[i] = ' ';
	}

	spaces[number] = '\0';
	return spaces;
}
