/* Function Pointers and Strings */


// The integer constant literal 0 has different meanings depending upon the
// context in which it's used. In all cases, it is still an integer constant
// with the value 0, it is just described in different ways.
//
// If a pointer is being compared to the constant literal 0, then this is a
// check to see if the pointer is a null pointer.
//
// This 0 is then referred to as a null pointer constant. The C standard
// defines that 0 cast to the type void * is both a null pointer and a null
// pointer constant.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *string_to_lower(const char *str)
{
	char *tmp = (char *) malloc (strlen(str) );
	char *start = tmp;

	while ( *str != 0 ){
		*tmp++ = tolower(*str++);
	}

	*tmp = 0;
	return start;
}

int compare( char *s1,  char *s2)
{
	return strcmp(s1, s2);
}

int compare_ign_case( char *s1,  char *s2)
{
	char *tmp_s1 = string_to_lower(s1);
	char *tmp_s2 = string_to_lower(s2);

	int result = strcmp(tmp_s1, tmp_s2);

	free(tmp_s1);
	free(tmp_s2);
	return result;
}

typedef int (*fun_ptr_operation) ( char *,  char *);

void sort (char *array[], int size, fun_ptr_operation operation)
{
	int i;
	char *tmp;
	int swap = 1;

	while(swap){
		swap = 0;
		for(i = 0; i < size-1; i++){
			if (operation( array[i], array[i+1] ) > 0 ){
				swap = 1;

				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
			}
		}
	}
}

void display_names(char *name[], int size)
{
	int i ;
	for(i = 0; i < size; i++){
		printf("%s\t", name[i]);
	}
	printf("\n");
}


int main()
{
	char *name_1[6] = {"Ted", "Bob", "Alice", "Kkbox", "apple", "bob"};
	char *name_2[6] = {"Ted", "Bob", "Alice", "Kkbox", "apple", "bob"};

	// care about case
	sort(name_1, 6, compare);
	display_names(name_1, 6);

	// ignore about case
	sort(name_2, 6, compare_ign_case);
	display_names(name_2, 6);

	return 0;
}
