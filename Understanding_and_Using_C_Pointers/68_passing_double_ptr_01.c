/* Passing a pointer to pointer */

void allocate_array(int **arr, int size, int value)
{
	int i;

	*arr = (int*)malloc(size*sizeof(int));

	if(*arr != NULL){
		for(i=0; i<size; i++){
			*(*arr+i) = value;
		}
	}
}


/* using allocate_array() */

int *vector = NULL;
allocate_array(&vector, 5, 45);
