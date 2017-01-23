/* Concatenating strings */

char *error = "ERROR: ";
char *error_msg = "Not enough memory";

char *buffer = (char *) malloc (strlen(error) + strlne(error_msg) + 1 );

strcpy(buffer, error);
strcat(buffer, error_msg);
