/* Using the realloc function to resize an array */

#include <stdio.h>
#include <stdlib.h>

char *get_line(void)
{
	int c;

	const size_t size_increment = 10;
	size_t max_len = size_increment;
	size_t len = 0;

	char *buf = (char *) malloc (size_increment);
	char *current_pos = buf;

	if (current_pos == NULL){
		return NULL;
	}

	while (1){

		// get the char
		c = fgetc(stdin);

		// next line
		if (c == '\n'){
			break;
		}

		if ( ++len >= len){

			// resize the array
			char *new_buf = realloc(buf, max_len + size_increment);

			// error handling
			if (new_buf == NULL){
				free(buf);
				return NULL;
			}

			// get the new current position
			current_pos = new_buf + (current_pos - buf);

			buf = new_buf;
		}

		*current_pos++ = c;

	// while loop
	}

	*current_pos = '\0';
	return buf;
}



int main()
{
	char * input_line = get_line();

	printf("input_line: %s\n", input_line);

	return 0;
}
